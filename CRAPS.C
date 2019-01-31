/*****
 * CRAPS.C main source
 *****/

#define INCL_WIN

#include <os2.h>
#include <stdlib.h>
#include "define.h"
#include "craps.h"
#include "winprocs.h"
#include "utility.h"

/*****
 * main function
 *****/

int main (VOID)
{
  HMQ         hmq ;
  QMSG        qmsg ;
  HWND        hwndFrame ;
  HWND        hwndClient ;
  BOOL        fQuit = FALSE ;
  CHAR        pszString[BUFFERLEN] ;
  FRAMECDATA  fcdata ;
  PCLIENTDATA pclientdata ;

  pclientdata = malloc (sizeof (CLIENTDATA)) ;
  fcdata.cb = sizeof (FRAMECDATA) ;
  fcdata.hmodResources = NULLHANDLE ;
  fcdata.idResources = ID_MAIN ;
  fcdata.flCreateFlags = (ULONG) FCF_SYSMENU    |
                         (ULONG) FCF_MINMAX     |
                         (ULONG) FCF_SIZEBORDER | 
                         (ULONG) FCF_ACCELTABLE |
                         (ULONG) FCF_TITLEBAR   | 
                         (ULONG) FCF_TASKLIST   |
                         (ULONG) FCF_ICON       |
                         (ULONG) FCF_MENU       ;
  pclientdata->hab = WinInitialize (0) ;
  hmq = WinCreateMsgQueue (pclientdata->hab, 0) ;
  WinRegisterClass (pclientdata->hab,
                    WC_CRAPS,
                    wpClientWndProc,
                    CS_SIZEREDRAW,
                    sizeof (PCLIENTDATA)) ;
  hwndFrame = WinCreateWindow (HWND_DESKTOP,
                               WC_FRAME,
                               NULL,
                               0,
                               0, 0, 0, 0,
                               NULLHANDLE,
                               HWND_TOP,
                               ID_MAIN,
                               &fcdata,
                               NULL) ;
  hwndClient = WinCreateWindow (hwndFrame,
                                WC_CRAPS,
                                NULL,
                                0,
                                0, 0, 0, 0,
                                NULLHANDLE,
                                HWND_TOP,
                                FID_CLIENT,
                                pclientdata,
                                NULL) ;
  while (!fQuit)
    if (WinGetMsg (pclientdata->hab, &qmsg, NULLHANDLE, 0, 0))
      WinDispatchMsg (pclientdata->hab, &qmsg) ;
    else
    {
      WinLoadString (pclientdata->hab,
                     NULLHANDLE,
                     IDS_CLOSEMESSAGE,
                     sizeof (pszString),
                     pszString) ;
      if (MBID_OK == WinMessageBox (HWND_DESKTOP,
                                    hwndClient,
                                    pszString,
                                    pclientdata->pszApplName,
                                    0,
                                    (ULONG) MB_OKCANCEL |
                                    (ULONG) MB_MOVEABLE |
                                    (ULONG) MB_WARNING))
        fQuit = TRUE ;
      else
        WinCancelShutdown (hmq, FALSE) ;
    }
  WinDestroyWindow (hwndFrame) ;
  WinDestroyMsgQueue (hmq) ;
  WinTerminate (pclientdata->hab) ;
  free (pclientdata) ;
  return (0) ;
}
