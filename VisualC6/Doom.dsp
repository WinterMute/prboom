# Microsoft Developer Studio Project File - Name="Doom" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Doom - Win32 Debug OpenGL NOASM
!MESSAGE Dies ist kein g�ltiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und f�hren Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "Doom.mak".
!MESSAGE 
!MESSAGE Sie k�nnen beim Ausf�hren von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "Doom.mak" CFG="Doom - Win32 Debug OpenGL NOASM"
!MESSAGE 
!MESSAGE F�r die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "Doom - Win32 Release" (basierend auf  "Win32 (x86) Application")
!MESSAGE "Doom - Win32 Debug" (basierend auf  "Win32 (x86) Application")
!MESSAGE "Doom - Win32 Release OpenGL" (basierend auf  "Win32 (x86) Application")
!MESSAGE "Doom - Win32 Debug OpenGL" (basierend auf  "Win32 (x86) Application")
!MESSAGE "Doom - Win32 Release NOASM" (basierend auf  "Win32 (x86) Application")
!MESSAGE "Doom - Win32 Release OpenGL NOASM" (basierend auf  "Win32 (x86) Application")
!MESSAGE "Doom - Win32 Debug NOASM" (basierend auf  "Win32 (x86) Application")
!MESSAGE "Doom - Win32 Debug OpenGL NOASM" (basierend auf  "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Doom - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /WX /GX /O2 /I "../VisualC6" /I "../src" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /D "I386_ASM" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /machine:I386 /out:"Release/prboom.exe"
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /WX /Gm /GX /ZI /Od /I "../VisualC6" /I "../src" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /D "I386_ASM" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/prboom.exe" /pdbtype:sept
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseGL"
# PROP BASE Intermediate_Dir "ReleaseGL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseGL"
# PROP Intermediate_Dir "ReleaseGL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "HIGHRES" /YX /FD /c
# ADD CPP /nologo /MT /W3 /WX /GX /O2 /I "../VisualC6" /I "../src" /D "NDEBUG" /D "GL_DOOM" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /D "I386_ASM" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib sdl.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 opengl32.lib glu32.lib user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /profile /machine:I386 /out:"ReleaseGL/glboom.exe"
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugGL"
# PROP BASE Intermediate_Dir "DebugGL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugGL"
# PROP Intermediate_Dir "DebugGL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HIGHRES" /D "INSTRUMENTED" /D "RANGECHECK" /D "SIMPLECHECKS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /WX /Gm /GX /ZI /Od /I "../VisualC6" /I "../src" /D "GL_DOOM" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /D "I386_ASM" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib sdl.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /debug /machine:I386 /out:"DebugGL/glboom.exe"
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "Doom - Win32 Release NOASM"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseNOASM"
# PROP BASE Intermediate_Dir "ReleaseNOASM"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseNOASM"
# PROP Intermediate_Dir "ReleaseNOASM"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../VisualC6" /I "../src" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD CPP /nologo /MT /W3 /WX /GX /O2 /I "../VisualC6" /I "../src" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib sdl.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /machine:I386 /out:"ReleaseNOASM/prboom.exe"
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL NOASM"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseNOASMGL"
# PROP BASE Intermediate_Dir "ReleaseNOASMGL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseNOASMGL"
# PROP Intermediate_Dir "ReleaseNOASMGL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../VisualC6" /I "../src" /D "NDEBUG" /D "GL_DOOM" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD CPP /nologo /MT /W3 /WX /GX /O2 /I "../VisualC6" /I "../src" /D "NDEBUG" /D "GL_DOOM" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib sdl.lib opengl32.lib glu32.lib /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /profile /debug
# ADD LINK32 opengl32.lib glu32.lib user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /machine:I386 /out:"ReleaseNOASMGL/glboom.exe"
# SUBTRACT LINK32 /profile /debug

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug NOASM"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Doom___Win32_Debug_NOASM"
# PROP BASE Intermediate_Dir "Doom___Win32_Debug_NOASM"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugNOASM"
# PROP Intermediate_Dir "DebugNOASM"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../VisualC6" /I "../src" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INSTRUMENTED" /D "RANGECHECK" /D "SIMPLECHECKS" /D "TIMEDIAG" /D "HEAPDUMP" /D "HAVE_CONFIG_H" /D "I386_ASM" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /WX /Gm /GX /ZI /Od /I "../VisualC6" /I "../src" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/prboom.exe" /pdbtype:sept
# SUBTRACT BASE LINK32 /profile
# ADD LINK32 user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /debug /machine:I386 /out:"DebugNOASM/prboom.exe" /pdbtype:sept
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL NOASM"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Doom___Win32_Debug_OpenGL_NOASM"
# PROP BASE Intermediate_Dir "Doom___Win32_Debug_OpenGL_NOASM"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugNOASMGL"
# PROP Intermediate_Dir "DebugNOASMGL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /Gm /GX /ZI /Od /I "../VisualC6" /I "../src" /D "GL_DOOM" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INSTRUMENTED" /D "RANGECHECK" /D "SIMPLECHECKS" /D "TIMEDIAG" /D "HEAPDUMP" /D "HAVE_CONFIG_H" /D "I386_ASM" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /WX /Gm /GX /ZI /Od /I "../VisualC6" /I "../src" /D "GL_DOOM" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 opengl32.lib glu32.lib user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /debug /machine:I386 /out:"DebugGL/glboom.exe"
# SUBTRACT BASE LINK32 /profile
# ADD LINK32 opengl32.lib glu32.lib user32.lib gdi32.lib sdl.lib sdl_mixer.lib sdl_net.lib /nologo /subsystem:windows /debug /machine:I386 /out:"DebugNOASMGL/glboom.exe"
# SUBTRACT LINK32 /profile

!ENDIF 

# Begin Target

# Name "Doom - Win32 Release"
# Name "Doom - Win32 Debug"
# Name "Doom - Win32 Release OpenGL"
# Name "Doom - Win32 Debug OpenGL"
# Name "Doom - Win32 Release NOASM"
# Name "Doom - Win32 Release OpenGL NOASM"
# Name "Doom - Win32 Debug NOASM"
# Name "Doom - Win32 Debug OpenGL NOASM"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\am_map.c
# End Source File
# Begin Source File

SOURCE=..\src\am_map.h
# End Source File
# Begin Source File

SOURCE=config.h
# End Source File
# Begin Source File

SOURCE=..\src\d_client.c
# End Source File
# Begin Source File

SOURCE=..\src\d_deh.c
# End Source File
# Begin Source File

SOURCE=..\src\d_deh.h
# End Source File
# Begin Source File

SOURCE=..\src\d_englsh.h
# End Source File
# Begin Source File

SOURCE=..\src\d_event.h
# End Source File
# Begin Source File

SOURCE=..\src\d_items.c
# End Source File
# Begin Source File

SOURCE=..\src\d_items.h
# End Source File
# Begin Source File

SOURCE=..\src\d_main.c
# End Source File
# Begin Source File

SOURCE=..\src\d_main.h
# End Source File
# Begin Source File

SOURCE=..\src\d_net.h
# End Source File
# Begin Source File

SOURCE=..\src\d_player.h
# End Source File
# Begin Source File

SOURCE=..\src\d_think.h
# End Source File
# Begin Source File

SOURCE=..\src\d_ticcmd.h
# End Source File
# Begin Source File

SOURCE=..\src\doomdata.h
# End Source File
# Begin Source File

SOURCE=..\src\doomdef.c
# End Source File
# Begin Source File

SOURCE=..\src\doomdef.h
# End Source File
# Begin Source File

SOURCE=..\src\doomstat.c
# End Source File
# Begin Source File

SOURCE=..\src\doomstat.h
# End Source File
# Begin Source File

SOURCE=..\src\doomtype.h
# End Source File
# Begin Source File

SOURCE=..\src\drawasm.h
# End Source File
# Begin Source File

SOURCE=..\src\dstrings.c
# End Source File
# Begin Source File

SOURCE=..\src\dstrings.h
# End Source File
# Begin Source File

SOURCE=..\src\f_finale.c
# End Source File
# Begin Source File

SOURCE=..\src\f_finale.h
# End Source File
# Begin Source File

SOURCE=..\src\f_wipe.c

!IF  "$(CFG)" == "Doom - Win32 Release"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL NOASM"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\src\f_wipe.h

!IF  "$(CFG)" == "Doom - Win32 Release"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL NOASM"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\src\g_game.c
# End Source File
# Begin Source File

SOURCE=..\src\g_game.h
# End Source File
# Begin Source File

SOURCE=..\src\hu_lib.c
# End Source File
# Begin Source File

SOURCE=..\src\hu_lib.h
# End Source File
# Begin Source File

SOURCE=..\src\hu_stuff.c
# End Source File
# Begin Source File

SOURCE=..\src\hu_stuff.h
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_joy.c
# End Source File
# Begin Source File

SOURCE=..\src\i_joy.h
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_main.c
# End Source File
# Begin Source File

SOURCE=..\src\i_main.h
# End Source File
# Begin Source File

SOURCE=..\src\i_network.h
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_sound.c
# End Source File
# Begin Source File

SOURCE=..\src\i_sound.h
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_pngshot.c
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_pngshot.h
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_system.c
# End Source File
# Begin Source File

SOURCE=..\src\i_system.h
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_network.c
# End Source File
# Begin Source File

SOURCE=..\src\SDL\i_video.c
# End Source File
# Begin Source File

SOURCE=..\src\i_video.h
# End Source File
# Begin Source File

SOURCE=..\src\info.c
# End Source File
# Begin Source File

SOURCE=..\src\info.h
# End Source File
# Begin Source File

SOURCE=..\src\lprintf.c
# End Source File
# Begin Source File

SOURCE=..\src\lprintf.h
# End Source File
# Begin Source File

SOURCE=..\src\m_argv.c
# End Source File
# Begin Source File

SOURCE=..\src\m_argv.h
# End Source File
# Begin Source File

SOURCE=..\src\m_bbox.c
# End Source File
# Begin Source File

SOURCE=..\src\m_bbox.h
# End Source File
# Begin Source File

SOURCE=..\src\m_cheat.c
# End Source File
# Begin Source File

SOURCE=..\src\m_cheat.h
# End Source File
# Begin Source File

SOURCE=..\src\m_fixed.h
# End Source File
# Begin Source File

SOURCE=..\src\m_menu.c
# End Source File
# Begin Source File

SOURCE=..\src\m_menu.h
# End Source File
# Begin Source File

SOURCE=..\src\m_misc.c
# End Source File
# Begin Source File

SOURCE=..\src\m_misc.h
# End Source File
# Begin Source File

SOURCE=..\src\m_random.c
# End Source File
# Begin Source File

SOURCE=..\src\m_random.h
# End Source File
# Begin Source File

SOURCE=..\src\m_swap.h
# End Source File
# Begin Source File

SOURCE=..\src\md5.c
# End Source File
# Begin Source File

SOURCE=..\src\md5.h
# End Source File
# Begin Source File

SOURCE=..\src\Mmus2mid.c
# End Source File
# Begin Source File

SOURCE=..\src\Mmus2mid.h
# End Source File
# Begin Source File

SOURCE=..\src\p_ceilng.c
# End Source File
# Begin Source File

SOURCE=..\src\p_checksum.c
# End Source File
# Begin Source File

SOURCE=..\src\p_checksum.h
# End Source File
# Begin Source File

SOURCE=..\src\p_doors.c
# End Source File
# Begin Source File

SOURCE=..\src\p_enemy.c
# End Source File
# Begin Source File

SOURCE=..\src\p_enemy.h
# End Source File
# Begin Source File

SOURCE=..\src\p_floor.c
# End Source File
# Begin Source File

SOURCE=..\src\p_genlin.c
# End Source File
# Begin Source File

SOURCE=..\src\p_inter.c
# End Source File
# Begin Source File

SOURCE=..\src\p_inter.h
# End Source File
# Begin Source File

SOURCE=..\src\p_lights.c
# End Source File
# Begin Source File

SOURCE=..\src\p_map.c
# End Source File
# Begin Source File

SOURCE=..\src\p_map.h
# End Source File
# Begin Source File

SOURCE=..\src\p_maputl.c
# End Source File
# Begin Source File

SOURCE=..\src\p_maputl.h
# End Source File
# Begin Source File

SOURCE=..\src\p_mobj.c
# End Source File
# Begin Source File

SOURCE=..\src\p_mobj.h
# End Source File
# Begin Source File

SOURCE=..\src\p_plats.c
# End Source File
# Begin Source File

SOURCE=..\src\p_pspr.c
# End Source File
# Begin Source File

SOURCE=..\src\p_pspr.h
# End Source File
# Begin Source File

SOURCE=..\src\p_saveg.c
# End Source File
# Begin Source File

SOURCE=..\src\p_saveg.h
# End Source File
# Begin Source File

SOURCE=..\src\p_setup.c
# End Source File
# Begin Source File

SOURCE=..\src\p_setup.h
# End Source File
# Begin Source File

SOURCE=..\src\p_sight.c
# End Source File
# Begin Source File

SOURCE=..\src\p_spec.c
# End Source File
# Begin Source File

SOURCE=..\src\p_spec.h
# End Source File
# Begin Source File

SOURCE=..\src\p_switch.c
# End Source File
# Begin Source File

SOURCE=..\src\p_telept.c
# End Source File
# Begin Source File

SOURCE=..\src\p_tick.c
# End Source File
# Begin Source File

SOURCE=..\src\p_tick.h
# End Source File
# Begin Source File

SOURCE=..\src\p_user.c
# End Source File
# Begin Source File

SOURCE=..\src\p_user.h
# End Source File
# Begin Source File

SOURCE=..\src\protocol.h
# End Source File
# Begin Source File

SOURCE=..\src\r_bsp.c
# End Source File
# Begin Source File

SOURCE=..\src\r_bsp.h
# End Source File
# Begin Source File

SOURCE=..\src\r_data.c
# End Source File
# Begin Source File

SOURCE=..\src\r_data.h
# End Source File
# Begin Source File

SOURCE=..\src\r_defs.h
# End Source File
# Begin Source File

SOURCE=..\src\r_demo.c
# End Source File
# Begin Source File

SOURCE=..\src\r_demo.h
# End Source File
# Begin Source File

SOURCE=..\src\r_draw.c
# End Source File
# Begin Source File

SOURCE=..\src\r_draw.h
# End Source File
# Begin Source File

SOURCE=..\src\r_drawcolumn.inl
# End Source File
# Begin Source File

SOURCE=..\src\r_drawspan.inl
# End Source File
# Begin Source File

SOURCE=..\src\r_filter.c
# End Source File
# Begin Source File

SOURCE=..\src\r_filter.h
# End Source File
# Begin Source File

SOURCE=..\src\r_fps.c
# End Source File
# Begin Source File

SOURCE=..\src\r_fps.h
# End Source File
# Begin Source File

SOURCE=..\src\r_main.c
# End Source File
# Begin Source File

SOURCE=..\src\r_main.h
# End Source File
# Begin Source File

SOURCE=..\src\r_patch.c
# End Source File
# Begin Source File

SOURCE=..\src\r_patch.h
# End Source File
# Begin Source File

SOURCE=..\src\r_plane.c
# End Source File
# Begin Source File

SOURCE=..\src\r_plane.h
# End Source File
# Begin Source File

SOURCE=..\src\r_segs.c
# End Source File
# Begin Source File

SOURCE=..\src\r_segs.h
# End Source File
# Begin Source File

SOURCE=..\src\r_sky.c
# End Source File
# Begin Source File

SOURCE=..\src\r_sky.h
# End Source File
# Begin Source File

SOURCE=..\src\r_state.h
# End Source File
# Begin Source File

SOURCE=..\src\r_things.c
# End Source File
# Begin Source File

SOURCE=..\src\r_things.h
# End Source File
# Begin Source File

SOURCE=..\src\s_sound.c
# End Source File
# Begin Source File

SOURCE=..\src\s_sound.h
# End Source File
# Begin Source File

SOURCE=..\src\sounds.c
# End Source File
# Begin Source File

SOURCE=..\src\sounds.h
# End Source File
# Begin Source File

SOURCE=..\src\st_lib.c
# End Source File
# Begin Source File

SOURCE=..\src\st_lib.h
# End Source File
# Begin Source File

SOURCE=..\src\st_stuff.c
# End Source File
# Begin Source File

SOURCE=..\src\st_stuff.h
# End Source File
# Begin Source File

SOURCE=..\src\tables.c
# End Source File
# Begin Source File

SOURCE=..\src\tables.h
# End Source File
# Begin Source File

SOURCE=..\src\v_video.c
# End Source File
# Begin Source File

SOURCE=..\src\v_video.h
# End Source File
# Begin Source File

SOURCE=..\src\version.c
# End Source File
# Begin Source File

SOURCE=..\src\version.h
# End Source File
# Begin Source File

SOURCE=..\src\w_mmap.c
# End Source File
# Begin Source File

SOURCE=..\src\w_wad.c
# End Source File
# Begin Source File

SOURCE=..\src\w_wad.h
# End Source File
# Begin Source File

SOURCE=..\src\wi_stuff.c
# End Source File
# Begin Source File

SOURCE=..\src\wi_stuff.h
# End Source File
# Begin Source File

SOURCE=..\src\z_bmalloc.c
# End Source File
# Begin Source File

SOURCE=..\src\z_bmalloc.h
# End Source File
# Begin Source File

SOURCE=..\src\z_zone.c
# End Source File
# Begin Source File

SOURCE=..\src\z_zone.h
# End Source File
# End Group
# Begin Group "OpenGL Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\gl_intern.h

!IF  "$(CFG)" == "Doom - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL NOASM"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\src\gl_main.c

!IF  "$(CFG)" == "Doom - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL NOASM"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\src\gl_struct.h

!IF  "$(CFG)" == "Doom - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL NOASM"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\src\gl_texture.c

!IF  "$(CFG)" == "Doom - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL"

!ELSEIF  "$(CFG)" == "Doom - Win32 Release NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Release OpenGL NOASM"

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug NOASM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Doom - Win32 Debug OpenGL NOASM"

!ENDIF 

# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Icons\barrel.ico
# End Source File
# Begin Source File

SOURCE=..\Icons\fouch.ico
# End Source File
# Begin Source File

SOURCE=..\Icons\god.ico
# End Source File
# Begin Source File

SOURCE=..\Icons\heada1.ico
# End Source File
# Begin Source File

SOURCE=..\Icons\icons.rc
# End Source File
# Begin Source File

SOURCE=..\Icons\resource.h
# End Source File
# Begin Source File

SOURCE=..\Icons\skull.ico
# End Source File
# End Group
# Begin Source File

SOURCE=..\src\SDL\SDL_win32_main.c
# End Source File
# End Target
# End Project
