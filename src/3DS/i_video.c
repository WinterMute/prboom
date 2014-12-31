/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2006 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  DOOM graphics stuff for SDL
 *
 *-----------------------------------------------------------------------------
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <stdint.h>

typedef  uint8_t Uint8;

#include <3ds/types.h>
#include <3ds/gfx.h>
#include <3ds/services/hid.h>

#include "m_argv.h"
#include "doomstat.h"
#include "doomdef.h"
#include "doomtype.h"
#include "v_video.h"
#include "r_draw.h"
#include "d_main.h"
#include "d_event.h"
#include "i_joy.h"
#include "i_video.h"
#include "z_zone.h"
#include "s_sound.h"
#include "sounds.h"
#include "w_wad.h"
#include "st_stuff.h"
#include "lprintf.h"
#include "i_pngshot.h"

int gl_colorbuffer_bits=16;
int gl_depthbuffer_bits=16;

extern void M_QuitDOOM(int choice);
#ifdef DISABLE_DOUBLEBUFFER
int use_doublebuffer = 0;
#else
int use_doublebuffer = 1; // Included not to break m_misc, but not relevant to SDL
#endif
int use_fullscreen;
int desired_fullscreen;

////////////////////////////////////////////////////////////////////////////
// Input code
int             leds_always_off = 0; // Expected by m_misc, not relevant

// Mouse handling
extern int     usemouse;        // config file var
static boolean mouse_enabled; // usemouse, but can be overriden by -nomouse
static boolean mouse_currently_grabbed;

/////////////////////////////////////////////////////////////////////////////////
// Main input code


//
// I_StartTic
//
struct eventTranslate {
  u32 buttonMask;
  u32 doomKey;
};

struct eventTranslate gameKeyTable[] = {
  { KEY_UP     , KEYD_UPARROW    },
  { KEY_DOWN   , KEYD_DOWNARROW  },
  { KEY_LEFT   , KEYD_LEFTARROW  },
  { KEY_RIGHT  , KEYD_RIGHTARROW },
  { KEY_START  , KEYD_ESCAPE     },
  { KEY_SELECT , KEYD_ENTER      },
  { KEY_A      , KEYD_RCTRL      },
  { KEY_B      , KEYD_SPACEBAR   },
  { KEY_L      , ','             },
  { KEY_R      , '.'             },
  { KEY_X      , KEYD_RSHIFT     }
};

int numGameKeys = sizeof(gameKeyTable) / sizeof(gameKeyTable[0]);

struct eventTranslate menuKeyTable[] = {
  { KEY_UP     , KEYD_UPARROW    },
  { KEY_DOWN   , KEYD_DOWNARROW  },
  { KEY_LEFT   , KEYD_LEFTARROW  },
  { KEY_RIGHT  , KEYD_RIGHTARROW },
  { KEY_START  , KEYD_ESCAPE     },
  { KEY_SELECT , KEYD_ENTER      },
  { KEY_A      , KEYD_ENTER      },
  { KEY_B      , KEYD_BACKSPACE  },
  { KEY_L      , ','             },
  { KEY_R      , '.'             },
  { KEY_X      , KEYD_RSHIFT     },
  { KEY_Y      , 'y'             }
};

int numMenuKeys = sizeof(menuKeyTable) / sizeof(menuKeyTable[0]);

void translateKeys(evtype_t type, u32 mask, struct eventTranslate *table, int count)
{
  int i;

  event_t event;
  event.type = type;

  for( i=0; i<count; i++)
  {
    if(mask & table[i].buttonMask)
    {
      event.data1 = table[i].doomKey;
      D_PostEvent(&event);
    }
  }
}

void I_StartTic (void)
{
  u32 kDown, kUp;

  struct eventTranslate *translateTable = gameKeyTable;
  int numTranslations = numGameKeys;

  if (menuactive)
  {
    translateTable = menuKeyTable;
    numTranslations = numMenuKeys;
  }

  hidScanInput();

  kDown = hidKeysDown();

  translateKeys(ev_keydown, kDown, translateTable, numTranslations);

  kUp   = hidKeysUp();

  translateKeys(ev_keyup, kUp, gameKeyTable, numGameKeys);




}

//
// I_StartFrame
//
void I_StartFrame (void)
{
}

//
// I_InitInputs
//

static void I_InitInputs(void)
{
  int nomouse_parm = M_CheckParm("-nomouse");

  // check if the user wants to use the mouse
  mouse_enabled = usemouse && !nomouse_parm;

}

///////////////////////////////////////////////////////////
// Palette stuff.
//
static u32* palettes;
static u32 currentPalette;

static void I_UploadNewPalette(int pal)
{
  // This is used to replace the current 256 colour cmap with a new one
  // Used by 256 colour PseudoColor modes

  static int cachedgamma;
  static size_t num_pals;

  if (V_GetMode() == VID_MODEGL)
    return;

  if ((palettes == NULL) || (cachedgamma != usegamma)) {
    int pplump = W_GetNumForName("PLAYPAL");
    int gtlump = (W_CheckNumForName)("GAMMATBL",ns_prboom);
    register const byte * palette = W_CacheLumpNum(pplump);
    register const byte * const gtable = (const byte *)W_CacheLumpNum(gtlump) + 256*(cachedgamma = usegamma);
    register int i;

    num_pals = W_LumpLength(pplump) / (3*256);
    num_pals *= 256;

    if (!palettes) {
      // First call - allocate and prepare colour array
      palettes = malloc(sizeof(*palettes)*num_pals);
    }

    // set the colormap entries
    for (i=0 ; (size_t)i<num_pals ; i++) {
      palettes[i] = (gtable[palette[0]] << 24) + (gtable[palette[1]] << 16) + (gtable[palette[2]] << 8) + 0xff;
      palette += 3;
    }

    W_UnlockLumpNum(pplump);
    W_UnlockLumpNum(gtlump);
    num_pals/=256;
  }

#ifdef RANGECHECK
  if ((size_t)pal >= num_pals)
    I_Error("I_UploadNewPalette: Palette number out of range (%d>=%d)",
      pal, num_pals);
#endif

  // store the colors to the current display
  currentPalette = 256 * pal;
}

//////////////////////////////////////////////////////////////////////////////
// Graphics API

void I_ShutdownGraphics(void)
{
}

//
// I_UpdateNoBlit
//
void I_UpdateNoBlit (void)
{
}

//
// I_FinishUpdate
//
static int newpal = 0;
#define NO_PALETTE_CHANGE 1000

void I_FinishUpdate (void)
{
  /* Update the display buffer (flipping video pages if supported)
   * If we need to change palette, that implicitely does a flip */
  if (newpal != NO_PALETTE_CHANGE) {
    I_UploadNewPalette(newpal);
    newpal = NO_PALETTE_CHANGE;
  }
  //dest=screen->pixels;
  int height=screens[0].height;
  int width=screens[0].width;

  u32* bufAdr=(u32*)gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
  int w, h;

  for (w=0; w<width; w++)
  {
    u32 *dest=&bufAdr[240*w + 239];
    u8 *src=screens[0].data + w;

    for (h=0; h<height; h++)
    {
        *(dest--)=palettes[(*src) + currentPalette];
        src += screens[0].byte_pitch;
    }

  }
  gfxSwapBuffers();
  gfxFlushBuffers();
  gspWaitForVBlank();

}

//
// I_ScreenShot
//

#ifdef HAVE_LIBPNG
#define SAVE_PNG_OR_BMP I_SavePNG
#else
#define SAVE_PNG_OR_BMP SDL_SaveBMP
#endif

int I_ScreenShot (const char *fname)
{
//  return SAVE_PNG_OR_BMP(SDL_GetVideoSurface(), fname);
	return 0;
}

//
// I_SetPalette
//
void I_SetPalette (int pal)
{
  newpal = pal;
}

// I_PreInitGraphics

static void I_ShutdownSDL(void)
{
}

void I_PreInitGraphics(void)
{
}

// e6y
// GLBoom use this function for trying to set the closest supported resolution if the requested mode can't be set correctly.
// For example glboom.exe -geom 1025x768 -nowindow will set 1024x768.
// It should be used only for fullscreen modes.
static void I_ClosestResolution (int *width, int *height, int flags)
{
}

// CPhipps -
// I_CalculateRes
// Calculates the screen resolution, possibly using the supplied guide
void I_CalculateRes(unsigned int width, unsigned int height)
{
  // e6y: how about 1680x1050?
  /*
  SCREENWIDTH = (width+3) & ~3;
  SCREENHEIGHT = (height+3) & ~3;
  */

    SCREENWIDTH = width;
    SCREENHEIGHT = height;
    SCREENPITCH = (width * V_GetPixelDepth() + 3) & ~3;
    if (!(SCREENPITCH % 1024))
      SCREENPITCH += 32;

}

// CPhipps -
// I_SetRes
// Sets the screen resolution
void I_SetRes(void)
{
  int i;

  I_CalculateRes(SCREENWIDTH, SCREENHEIGHT);

  // set first three to standard values
  for (i=0; i<3; i++) {
    screens[i].width = SCREENWIDTH;
    screens[i].height = SCREENHEIGHT;
    screens[i].byte_pitch = SCREENPITCH;
    screens[i].short_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE16);
    screens[i].int_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE32);
  }

  // statusbar
  screens[4].width = SCREENWIDTH;
  screens[4].height = (ST_SCALED_HEIGHT+1);
  screens[4].byte_pitch = SCREENPITCH;
  screens[4].short_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE16);
  screens[4].int_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE32);

  lprintf(LO_INFO,"I_SetRes: Using resolution %dx%d\n", SCREENWIDTH, SCREENHEIGHT);
}

void I_InitGraphics(void)
{
  char titlebuffer[2048];
  static int    firsttime=1;

  if (firsttime)
  {
    firsttime = 0;

	SCREENWIDTH = 400;
	SCREENHEIGHT = 240;
	SCREENPITCH = 400;

    atexit(I_ShutdownGraphics);
    lprintf(LO_INFO, "I_InitGraphics: %dx%d\n", SCREENWIDTH, SCREENHEIGHT);

    /* Set the video mode */
    I_UpdateVideoMode();

    /* Setup the window title */
    snprintf(titlebuffer,sizeof(titlebuffer),"%s %s", PACKAGE, VERSION);

    /* Initialize the input system */
    I_InitInputs();
  }
}

int I_GetModeFromString(const char *modestr)
{
  return VID_MODE8;
}

void I_UpdateVideoMode(void)
{
  int init_flags;
  int i;
  video_mode_t mode;

  lprintf(LO_INFO, "I_UpdateVideoMode: %dx%d (%s)\n", SCREENWIDTH, SCREENHEIGHT, desired_fullscreen ? "fullscreen" : "nofullscreen");

  mode = I_GetModeFromString(default_videomode);
  if ((i=M_CheckParm("-vidmode")) && i<myargc-1) {
    mode = I_GetModeFromString(myargv[i+1]);
  }

  V_InitMode(mode);
  V_DestroyUnusedTrueColorPalettes();
  V_FreeScreens();

  I_SetRes();

  screens[0].not_on_heap = false;
  screens[0].width = 400;
  screens[0].height = 240;
  screens[0].byte_pitch = 400;
  screens[0].short_pitch = 200;
  screens[0].int_pitch = 100;

  V_AllocScreens();
  R_InitBuffer(SCREENWIDTH, SCREENHEIGHT);
}
