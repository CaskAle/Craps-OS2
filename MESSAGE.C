/*****
 * MESSAGE.C processes the messages we wish deal with
 *****/

#define INCL_WIN
#define INCL_GPI

#include <os2.h>
#include <stdlib.h>
#include <stdio.h>
#include "define.h"
#include "craps.h"
#include "message.h"
#include "utility.h"
#include "logic.h"
#include "graphics.h"

/****************************************************************/
/* CreateProc handles the WM_CREATE message                     */
/****************************************************************/

MRESULT CreateProc (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  PCLIENTDATA pclientdata ;
  SIZEL       sizl = {0, 0} ;
  HWND        hwndFrame ;
  MRESULT     mres = 0 ;
  HDC         hdc ;

  WinDefWindowProc (hwnd, msg, mp1, mp2) ;
  pclientdata = PVOIDFROMMP (mp1) ;
  hwndFrame = WinQueryWindow (hwnd, QW_PARENT) ;
  pclientdata->hwndMenu = WinWindowFromID (hwndFrame, FID_MENU) ;
  hdc = WinOpenWindowDC (hwnd) ;
  pclientdata->hps = GpiCreatePS (pclientdata->hab,
                                  hdc,
                                  &sizl,
                                  (ULONG) PU_LOMETRIC |
                                  (ULONG) GPIF_LONG   |
                                  (ULONG) GPIT_NORMAL | 
                                  (ULONG) GPIA_ASSOC) ;
  pclientdata->hdcMemory = DevOpenDC (pclientdata->hab,
                                      OD_MEMORY,
                                      "*",
                                      0,
                                      NULL,
                                      NULLHANDLE) ;
  pclientdata->hpsMemory = GpiCreatePS (pclientdata->hab,
                                        pclientdata->hdcMemory,
                                        &sizl,
                                        (ULONG) PU_LOMETRIC |
                                        (ULONG) GPIF_LONG   |
                                        (ULONG) GPIT_NORMAL |
                                        (ULONG) GPIA_ASSOC) ;
  WinQuerySessionTitle (pclientdata->hab,
                        0,
                        pclientdata->pszApplName,
                        sizeof (pclientdata->pszApplName)) ;
  WinSetWindowText (hwndFrame, pclientdata->pszApplName) ;
  InitGame (&pclientdata->betdata, &pclientdata->dicedata) ;
  InitSettings (&pclientdata->settings) ;
  if (!InitHelp (pclientdata->hab,
                 &pclientdata->hwndHelp,
                 hwndFrame,
                 pclientdata->pszApplName,
                 ID_HELP))
    MessageBox (pclientdata->hab,
                hwnd,
                IDS_HELPERROR,
                IDS_APPLNAME,
                IDS_HELPERRORTITLE,
                (ULONG) MB_OK | 
                (ULONG) MB_MOVEABLE | 
                (ULONG) MB_INFORMATION,
                FALSE) ;
  WinSetWindowPtr (hwnd, QWL_USER, pclientdata) ;
  InitFont (pclientdata->hps) ;
  DrawTable (&pclientdata->hps) ;
  WindowSize (hwndFrame, pclientdata->hps) ;
  return (mres) ;
}

/****************************************************************/
/* DestroyProc handles the WM_DESTROY message                   */
/****************************************************************/

VOID DestroyProc (HWND hwnd)
{
  PCLIENTDATA pclientdata ;

  pclientdata = WinQueryWindowPtr (hwnd, 0) ;
  if (pclientdata->hwndHelp)
    WinDestroyHelpInstance (pclientdata->hwndHelp) ;
  GpiDestroyPS (pclientdata->hps) ;
  GpiDestroyPS (pclientdata->hpsMemory) ;
  DevCloseDC (pclientdata->hdcMemory) ;
  GpiDeleteBitmap (pclientdata->dicedata.hbmDie1) ;
  GpiDeleteBitmap (pclientdata->dicedata.hbmDie2) ;
  return ;
}

/*****
 * SizeProc handles the WM_SIZE message
 * It sets ptlWindowSize to the size of 
 * the window in PAGE units
 *****/

VOID SizeProc (HWND hwnd, MPARAM mp)
{
  PCLIENTDATA pclientdata ;
  MATRIXLF    matlf ;
  POINTL      ptl ;
  SIZEL       sizlModel ;
  SIZEL       sizlPage ;
  FIXED       afxScale[2] ;

  pclientdata = WinQueryWindowPtr (hwnd, 0) ;
  pclientdata->ptlWindowSize.x = SHORT1FROMMP (mp) ;
  pclientdata->ptlWindowSize.y = SHORT2FROMMP (mp) ;
  GpiConvert (pclientdata->hps, 
              CVTC_DEVICE, 
              CVTC_PAGE, 
              1, 
              &pclientdata->ptlWindowSize) ;
  sizlPage.cx = pclientdata->ptlWindowSize.x ;
  sizlPage.cy = pclientdata->ptlWindowSize.y ;
  sizlModel.cx = TBLUNIT * TBLHORZ ;
  sizlModel.cy = TBLUNIT * TBLVERT ;
  if ((sizlPage.cx / sizlPage.cy) > (sizlModel.cx / sizlModel.cy))
    afxScale[0] = (sizlPage.cy * 0x10000) / sizlModel.cy ;
  else
    afxScale[0] = (sizlPage.cx * 0x10000) / sizlModel.cx ;
  afxScale[1] = afxScale [0] ;
  ptl.x = sizlPage.cx / 2 ;
  ptl.y = sizlPage.cy / 2 ;
  ptl.x -= (sizlModel.cx / 2) ;
  ptl.y -= (sizlModel.cy / 2) ;
  GpiTranslate (pclientdata->hps, &matlf, TRANSFORM_REPLACE, &ptl) ;
  ptl.x = sizlPage.cx / 2 ;
  ptl.y = sizlPage.cy / 2 ;
  GpiScale (pclientdata->hps, &matlf, TRANSFORM_ADD, afxScale, &ptl) ;
  GpiSetDefaultViewMatrix (pclientdata->hps, 9, &matlf, TRANSFORM_REPLACE) ;

  pclientdata->dicedata.fDrawn = FALSE ;

  return ;
}

/****************************************************************/
/* PaintProc handles the WM_PAINT message                       */
/****************************************************************/

VOID PaintProc (HWND hwnd)
{
  PCLIENTDATA pclientdata ;
  POINTL      ptl ;
  RECTL       rcl ;

  WinSetPointer (HWND_DESKTOP, 
                 WinQuerySysPointer (HWND_DESKTOP, SPTR_WAIT, FALSE)) ;
  pclientdata = WinQueryWindowPtr (hwnd, 0) ;
  WinBeginPaint (hwnd, pclientdata->hps, &rcl) ;
  WinFillRect (pclientdata->hps, &rcl, CLR_DARKGREEN) ;
  GpiDrawChain (pclientdata->hps) ;
  DrawDice (pclientdata->hps, pclientdata->hpsMemory, &pclientdata->dicedata) ;
  if (pclientdata->dicedata.sPoint)
    SetMarker (pclientdata->hps, pclientdata->dicedata.sPoint, FALSE) ; 
  if (pclientdata->dicedata.sComePoint)
    SetMarker (pclientdata->hps, pclientdata->dicedata.sComePoint, TRUE) ; 
  WinEndPaint (pclientdata->hps) ;
  WinSetPointer (HWND_DESKTOP, 
                 WinQuerySysPointer (HWND_DESKTOP, SPTR_ARROW, FALSE)) ;
  return ;
}

/****************************************************************/
/* CommandProc handles the WM_COMMAND message                   */
/****************************************************************/

VOID CommandProc (HWND hwnd, MPARAM mp1)
{
  PCLIENTDATA pclientdata ;

  pclientdata = WinQueryWindowPtr (hwnd, 0) ;
  switch (SHORT1FROMMP (mp1))
  {
    case IDM_FILENEW:
      NewGame (hwnd,
               &pclientdata->betdata.lMarker,
               &pclientdata->betdata.lBank,
               pclientdata) ;
      break ;
    case IDM_BETPASS:
      PlaceBet (hwnd,
                IDS_PASS,
                pclientdata->dicedata.sPoint,
                &pclientdata->betdata.lnbetPass.lLine,
                &pclientdata->betdata.lnbetPass.lOdds,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETDONTPASS:
      PlaceBet (hwnd,
                IDS_DONTPASS,
                pclientdata->dicedata.sPoint,
                &pclientdata->betdata.lnbetDontPass.lLine,
                &pclientdata->betdata.lnbetDontPass.lOdds,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETCOME:
      PlaceBet (hwnd,
                IDS_COME,
                pclientdata->dicedata.sComePoint,
                &pclientdata->betdata.lnbetCome.lLine,
                &pclientdata->betdata.lnbetCome.lOdds,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETDONTCOME:
      PlaceBet (hwnd,
                IDS_DONTCOME,
                pclientdata->dicedata.sComePoint,
                &pclientdata->betdata.lnbetDontCome.lLine,
                &pclientdata->betdata.lnbetDontCome.lOdds,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETPLACEFOUR:
      PlaceBet (hwnd,
                IDS_PLACEFOUR,
                0,
                &pclientdata->betdata.lPlaceFour,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETPLACEFIVE:
      PlaceBet (hwnd,
                IDS_PLACEFIVE,
                0,
                &pclientdata->betdata.lPlaceFive,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETPLACESIX:
      PlaceBet (hwnd,
                IDS_PLACESIX,
                0,
                &pclientdata->betdata.lPlaceSix,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETPLACEEIGHT:
      PlaceBet (hwnd,
                IDS_PLACEEIGHT,
                0,
                &pclientdata->betdata.lPlaceEight,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETPLACENINE:
      PlaceBet (hwnd,
                IDS_PLACENINE,
                0,
                &pclientdata->betdata.lPlaceNine,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETPLACETEN:
      PlaceBet (hwnd,
                IDS_PLACETEN,
                0,
                &pclientdata->betdata.lPlaceTen,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETANYSEVEN:
      PlaceBet (hwnd,
                IDS_ANYSEVEN,
                0,
                &pclientdata->betdata.lAnySeven,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETANYCRAPS:
      PlaceBet (hwnd,
                IDS_ANYCRAPS,
                0,
                &pclientdata->betdata.lAnyCraps,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETTWO:
      PlaceBet (hwnd,
                IDS_TWO,
                0,
                &pclientdata->betdata.lTwo,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETTHREE:
      PlaceBet (hwnd,
                IDS_THREE,
                0,
                &pclientdata->betdata.lThree,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETELEVEN:
      PlaceBet (hwnd,
                IDS_ELEVEN,
                0,
                &pclientdata->betdata.lEleven,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETTWELVE:
      PlaceBet (hwnd,
                IDS_TWELVE,
                0,
                &pclientdata->betdata.lTwelve,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETHARDFOUR:
      PlaceBet (hwnd,
                IDS_HARDFOUR,
                0,
                &pclientdata->betdata.lHardFour,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETHARDSIX:
      PlaceBet (hwnd,
                IDS_HARDSIX,
                0,
                &pclientdata->betdata.lHardSix,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETHARDEIGHT:
      PlaceBet (hwnd,
                IDS_HARDEIGHT,
                0,
                &pclientdata->betdata.lHardEight,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETHARDTEN:
      PlaceBet (hwnd,
                IDS_HARDTEN,
                0,
                &pclientdata->betdata.lHardTen,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETBIGSIX:
      PlaceBet (hwnd,
                IDS_BIGSIX,
                0,
                &pclientdata->betdata.lBigSix,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETBIGEIGHT:
      PlaceBet (hwnd,
                IDS_BIGEIGHT,
                0,
                &pclientdata->betdata.lBigEight,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_BETFIELD:
      PlaceBet (hwnd,
                IDS_FIELD,
                0,
                &pclientdata->betdata.lField,
                NULL,
                &pclientdata->betdata.lBank,
                pclientdata) ;
      break ;

    case IDM_ROLLROLL:
      PlayGame (hwnd, pclientdata) ;
      break ;

    case IDM_OPTIONSMARKER:
      Marker (hwnd, pclientdata) ;
      break ;

    case IDM_OPTIONSSETTINGS:
      Settings (hwnd, pclientdata) ;
      break ;

    case IDM_HELPHELP:
      if (pclientdata->hwndHelp)
        WinSendMsg (pclientdata->hwndHelp, HM_DISPLAY_HELP, 0L, 0L) ;
      break ;

    case IDM_HELPABOUT:
      Copyright (hwnd, pclientdata->hab, pclientdata->pszApplName) ;
      break ;
  }
  return ;
}

/****************************************************************/
/* InitMenuProc handles the WM_INITMENU message                 */
/****************************************************************/

VOID InitMenuProc (HWND hwnd, MPARAM mp1)
{
  PCLIENTDATA pclientdata ;

  pclientdata = WinQueryWindowPtr (hwnd, 0) ;
  switch (SHORT1FROMMP (mp1))
  {
    case IDM_BET:
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETPASS,
                         (!pclientdata->dicedata.sPoint &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetPass.lLine)) ||
                         (pclientdata->dicedata.sPoint &&
                         pclientdata->betdata.lnbetPass.lLine &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetPass.lOdds))) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETPASS,
                        pclientdata->betdata.lnbetPass.lLine) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETDONTPASS,
                         (!pclientdata->dicedata.sPoint &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetDontPass.lLine)) ||
                         (pclientdata->dicedata.sPoint &&
                         pclientdata->betdata.lnbetDontPass.lLine &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetDontPass.lOdds))) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETDONTPASS,
                        pclientdata->betdata.lnbetDontPass.lLine) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETCOME,
                         (pclientdata->dicedata.sPoint &&
                         !pclientdata->dicedata.sComePoint &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetCome.lLine)) ||
                         (pclientdata->dicedata.sComePoint &&
                         pclientdata->betdata.lnbetCome.lLine &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetCome.lOdds))) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETCOME,
                        pclientdata->betdata.lnbetCome.lLine) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETDONTCOME,
                         (pclientdata->dicedata.sPoint &&
                         !pclientdata->dicedata.sComePoint &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetDontCome.lLine)) ||
                         (pclientdata->dicedata.sComePoint &&
                         pclientdata->betdata.lnbetDontCome.lLine &&
                         ((pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lnbetDontCome.lOdds))) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETDONTCOME,
                        pclientdata->betdata.lnbetDontCome.lLine) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETBIGSIX,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lBigSix) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETBIGSIX,
                        pclientdata->betdata.lBigSix) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETBIGEIGHT,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lBigEight) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETBIGEIGHT,
                        pclientdata->betdata.lBigEight) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETFIELD,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lField) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETFIELD,
                        pclientdata->betdata.lField) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETPLACEFOUR,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lPlaceFour) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETPLACEFOUR,
                        pclientdata->betdata.lPlaceFour) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETPLACEFIVE,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lPlaceFive) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETPLACEFIVE,
                        pclientdata->betdata.lPlaceFive) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETPLACESIX,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lPlaceSix) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETPLACESIX,
                        pclientdata->betdata.lPlaceSix) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETPLACEEIGHT,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lPlaceEight) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETPLACEEIGHT,
                        pclientdata->betdata.lPlaceEight) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETPLACENINE,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lPlaceNine) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETPLACENINE,
                        pclientdata->betdata.lPlaceNine) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETPLACETEN,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lPlaceTen) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETPLACETEN,
                        pclientdata->betdata.lPlaceTen) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETANYSEVEN,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lAnySeven) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETANYSEVEN,
                        pclientdata->betdata.lAnySeven) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETANYCRAPS,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lAnyCraps) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETANYCRAPS,
                        pclientdata->betdata.lAnyCraps) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETTWO,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lTwo) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETTWO,
                        pclientdata->betdata.lTwo) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETTHREE,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lThree) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETTHREE,
                        pclientdata->betdata.lThree) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETELEVEN,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lEleven) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETELEVEN,
                        pclientdata->betdata.lEleven) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETTWELVE,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lTwelve) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETTWELVE,
                        pclientdata->betdata.lTwelve) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETHARDFOUR,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lHardFour) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETHARDFOUR,
                        pclientdata->betdata.lHardFour) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETHARDSIX,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lHardSix) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETHARDSIX,
                        pclientdata->betdata.lHardSix) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETHARDEIGHT,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lHardEight) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETHARDEIGHT,
                        pclientdata->betdata.lHardEight) ;
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_BETHARDTEN,
                         (pclientdata->betdata.lBank >=
                         pclientdata->settings.lMinBet) ||
                         pclientdata->betdata.lHardTen) ;
      WinCheckMenuItem (pclientdata->hwndMenu,
                        IDM_BETHARDTEN,
                        pclientdata->betdata.lHardTen) ;
      break ;

    case IDM_ROLL:
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_ROLLROLL,
                         pclientdata->betdata.lnbetPass.lLine ||
                         pclientdata->betdata.lnbetDontPass.lLine ||
                         pclientdata->betdata.lnbetCome.lLine ||
                         pclientdata->betdata.lnbetDontCome.lLine ||
                         pclientdata->betdata.lPlaceFour ||
                         pclientdata->betdata.lPlaceFive ||
                         pclientdata->betdata.lPlaceSix ||
                         pclientdata->betdata.lPlaceEight ||
                         pclientdata->betdata.lPlaceNine ||
                         pclientdata->betdata.lPlaceTen ||
                         pclientdata->betdata.lAnySeven ||
                         pclientdata->betdata.lAnyCraps ||
                         pclientdata->betdata.lTwo ||
                         pclientdata->betdata.lTwelve ||
                         pclientdata->betdata.lThree ||
                         pclientdata->betdata.lEleven ||
                         pclientdata->betdata.lHorn ||
                         pclientdata->betdata.lHop ||
                         pclientdata->betdata.lCrapsEleven ||
                         pclientdata->betdata.lHardFour ||
                         pclientdata->betdata.lHardSix ||
                         pclientdata->betdata.lHardEight ||
                         pclientdata->betdata.lHardTen ||
                         pclientdata->betdata.lBigSix ||
                         pclientdata->betdata.lBigEight ||
                         pclientdata->betdata.lField) ;
      break ;

    case IDM_OPTIONS:
      WinEnableMenuItem (pclientdata->hwndMenu,
                         IDM_OPTIONSMARKER,
                         (pclientdata->betdata.lBank ||
                          (pclientdata->betdata.lMarker <
                           pclientdata->settings.lMaxMarker))) ;
      break ;
  }
  return ;
}

