/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
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
 *  Misc system stuff needed by Doom, implemented for Linux.
 *  Mainly timer handling, and ENDOOM/ENDBOOM.
 *
 *-----------------------------------------------------------------------------
 */

#include <stdio.h>

#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#ifdef _MSC_VER
#define    F_OK    0    /* Check for file existence */
#define    W_OK    2    /* Check for write permission */
#define    R_OK    4    /* Check for read permission */
#include <io.h>
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <sys/stat.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "SDL.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SCHED_H
#include <sched.h>
#endif
#ifdef _MSC_VER
#include <io.h>
#endif
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#ifndef PRBOOM_SERVER
#include "m_argv.h"
#endif
#include "lprintf.h"
#include "doomtype.h"
#include "doomdef.h"
#include "lprintf.h"
#ifndef PRBOOM_SERVER
#include "m_fixed.h"
#include "r_fps.h"
#endif
#include "i_system.h"

#ifdef __GNUG__
#pragma implementation "i_system.h"
#endif
#include "i_system.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

static unsigned int start_displaytime;
static unsigned int displaytime;
static boolean InDisplay = false;

boolean I_StartDisplay(void)
{
  if (InDisplay)
    return false;

  start_displaytime = SDL_GetTicks();
  InDisplay = true;
  return true;
}

void I_EndDisplay(void)
{
  displaytime = SDL_GetTicks() - start_displaytime;
  InDisplay = false;
}

void I_uSleep(unsigned long usecs)
{
    SDL_Delay(usecs/1000);
}

int ms_to_next_tick;

int I_GetTime_RealTime (void)
{
  int t = SDL_GetTicks();
  int i = t*(TICRATE/5)/200;
  ms_to_next_tick = (i+1)*200/(TICRATE/5) - t;
  if (ms_to_next_tick > 1000/TICRATE || ms_to_next_tick<1) ms_to_next_tick = 1;
  return i;
}

#ifndef PRBOOM_SERVER
fixed_t I_GetTimeFrac (void)
{
  unsigned long now;
  fixed_t frac;

  now = SDL_GetTicks();

  if (tic_vars.step == 0)
    return FRACUNIT;
  else
  {
    frac = (fixed_t)((now - tic_vars.start + displaytime) * FRACUNIT / tic_vars.step);
    if (frac < 0)
      frac = 0;
    if (frac > FRACUNIT)
      frac = FRACUNIT;
    return frac;
  }
}

void I_GetTime_SaveMS(void)
{
  if (!movement_smooth)
    return;

  tic_vars.start = SDL_GetTicks();
  tic_vars.next = (unsigned int) ((tic_vars.start * tic_vars.msec + 1.0f) / tic_vars.msec);
  tic_vars.step = tic_vars.next - tic_vars.start;
}
#endif

/*
 * I_GetRandomTimeSeed
 *
 * CPhipps - extracted from G_ReloadDefaults because it is O/S based
 */
unsigned long I_GetRandomTimeSeed(void)
{
/* This isnt very random */
  return(SDL_GetTicks());
}

/* cphipps - I_GetVersionString
 * Returns a version string in the given buffer
 */
const char* I_GetVersionString(char* buf, size_t sz)
{
  doom_snprintf(buf,sz,"%s v%s (http://prboom.sourceforge.net/)",PACKAGE,VERSION);
  return buf;
}

/* cphipps - I_SigString
 * Returns a string describing a signal number
 */
const char* I_SigString(char* buf, size_t sz, int signum)
{
#if HAVE_DECL_SYS_SIGLIST // NSM: automake defines this symbol as 0 or 1
  if (strlen(sys_siglist[signum]) < sz)
    strcpy(buf,sys_siglist[signum]);
  else
#endif
    doom_snprintf(buf,sz,"signal %d",signum);
  return buf;
}


/* 
 * I_Read
 *
 * cph 2001/11/18 - wrapper for read(2) which handles partial reads and aborts
 * on error.
 */
void I_Read(int fd, void* vbuf, size_t sz)
{
  unsigned char* buf = vbuf;

  while (sz) {
    int rc = read(fd,buf,sz);
    if (rc <= 0) {
      I_Error("I_Read: read failed: %s", rc ? strerror(errno) : "EOF");
    }
    sz -= rc; buf += rc;
  }
}

/*
 * I_Filelength
 *
 * Return length of an open file.
 */

int I_Filelength(int handle)
{
  struct stat   fileinfo;
  if (fstat(handle,&fileinfo) == -1)
    I_Error("I_Filelength: %s",strerror(errno));
  return fileinfo.st_size;
}

#ifndef PRBOOM_SERVER

// Return the path where the executable lies -- Lee Killough
// proff_fs 2002-07-04 - moved to i_system
#ifdef _WIN32
const char *I_DoomExeDir(void)
{
  static const char current_dir_dummy[] = {"."}; // proff - rem extra slash 8/21/03
  static char *base;
  if (!base)        // cache multiple requests
    {
      size_t len = strlen(*myargv);
      char *p = (base = malloc(len+1)) + len - 1;
      strcpy(base,*myargv);
      while (p > base && *p!='/' && *p!='\\')
        *p--=0;
      if (*p=='/' || *p=='\\')
        *p--=0;
      if (strlen(base)<2)
      {
        free(base);
        base = malloc(1024);
        if (!getcwd(base,1024))
          strcpy(base, current_dir_dummy);
      }
    }
  return base;
}

#elif defined(AMIGA)

const char *I_DoomExeDir(void)
{
  return "PROGDIR:";
}

#elif defined(MACOSX)

/* Defined elsewhere */

#else
// cph - V.Aguilar (5/30/99) suggested return ~/.lxdoom/, creating
//  if non-existant
static const char prboom_dir[] = {"/.prboom"}; // Mead rem extra slash 8/21/03

const char *I_DoomExeDir(void)
{
  static char *base;
  if (!base)        // cache multiple requests
    {
      char *home = getenv("HOME");
      size_t len = strlen(home);

      base = malloc(len + strlen(prboom_dir) + 1);
      strcpy(base, home);
      // I've had trouble with trailing slashes before...
      if (base[len-1] == '/') base[len-1] = 0;
      strcat(base, prboom_dir);
      mkdir(base, S_IRUSR | S_IWUSR | S_IXUSR); // Make sure it exists
    }
  return base;
}
#endif

/*
 * HasTrailingSlash
 *
 * cphipps - simple test for trailing slash on dir names
 */

boolean HasTrailingSlash(const char* dn)
{
  return ( (dn[strlen(dn)-1] == '/')
#if defined(AMIGA)
        || (dn[strlen(dn)-1] == ':')
#endif
          );
}

/*
 * I_FindFile
 *
 * proff_fs 2002-07-04 - moved to i_system
 *
 * cphipps 19/1999 - writen to unify the logic in FindIWADFile and the WAD
 *      autoloading code.
 * Searches the standard dirs for a named WAD file
 * The dirs are listed at the start of the function
 */

#ifndef MACOSX /* OSX defines its search paths elsewhere. */
char* I_FindFile(const char* wfname, const char* ext)
{
  // lookup table of directories to search
  static const struct {
    const char *dir; // directory
    const char *sub; // subdirectory
    const char *env; // environment variable
    const char *(*func)(void); // for I_DoomExeDir
  } search[] = {
    {NULL}, // current working directory
    {NULL, NULL, "DOOMWADDIR"}, // run-time $DOOMWADDIR
    {DOOMWADDIR}, // build-time configured DOOMWADDIR
    {NULL, "doom", "HOME"}, // ~/doom
    {NULL, NULL, "HOME"}, // ~
    {NULL, NULL, NULL, I_DoomExeDir}, // config directory
    {"/usr/local/share/games/doom"},
    {"/usr/share/games/doom"},
    {"/usr/local/share/doom"},
    {"/usr/share/doom"},
  };

  int   i;
  /* Precalculate a length we will need in the loop */
  size_t  pl = strlen(wfname) + strlen(ext) + 4;

  for (i = 0; i < sizeof(search)/sizeof(*search); i++) {
    char  * p;
    const char  * d = NULL;
    const char  * s = NULL;
    /* Each entry in the switch sets d to the directory to look in,
     * and optionally s to a subdirectory of d */
    // switch replaced with lookup table
    if (search[i].env) {
      if (!(d = getenv(search[i].env)))
        continue;
    } else if (search[i].func)
      d = search[i].func();
    else
      d = search[i].dir;
    s = search[i].sub;

    p = malloc((d ? strlen(d) : 0) + (s ? strlen(s) : 0) + pl);
    sprintf(p, "%s%s%s%s%s", d ? d : "", (d && !HasTrailingSlash(d)) ? "/" : "",
                             s ? s : "", (s && !HasTrailingSlash(s)) ? "/" : "",
                             wfname);

    if (access(p,F_OK))
      strcat(p, ext);
    if (!access(p,F_OK)) {
      lprintf(LO_INFO, " found %s\n", p);
      return p;
    }
    free(p);
  }
  return NULL;
}
#endif

#ifdef _WIN32
static char* WINError(void)
{
  static char *WinEBuff = NULL;
  DWORD err = GetLastError();
  char *ch;

  if (WinEBuff)
  {
    LocalFree(WinEBuff);
  }

  if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
    NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPTSTR) &WinEBuff, 0, NULL) == 0)
  {
    return "Unknown error";
  }

  if ((ch = strchr(WinEBuff, '\n')) != 0)
    *ch = 0;
  if ((ch = strchr(WinEBuff, '\r')) != 0)
    *ch = 0;

  return WinEBuff;
}
#endif

#define DEFAULT_AFFINITY_MASK 1

void I_SetAffinityMask(void)
{
  unsigned int process_affinity_mask = DEFAULT_AFFINITY_MASK;
  int p = M_CheckParm("-affinity");

  if (p && p < myargc-1)
    process_affinity_mask = atoi(myargv[p+1]);

  // Set the process affinity mask so that all threads
  // run on the same processor.  This is a workaround for a bug in
  // SDL_mixer that causes occasional crashes.
  if (process_affinity_mask)
  {
    const char *errbuf = NULL;
#ifdef _WIN32
    if (!SetProcessAffinityMask(GetCurrentProcess(), process_affinity_mask))
    {
      errbuf = WINError();
    }
#elif defined(HAVE_SCHED_SETAFFINITY)
    // POSIX version:
    int i;
    {
      cpu_set_t set;

      CPU_ZERO(&set);

      for(i = 0; i < 16; i++)
      {
        CPU_SET((process_affinity_mask>>i)&1, &set);
      }

      if (sched_setaffinity(getpid(), sizeof(set), &set) == -1)
      {
        errbuf = strerror(errno);
      }
    }
#else
    return;
#endif

    if (errbuf == NULL)
    {
      lprintf(LO_INFO, "I_SetAffinityMask: manual affinity mask is %d\n", process_affinity_mask);
    }
    else
    {
      lprintf(LO_ERROR, "I_SetAffinityMask: failed to set process affinity mask (%s)\n", errbuf);
    }
  }
}

#endif // PRBOOM_SERVER
