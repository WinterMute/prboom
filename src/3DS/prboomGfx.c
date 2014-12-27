#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <3ds/types.h>
#include <3ds/gfx.h>
#include <3ds/svc.h>
#include <3ds/linear.h>

extern u8* gfxSharedMemory;
extern u8* gfxTopLeftFramebuffers[2];
extern u8* gfxTopRightFramebuffers[2];
extern u8* gfxBottomFramebuffers[2];
extern u8 gfxThreadID;
extern Handle gspEvent;
extern Handle gspSharedMemHandle;
void gfxSetFramebufferInfo(gfxScreen_t screen, u8 id);

void prboomGfxInit()
{
	gspInit();

	gfxSharedMemory=(u8*)0x10002000;

	GSPGPU_AcquireRight(NULL, 0x0);

	//setup our gsp shared mem section
	svcCreateEvent(&gspEvent, 0x0);
	GSPGPU_RegisterInterruptRelayQueue(NULL, gspEvent, 0x1, &gspSharedMemHandle, &gfxThreadID);
	svcMapMemoryBlock(gspSharedMemHandle, (u32)gfxSharedMemory, 0x3, 0x10000000);

	// default gspHeap configuration :
	//		topleft1  0x00000000-0x00046500
	//		topleft2  0x00046500-0x0008CA00
	//		bottom1   0x0008CA00-0x000C4E00
	//		bottom2   0x000C4E00-0x000FD200
	//	 if 3d enabled :
	//		topright1 0x000FD200-0x00143700
	//		topright2 0x00143700-0x00189C00

	gfxTopLeftFramebuffers[0]=linearAlloc(400*240*4);
	gfxTopLeftFramebuffers[1]=linearAlloc(400*240*4);
	gfxBottomFramebuffers[0]=linearAlloc(320*240*2);

	//initialize framebuffer info structures
	gfxSetFramebufferInfo(GFX_TOP, 0);
	gfxSetFramebufferInfo(GFX_BOTTOM, 0);

	//GSP shared mem : 0x2779F000
	gxCmdBuf=(u32*)(gfxSharedMemory+0x800+gfxThreadID*0x200);

	// Initialize event handler and wait for VBlank
	gspInitEventHandler(gspEvent, (vu8*)gfxSharedMemory, gfxThreadID);
	gspWaitForVBlank();

	GSPGPU_SetLcdForceBlack(NULL, 0x0);
}

void prboomGfxExit()
{
	// Exit event handler
	gspExitEventHandler();

	// Free framebuffers
	linearFree(gfxBottomFramebuffers[0]);
	linearFree(gfxTopLeftFramebuffers[1]);
	linearFree(gfxTopLeftFramebuffers[0]);

	//unmap GSP shared mem
	svcUnmapMemoryBlock(gspSharedMemHandle, 0x10002000);

	GSPGPU_UnregisterInterruptRelayQueue(NULL);

	svcCloseHandle(gspSharedMemHandle);
	svcCloseHandle(gspEvent);

	GSPGPU_ReleaseRight(NULL);

	gspExit();
}
