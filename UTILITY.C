/************************************************************************/
/* UTILITY.C contains various utility functions                         */
/************************************************************************/

#define INCL_WINFRAMEMGR
#define INCL_WINWINDOWMGR
#define INCL_WINMESSAGEMGR
#define INCL_WINHELP
#define INCL_WINMENUS
#define INCL_WINDIALOGS
#define INCL_WININPUT
#define INCL_WINTIMER
#define INCL_GPITRANSFORMS
#define INCL_DOSPROCESS
#define INCL_WINBUTTONS
#define INCL_WINENTRYFIELDS

#include <os2.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "define.h"
#include "craps.h"
#include "winprocs.h"
#include "crapsdlg.h"
#include "utility.h"
#include "graphics.h"

/************************/
/* Window size function */
/************************/

VOID WindowSize (HWND hwnd, HPS hps)
{
  RECTL  rcl ;
  POINTL ptl ;

  ptl.x = 2250 ;
  ptl.y = 850 ;
  GpiConvert (hps, CVTC_PAGE, CVTC_DEVICE, 1, &ptl) ;
  rcl.xLeft = 20 ;
  rcl.xRight = rcl.xLeft + ptl.x ;
  rcl.yBottom = 100 ;
  rcl.yTop = rcl.yBottom + ptl.y ;
  WinCalcFrameRect (hwnd, &rcl, FALSE) ;
  WinSetWindowPos (hwnd,
                   NULLHANDLE,
                   rcl.xLeft,
                   rcl.yBottom,
                   rcl.xRight - rcl.xLeft,
                   rcl.yTop - rcl.yBottom,
                   (ULONG) SWP_SIZE     | (ULONG) SWP_MOVE  | 
                   (ULONG) SWP_ACTIVATE | (ULONG) SWP_SHOW) ;
  return ;
}

/************************************************************************/
/* SetSystemMenu removes items from dialog box system menus             */
/************************************************************************/

VOID SetSystemMenu (HWND hwnd)
{
  MENUITEM mi;
  SHORT    sItemIndex ;
  USHORT   usItemCount ;
  USHORT   usItemId ;

  WinSendMsg (WinWindowFromID (hwnd, FID_SYSMENU),
              MM_QUERYITEM,
              MPFROM2SHORT (SC_SYSMENU, FALSE),
              MPFROMP ((PCH) &mi)) ;
  sItemIndex = 0 ;
  usItemCount = SHORT1FROMMR (WinSendMsg (mi.hwndSubMenu,
                                          MM_QUERYITEMCOUNT,
                                          (MPARAM) 0,
                                          (MPARAM) 0)) ;
  while (usItemCount--)
  {
    usItemId = SHORT1FROMMR (WinSendMsg (mi.hwndSubMenu,
                                         MM_ITEMIDFROMPOSITION,
                                         MPFROM2SHORT (sItemIndex, TRUE),
                                         (MPARAM) 0)) ;
    if ((usItemId == SC_MOVE) || (usItemId == SC_CLOSE))
      sItemIndex++ ;
    else
      WinSendMsg (mi.hwndSubMenu,
                  MM_DELETEITEM,
                  MPFROM2SHORT(usItemId, TRUE),
                  (MPARAM) 0) ;
  }
  return ;
}

/************************************************************************/
/* InitHelp initializes the help instance                               */
/************************************************************************/

BOOL InitHelp (HAB hab,
               PHWND phwndHelp,
               HWND hwndFrame,
               PSZ pszApplName,
               PSZ pszHelpName)
{
  BOOL     fCreated = FALSE ;
  HELPINIT hinit ;

  hinit.cb = sizeof (HELPINIT) ;
  hinit.ulReturnCode = 0 ;
  hinit.pszTutorialName = NULL ;
  hinit.phtHelpTable = (PHELPTABLE) (0xFFFF0000 | (ULONG) ID_MAIN) ;
  hinit.hmodHelpTableModule = NULLHANDLE ;
  hinit.hmodAccelActionBarModule = NULLHANDLE ;
  hinit.idAccelTable = 0 ;
  hinit.idActionBar = 0 ;
  hinit.pszHelpWindowTitle = pszApplName ;
  hinit.fShowPanelId = CMIC_HIDE_PANEL_ID ;
  hinit.pszHelpLibraryName = pszHelpName ;
  *phwndHelp = WinCreateHelpInstance (hab, &hinit) ;
  if (*phwndHelp)
    if (hinit.ulReturnCode)
      WinDestroyHelpInstance (*phwndHelp) ;
    else
    {
      WinAssociateHelpInstance (*phwndHelp, hwndFrame) ;
      fCreated = TRUE ;
    }
  return fCreated ;
}

/************************************************************************/
/* MessageBox loads a string and displays it in a message box           */
/************************************************************************/

ULONG MessageBox (HAB hab,
                  HWND hwnd,
                  ULONG ulMessageNum,
                  ULONG ulTitleFront,
                  ULONG ulTitleBack,
                  ULONG flStyle,
                  BOOL fBeep,
                  ...)
{
  va_list vargs ;
  CHAR    pszTempString[BUFFERLEN] ;
  CHAR    pszMsgString[BUFFERLEN] ;
  CHAR    pszTitleString[BUFFERLEN] ;
  ULONG   ulReturn ;

  WinLoadString (hab,
                 NULLHANDLE,
                 ulTitleFront,
                 sizeof (pszTitleString),
                 pszTitleString) ;
  if (ulTitleBack)
  {
    WinLoadString (hab,
                   NULLHANDLE,
                   IDS_SEPARATOR,
                   sizeof (pszTempString),
                   pszTempString) ;
    strcat (pszTitleString, pszTempString) ;
    WinLoadString (hab,
                   NULLHANDLE,
                   ulTitleBack,
                   sizeof (pszTempString),
                   pszTempString) ;
    strcat (pszTitleString, pszTempString) ;
  }
  WinLoadString (hab,
                 NULLHANDLE,
                 ulMessageNum,
                 sizeof (pszTempString),
                 pszTempString) ;
  va_start (vargs, fBeep) ;
  vsprintf (pszMsgString, pszTempString, vargs) ;
  va_end (vargs) ;
  if (fBeep)
    WinAlarm (HWND_DESKTOP, WA_ERROR) ;
  ulReturn = WinMessageBox (HWND_DESKTOP,
                            hwnd,
                            pszMsgString,
                            pszTitleString,
                            0,
                            flStyle) ;
  return ulReturn ;
}

/************************************************************************/
/* InitGame initializes the bets and dice to zero                       */
/************************************************************************/

VOID InitGame (PBETDATA pbetdata, PDICEDATA pdicedata)
{
  pbetdata->lMarker = DEF_MAXBET ;
  pbetdata->lBank = 0 ;
  pbetdata->lnbetPass.lLine = 0 ;
  pbetdata->lnbetPass.lOdds = 0 ;
  pbetdata->lnbetDontPass.lLine = 0 ;
  pbetdata->lnbetDontPass.lOdds = 0 ;
  pbetdata->lnbetCome.lLine = 0 ;
  pbetdata->lnbetCome.lOdds = 0 ;
  pbetdata->lnbetDontCome.lLine = 0 ;
  pbetdata->lnbetDontCome.lOdds = 0 ;
  pbetdata->lBigSix = 0 ;
  pbetdata->lBigEight = 0 ;
  pbetdata->lField = 0 ;
  pbetdata->lPlaceFour = 0 ;
  pbetdata->lPlaceFive = 0 ;
  pbetdata->lPlaceSix = 0 ;
  pbetdata->lPlaceEight = 0 ;
  pbetdata->lPlaceNine = 0 ;
  pbetdata->lPlaceTen = 0 ;
  pbetdata->lAnySeven = 0 ;
  pbetdata->lAnyCraps = 0 ;
  pbetdata->lTwo = 0 ;
  pbetdata->lTwelve = 0 ;
  pbetdata->lThree = 0 ;
  pbetdata->lEleven = 0 ;
  pbetdata->lHorn = 0 ;
  pbetdata->lHop = 0 ;
  pbetdata->lCrapsEleven = 0 ;
  pbetdata->lHardFour = 0 ;
  pbetdata->lHardSix = 0 ;
  pbetdata->lHardEight = 0 ;
  pbetdata->lHardTen = 0 ;
  pdicedata->sDie1 = 4 ;
  pdicedata->sDie2 = 3 ;
  pdicedata->sRoll = (SHORT) (pdicedata->sDie1 + pdicedata->sDie2) ;
  pdicedata->sPoint = 0 ;
  pdicedata->sComePoint = 0 ;
  pdicedata->ptlDie1.x = DEF_DIE1POSX ;
  pdicedata->ptlDie1.y = DEF_DIEPOSY ;
  pdicedata->ptlDie2.x = DEF_DIE2POSX ;
  pdicedata->ptlDie2.y = DEF_DIEPOSY ;
  return ;                
}

/************************************************************************/
/* InitSettings initializes user settings to their defaults             */
/************************************************************************/

VOID InitSettings (PSETTINGS psettings)
{
  psettings->lDefaultBet = DEF_BET ;
  psettings->lDefaultMarker = DEF_MARKER ;
  psettings->lMinBet = DEF_MINBET ;
  psettings->lMaxBet = DEF_MAXBET ;
  psettings->lMaxMarker = DEF_MAXBET ;
  psettings->sOddsMultiple = DEF_ODDSMULTIPLE ;
  psettings->fAutoOdds = DEF_AUTOODDS ;
  psettings->fBetsOnComeOut = DEF_BETSONCOME ;
  psettings->fGuidoExtracts = DEF_GUIDO ;
  return ;
}

/************************************************************************/
/* PlaceBet is used for initializing the bet dialog call                */
/************************************************************************/

VOID PlaceBet (HWND hwnd,
               ULONG ulBetName,
               SHORT sPoint,
               PLONG plBet,
               PLONG plOdds,
               PLONG plBank,
               PCLIENTDATA pclientdata)
{
  BETDLGDATA betdlgdata ;
  BOOL       fLineBet = FALSE ;
  BOOL       fRight = FALSE ;

  if ((ulBetName == IDS_PASS) || (ulBetName == IDS_DONTPASS) ||
      (ulBetName == IDS_COME) || (ulBetName == IDS_DONTCOME))
    fLineBet = TRUE ;
  if ((ulBetName == IDS_PASS) || (ulBetName == IDS_COME))
    fRight = TRUE ;
  betdlgdata.hwndHelp = pclientdata->hwndHelp ;
  betdlgdata.hab = pclientdata->hab ;
  strcpy (betdlgdata.pszApplName, pclientdata->pszApplName) ;
  betdlgdata.ulBetName = ulBetName ;
  betdlgdata.fLineBet = fLineBet ;
  betdlgdata.lMinBet = pclientdata->settings.lMinBet ;
  betdlgdata.lMaxBet = pclientdata->settings.lMaxBet ;
  betdlgdata.lBank = *plBank ;
  betdlgdata.sPoint = sPoint ;
  betdlgdata.lBet = *plBet ;
  betdlgdata.lOldBet = *plBet ;
  if ((sPoint) && (fLineBet))
  {
    betdlgdata.lOdds = *plOdds ;
    betdlgdata.lOldOdds = *plOdds ;
    betdlgdata.lMaxOdds = SetMaxOdds (sPoint,
                                      pclientdata->settings.sOddsMultiple,
                                      *plBet,
                                      fRight) ;
    if (*plOdds)
      betdlgdata.lDefaultOdds = *plOdds ;
    else
    {
      if (pclientdata->settings.fAutoOdds)
        betdlgdata.lDefaultOdds = betdlgdata.lMaxOdds ;
      else
        betdlgdata.lDefaultOdds = pclientdata->settings.lDefaultBet ;
      if (betdlgdata.lDefaultOdds > *plBank)
        betdlgdata.lDefaultOdds = *plBank ;
    }
  }
  if (*plBet)
    betdlgdata.lDefaultBet = *plBet ;
  else
    betdlgdata.lDefaultBet = (pclientdata->settings.lDefaultBet < *plBank) ?
                              pclientdata->settings.lDefaultBet : *plBank ;
  if (WinDlgBox (HWND_DESKTOP,
                 hwnd,
                 wpBetDlgProc,
                 NULLHANDLE,
                 IDD_BETBOX,
                 &betdlgdata))
  {
    *plBet = betdlgdata.lBet ;
    *plBank += betdlgdata.lOldBet ;
    *plBank -= *plBet ;
    if ((sPoint) && (fLineBet))
    {
      *plOdds = betdlgdata.lOdds ;
      *plBank += betdlgdata.lOldOdds ;
      *plBank -= *plOdds ;
    }
  }
  return ;
}

/************************************************************************/
/* NewGame is used for initializing the table for a new game            */
/************************************************************************/

VOID NewGame (HWND hwnd,
              PLONG plMarker, 
              PLONG plBank, 
              PCLIENTDATA pclientdata)
{
  NEWDLGDATA newdlgdata ;

  newdlgdata.hwndHelp = pclientdata->hwndHelp ;
  newdlgdata.hab = pclientdata->hab ;
  strcpy (newdlgdata.pszApplName, pclientdata->pszApplName) ;
  newdlgdata.lMinBet = pclientdata->settings.lMinBet ;
  newdlgdata.lMaxMarker = pclientdata->settings.lMaxMarker ;
  newdlgdata.lMarker = *plMarker ;
  newdlgdata.lDefaultMarker = pclientdata->settings.lDefaultMarker ;
  if (WinDlgBox (HWND_DESKTOP,
                 hwnd,
                 wpNewDlgProc,
                 NULLHANDLE,
                 IDD_NEWBOX,
                 &newdlgdata))
  {
    if (pclientdata->dicedata.sPoint)
      ClearMarker (pclientdata->hps, pclientdata->dicedata.sPoint) ;
    if (pclientdata->dicedata.sComePoint)
      ClearMarker (pclientdata->hps, pclientdata->dicedata.sComePoint) ;
    InitGame (&pclientdata->betdata, &pclientdata->dicedata) ;
    *plMarker = newdlgdata.lMarker ;
    *plBank = *plMarker ;
  }
  return ;
}

/************************************************************************/
/* Copyright is used for initializing the about dialog box              */
/************************************************************************/

VOID Copyright (HWND hwnd, HAB hab, PSZ pszApplName)
{
  INFODLGDATA infodlgdata ;

  infodlgdata.hab = hab ;
  strcpy (infodlgdata.pszApplName, pszApplName) ;
  WinDlgBox (HWND_DESKTOP,
             hwnd,
             wpInfoDlgProc,
             NULLHANDLE,
             IDD_ABOUTBOX,
             &infodlgdata) ;
  return ;
}

/************************************************************************/
/* SetMaxOdds is used to determine the maximum odds allowed             */
/************************************************************************/

LONG SetMaxOdds (SHORT sPoint, SHORT sOddsMultiple, LONG lBet, BOOL fRight)
{
  LONG lMaxOdds ;

  switch (sPoint)
  {
    case  4:
    case 10:
      if (fRight)
        lMaxOdds = lBet * sOddsMultiple ;
      else
        lMaxOdds = (lBet * sOddsMultiple) * 2 ;
      break ;

    case  5:
    case  9:
      if (fRight)
        if ((sOddsMultiple == 1) && (lBet % 2))
          lMaxOdds = lBet + 1 ;
        else
          lMaxOdds = lBet * sOddsMultiple ;
      else
        if ((sOddsMultiple == 1) && (lBet % 2))
          lMaxOdds = ((lBet + 1) / 2) * 3 ;
        else
          lMaxOdds = ((lBet * sOddsMultiple) / 2) * 3 ;
      break ;

    case  6:
    case  8:
      if (fRight)
        if ((sOddsMultiple == 1) && (!(lBet % 3)))
          lMaxOdds = (lBet / 3) * 5 ;
        else if ((sOddsMultiple == 2) && (!(lBet % 2)))
          lMaxOdds = (lBet / 2) * 5 ;
        else
          lMaxOdds = lBet * sOddsMultiple ;
      else
        lMaxOdds = ((lBet * sOddsMultiple) / 5) * 6 ;
      break ;
  }
  return (lMaxOdds) ;
}


/************************************************************************/
/* EntryError handles invalid values in the entry boxes                 */
/************************************************************************/

VOID EntryError (HAB hab,
                 HWND hwnd,
                 HWND hwndFocus,
                 ULONG ulBetName,
                 ULONG ulField,
                 ULONG ulErrorType,
                 LONG lAmount,
                 LONG lDefault)
{
  CHAR pszString[BUFFERLEN] ;

  MessageBox (hab,
              hwnd,
              ulErrorType,
              ulBetName,
              IDS_ENTRYERROR,
              (ULONG) MB_OK | (ULONG) MB_MOVEABLE | (ULONG) MB_INFORMATION,
              TRUE,
              lAmount) ;
  WinSetDlgItemText (hwnd,
                     ulField,
                     lDefault ? _ltoa (lDefault, pszString, 10) : "") ;
  WinSendDlgItemMsg (hwnd,
                     ulField,
                     EM_SETSEL,
                     MPFROM2SHORT (0, DEF_BETLEN),
                     NULL) ;
  WinSetFocus (HWND_DESKTOP, hwndFocus) ;
  return ;
}

/************************************************************************/
/* BetResult displays a messagebox with the results of the bet          */
/************************************************************************/

VOID BetResult (HAB hab,
                HWND hwnd,
                ULONG ulBetName,
                LONG lBet,
                LONG lWinnings,
                LONG lBank,
                BOOL fWinner)
{
  CHAR  pszString[BUFFERLEN] ;
  ULONG ulTitle ;
  ULONG ulText ;

  WinLoadString (hab,
                 NULLHANDLE,
                 ulBetName,
                 sizeof (pszString),
                 pszString) ;
  if (fWinner)
  {
    DosBeep (261, 100) ;
    DosBeep (330, 100) ;
    DosBeep (392, 100) ;
    DosBeep (523, 100) ;
    ulText = IDS_WINNER ;
    ulTitle = IDS_WINTITLE ;
  }
  else
  {
    DosBeep (50, 400) ;
    ulText = (ULONG) ((lWinnings == 0) ? IDS_PUSH : IDS_LOSER) ;
    ulTitle = (ULONG) ((lWinnings == 0) ? IDS_PUSHTITLE : IDS_LOSETITLE) ;
  }

  MessageBox (hab,
              hwnd,
              ulText,
              ulBetName,
              ulTitle,
              (ULONG) MB_OK | (ULONG) MB_MOVEABLE | (ULONG) MB_INFORMATION,
              FALSE,
              pszString,
              lBet,
              lWinnings,
              lBank) ;
  return ;
}

/************************************************************************/
/* Settings is used for initializing the settings dialog call           */
/************************************************************************/

VOID Settings (HWND hwnd, PCLIENTDATA pclientdata)
{
  SETTINGSDLGDATA settingsdlgdata ;

  settingsdlgdata.hab = pclientdata->hab ;
  strcpy (settingsdlgdata.pszApplName, pclientdata->pszApplName) ;
  settingsdlgdata.lOldMinBet = pclientdata->settings.lMinBet ;
  settingsdlgdata.lOldMaxBet = pclientdata->settings.lMaxBet ;
  settingsdlgdata.lOldDefaultBet = pclientdata->settings.lDefaultBet ;
  settingsdlgdata.hwndHelp = pclientdata->hwndHelp ;
  settingsdlgdata.settings = pclientdata->settings ;
  if (WinDlgBox (HWND_DESKTOP,
                 hwnd,
                 wpSettingsDlgProc,
                 NULLHANDLE,
                 IDD_SETTINGSBOX,
                 &settingsdlgdata))
    pclientdata->settings = settingsdlgdata.settings ;
  return ;
}

/************************************************************************/
/* InitSettingsDlg is used for initializing the settings dialog items   */
/************************************************************************/

VOID InitSettingsDlg (HWND hwnd, PSETTINGS psettings)
{
  CHAR pszString[BUFFERLEN] ;

  WinSetDlgItemText (hwnd,
                     IDD_MINBET,
                     psettings->lMinBet ?
                     _ltoa (psettings->lMinBet, pszString, 10)
                     : "") ;
  WinSendDlgItemMsg (hwnd,
                     IDD_MINBET,
                     EM_SETTEXTLIMIT,
                     MPFROM2SHORT (DEF_BETLEN, 0),
                     NULL) ;
  WinSendDlgItemMsg (hwnd,
                     IDD_MINBET,
                     EM_SETSEL,
                     MPFROM2SHORT (0, DEF_BETLEN),
                     NULL) ;
  WinSetDlgItemText (hwnd,
                     IDD_MAXBET,
                     psettings->lMaxBet ?
                     _ltoa (psettings->lMaxBet, pszString, 10)
                     : "") ;
  WinSendDlgItemMsg (hwnd,
                     IDD_MAXBET,
                     EM_SETTEXTLIMIT,
                     MPFROM2SHORT (DEF_BETLEN, 0),
                     NULL) ;
  WinSendDlgItemMsg (hwnd,
                     IDD_MAXBET,
                     EM_SETSEL,
                     MPFROM2SHORT (0, DEF_BETLEN),
                     NULL) ;
  WinSetDlgItemText (hwnd,
                     IDD_DEFAULTBET,
                     psettings->lDefaultBet ?
                     _ltoa (psettings->lDefaultBet, pszString, 10)
                     : "") ;
  WinSendDlgItemMsg (hwnd,
                     IDD_DEFAULTBET,
                     EM_SETTEXTLIMIT,
                     MPFROM2SHORT (DEF_BETLEN, 0),
                     NULL) ;
  WinSendDlgItemMsg (hwnd,
                     IDD_DEFAULTBET,
                     EM_SETSEL,
                     MPFROM2SHORT (0, DEF_BETLEN),
                     NULL) ;
  if (psettings->sOddsMultiple == 1)
    WinCheckButton (hwnd, IDD_SINGLE, TRUE) ;
  else
    WinCheckButton (hwnd, IDD_DOUBLE, TRUE) ;
  WinCheckButton (hwnd, IDD_BETSONCOME, psettings->fBetsOnComeOut) ;
  WinCheckButton (hwnd, IDD_AUTOODDS, psettings->fAutoOdds) ;
  WinCheckButton (hwnd, IDD_GUIDO, psettings->fGuidoExtracts) ;
  return ;
}

/************************************************************************/
/* Marker is used for initializing the marker dialog call               */
/************************************************************************/

VOID Marker (HWND hwnd, PCLIENTDATA pclientdata)
{
  MARKERDLGDATA markerdlgdata ;

  markerdlgdata.hwndHelp = pclientdata->hwndHelp ;
  markerdlgdata.hab = pclientdata->hab ;
  strcpy (markerdlgdata.pszApplName, pclientdata->pszApplName) ;
  markerdlgdata.lMarker = pclientdata->betdata.lMarker ;
  markerdlgdata.lBank = pclientdata->betdata.lBank ;
  markerdlgdata.lMaxMarker = pclientdata->settings.lMaxMarker ;
  markerdlgdata.lDefaultChange = pclientdata->settings.lDefaultBet ;
  if (WinDlgBox (HWND_DESKTOP,
                 hwnd,
                 wpMarkerDlgProc,
                 NULLHANDLE,
                 IDD_MARKERBOX,
                 &markerdlgdata))
  {
    pclientdata->betdata.lBank = markerdlgdata.lBank ;
    pclientdata->betdata.lMarker = markerdlgdata.lMarker ;
  }
  return ;
}

/************************************************************************/
/* Check to see if Guido needs to extract money                         */
/************************************************************************/

VOID Guido (HWND hwnd, HAB hab, PLONG lBank, PLONG lMarker, LONG lWinnings)
{
  LONG lLoss ;
  LONG lGuido ;

  srand (WinGetCurrentTime (NULLHANDLE)) ;
  lGuido = rand () % 100 + 1 ;
  if ((lWinnings >= (*lMarker * lGuido / 100)) &&
      ((*lBank - *lMarker) >= (*lMarker * lGuido / 100)))
  {
    lLoss = lWinnings * lGuido / 100 ;
    lLoss = (*lMarker >= lLoss) ? lLoss : *lMarker ;
    *lBank -= lLoss ;
    *lMarker -= lLoss ;
    DosBeep (50, 400) ;
    MessageBox (hab,
                hwnd,
                IDS_GUIDO,
                IDS_MARKERTITLE,
                IDS_GUIDOTITLE,
                (ULONG) MB_OK | (ULONG) MB_MOVEABLE | (ULONG) MB_INFORMATION,
                FALSE,
                lLoss,
                *lBank,
                *lMarker) ;
  }
  return ;
}

