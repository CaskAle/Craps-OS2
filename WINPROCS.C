/*****
 * WINPROCS.C is the program's window procedures
 *****/

#define INCL_WIN

#include <os2.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "craps.h"
#include "winprocs.h"
#include "message.h"
#include "crapsdlg.h"
#include "utility.h"

/*****
 * wpClientWndProc is the main window procedure
 *****/

MRESULT EXPENTRY wpClientWndProc (HWND hwnd, 
                                  ULONG msg, 
                                  MPARAM mp1, 
                                  MPARAM mp2)
{
  MRESULT mres = 0 ;

  switch (msg)
  {
    case WM_CREATE:
      mres = CreateProc (hwnd, msg, mp1, mp2) ;
      break ;

    case WM_PAINT:
      PaintProc (hwnd) ;
      break ;

    case WM_SIZE:
      SizeProc (hwnd, mp2) ;
      break ;

    case WM_COMMAND:
      CommandProc (hwnd, mp1) ;
      break ;

    case WM_INITMENU:
      InitMenuProc (hwnd, mp1) ;
      break ;

    case WM_DESTROY:
      DestroyProc (hwnd) ;
      break ;

    default:
      mres = WinDefWindowProc (hwnd, msg, mp1, mp2) ;
      break ;
  }
  return (mres) ;
}

/****************************************************************/
/*  wpInfoDlgProc for the about dialog box                      */
/****************************************************************/

MRESULT EXPENTRY wpInfoDlgProc (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  MRESULT      mres = (MRESULT) FALSE ;
  CHAR         pszString[BUFFERLEN] ;
  CHAR         pszTempString[BUFFERLEN] ;
  PINFODLGDATA pinfodlgdata ;

  switch (msg)
  {
    case WM_INITDLG:
      pinfodlgdata = PVOIDFROMMP (mp2) ;
      SetSystemMenu (hwnd) ;
      strcpy (pszString, pinfodlgdata->pszApplName) ;
      WinLoadString (pinfodlgdata->hab,
                     NULLHANDLE,
                     IDS_SEPARATOR,
                     sizeof (pszTempString),
                     pszTempString) ;
      strcat (pszString, pszTempString) ;
      WinLoadString (pinfodlgdata->hab,
                     NULLHANDLE,
                     IDS_PRODUCTINFO,
                     sizeof (pszTempString),
                     pszTempString) ;
      strcat (pszString, pszTempString) ;
      WinSetWindowText (hwnd, pszString) ;
      WinLoadString (pinfodlgdata->hab,
                     NULLHANDLE,
                     IDS_APPLNAME,
                     sizeof (pszString),
                     pszString) ;
      WinSetDlgItemText (hwnd, IDD_APPLNAME, pszString) ;
      WinLoadString (pinfodlgdata->hab,
                     NULLHANDLE,
                     IDS_VERSION,
                     sizeof (pszString),
                     pszString) ;
      WinSetDlgItemText (hwnd, IDD_VERSION, pszString) ;
      WinLoadString (pinfodlgdata->hab,
                     NULLHANDLE,
                     IDS_AUTHOR,
                     sizeof (pszString),
                     pszString) ;
      WinSetDlgItemText (hwnd, IDD_AUTHOR, pszString) ;
      WinSetDlgItemText (hwnd, IDD_COPYRIGHT, __DATE__) ;
      break ;

    case WM_COMMAND:
      switch (SHORT1FROMMP (mp1))
      {
        case DID_OK:
        case DID_CANCEL:
          WinDismissDlg (hwnd, FALSE) ;
          break ;
      }
      break ;

    default:
      mres = WinDefDlgProc (hwnd, msg, mp1, mp2) ;
      break ;
  }
  return mres ;
}

/****************************************************************/
/*  wpBetDlgProc for the bet dialog box                         */
/****************************************************************/

MRESULT EXPENTRY wpBetDlgProc (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  MRESULT     mres = (MRESULT) FALSE ;
  PBETDLGDATA pbetdlgdata ;
  CHAR        pszString[BUFFERLEN] ;
  CHAR        pszTempString[BUFFERLEN] ;
  HWND        hwndFocus ;
  BOOL        fGoodData = FALSE ;

  switch (msg)
  {
    case WM_INITDLG:
      pbetdlgdata = PVOIDFROMMP (mp2) ;
      WinSetWindowPtr (hwnd, QWL_USER, pbetdlgdata) ;
      SetSystemMenu (hwnd) ;
      if (pbetdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (pbetdlgdata->hwndHelp, hwnd) ;
      WinLoadString (pbetdlgdata->hab,
                     NULLHANDLE,
                     IDS_SEPARATOR,
                     sizeof (pszString),
                     pszString) ;
      strcat (pbetdlgdata->pszApplName, pszString) ;
      WinLoadString (pbetdlgdata->hab,
                     NULLHANDLE,
                     pbetdlgdata->ulBetName,
                     sizeof (pszString),
                     pszString) ;
      strcat (pbetdlgdata->pszApplName, pszString) ;
      WinSetWindowText (hwnd, pbetdlgdata->pszApplName) ;
      WinLoadString (pbetdlgdata->hab,
                     NULLHANDLE,
                     IDS_CURRENCY,
                     sizeof (pszString),
                     pszString) ;
      _ltoa (pbetdlgdata->lBank, pszTempString, 10) ;
      strcat (pszString, pszTempString) ;
      WinSetDlgItemText (hwnd, IDD_BANKAMOUNT, pszString) ;
      WinSetDlgItemText (hwnd,
                         IDD_BETAMOUNT,
                         pbetdlgdata->lDefaultBet ?
                         _ltoa (pbetdlgdata->lDefaultBet, pszTempString, 10) :
                         "") ;
      pbetdlgdata->hwndBetAmount = WinWindowFromID (hwnd, IDD_BETAMOUNT) ;
      pbetdlgdata->hwndOddsAmount = WinWindowFromID (hwnd, IDD_ODDSAMOUNT) ;
      if ((pbetdlgdata->sPoint) && (pbetdlgdata->fLineBet))
      {
        WinSetDlgItemText (hwnd,
                           IDD_ODDSAMOUNT,
                           pbetdlgdata->lDefaultOdds ?
                           _ltoa (pbetdlgdata->lDefaultOdds, pszTempString, 10) :
                           "") ;
        WinSendDlgItemMsg (hwnd,
                           IDD_ODDSAMOUNT,
                           EM_SETTEXTLIMIT,
                           MPFROM2SHORT (DEF_BETLEN, 0),
                           NULL) ;
        WinSendDlgItemMsg (hwnd,
                           IDD_ODDSAMOUNT,
                           EM_SETSEL,
                           MPFROM2SHORT (0, DEF_BETLEN),
                           NULL) ;
        WinEnableControl (hwnd, IDD_BETTEXT, FALSE) ;
        WinEnableControl (hwnd, IDD_BETAMOUNT, FALSE) ;
        hwndFocus = pbetdlgdata->hwndOddsAmount ;
      }
      else
      {
        WinSendDlgItemMsg (hwnd,
                           IDD_BETAMOUNT,
                           EM_SETTEXTLIMIT,
                           MPFROM2SHORT (DEF_BETLEN, 0),
                           NULL) ;
        WinSendDlgItemMsg (hwnd,
                           IDD_BETAMOUNT,
                           EM_SETSEL,
                           MPFROM2SHORT (0, DEF_BETLEN),
                           NULL) ;
        WinEnableControl (hwnd, IDD_ODDSTEXT, FALSE) ;
        WinEnableControl (hwnd, IDD_ODDSAMOUNT, FALSE) ;
        hwndFocus = pbetdlgdata->hwndBetAmount ;
      }
      WinSetFocus (HWND_DESKTOP, hwndFocus) ;
      WinSubclassWindow (hwndFocus, wpNumericEntry) ;
      mres = (MRESULT) TRUE ;
      break ;

    case WM_COMMAND:
      pbetdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      switch (SHORT1FROMMP (mp1))
      {
        case DID_OK:
          mres = (MRESULT) TRUE ;
          if ((pbetdlgdata->sPoint) && (pbetdlgdata->fLineBet))
          {
            if (!WinQueryDlgItemText (hwnd,
                                      IDD_ODDSAMOUNT,
                                      sizeof (pszTempString),
                                      pszTempString))
              pbetdlgdata->lOdds = 0 ;
            else
              pbetdlgdata->lOdds = atol (pszTempString) ;
            if ((pbetdlgdata->lOdds < pbetdlgdata->lMinBet) &&
                (pbetdlgdata->lOdds))
              EntryError (pbetdlgdata->hab,
                          hwnd,
                          pbetdlgdata->hwndOddsAmount,
                          pbetdlgdata->ulBetName,
                          IDD_ODDSAMOUNT,
                          IDS_MINBET,
                          pbetdlgdata->lMinBet,
                          pbetdlgdata->lDefaultOdds) ;
            else if (pbetdlgdata->lOdds > (pbetdlgdata->lBank + pbetdlgdata->lOldOdds))
              EntryError (pbetdlgdata->hab,
                          hwnd,
                          pbetdlgdata->hwndOddsAmount,
                          pbetdlgdata->ulBetName,
                          IDD_ODDSAMOUNT,
                          IDS_NOTENOUGH,
                          pbetdlgdata->lBank + pbetdlgdata->lOldOdds,
                          pbetdlgdata->lDefaultOdds) ;
            else if (pbetdlgdata->lOdds > pbetdlgdata->lMaxOdds)
              EntryError (pbetdlgdata->hab,
                          hwnd,
                          pbetdlgdata->hwndOddsAmount,
                          pbetdlgdata->ulBetName,
                          IDD_ODDSAMOUNT,
                          IDS_MAXODDS,
                          pbetdlgdata->lMaxOdds,
                          pbetdlgdata->lDefaultOdds) ;
            else
              fGoodData = TRUE ;
          }
          else
          {
            if (!WinQueryDlgItemText (hwnd,
                                      IDD_BETAMOUNT,
                                      sizeof (pszTempString),
                                      pszTempString))
              pbetdlgdata->lBet = 0 ;
            else
              pbetdlgdata->lBet = atol (pszTempString) ;
            if ((pbetdlgdata->lBet < pbetdlgdata->lMinBet) &&
                (pbetdlgdata->lBet))
              EntryError (pbetdlgdata->hab,
                          hwnd,
                          pbetdlgdata->hwndBetAmount,
                          pbetdlgdata->ulBetName,
                          IDD_BETAMOUNT,
                          IDS_MINBET,
                          pbetdlgdata->lMinBet,
                          pbetdlgdata->lDefaultBet) ;
            else if (pbetdlgdata->lBet > (pbetdlgdata->lBank + pbetdlgdata->lOldBet))
              EntryError (pbetdlgdata->hab,
                          hwnd,
                          pbetdlgdata->hwndBetAmount,
                          pbetdlgdata->ulBetName,
                          IDD_BETAMOUNT,
                          IDS_NOTENOUGH,
                          pbetdlgdata->lBank + pbetdlgdata->lOldBet,
                          pbetdlgdata->lDefaultBet) ;
            else if (pbetdlgdata->lBet > pbetdlgdata->lMaxBet)
              EntryError (pbetdlgdata->hab,
                          hwnd,
                          pbetdlgdata->hwndBetAmount,
                          pbetdlgdata->ulBetName,
                          IDD_BETAMOUNT,
                          IDS_MAXBET,
                          pbetdlgdata->lMaxBet,
                          pbetdlgdata->lDefaultBet) ;
            else
              fGoodData = TRUE ;
          }
          if (fGoodData)
          {
            mres = (MRESULT) FALSE ;
            WinDismissDlg (hwnd, TRUE) ;
          }
          break ;

        case DID_CANCEL:
          WinDismissDlg (hwnd, FALSE) ;
          break ;
      }
      break ;

    case WM_DESTROY:
      pbetdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      if (pbetdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (NULLHANDLE, hwnd) ;
      break ;

    default:
      mres = WinDefDlgProc (hwnd, msg, mp1, mp2) ;
      break ;
  }
  return mres ;
}

/****************************************************************/
/*  wpNewDlgProc for the new dialog box                         */
/****************************************************************/

MRESULT EXPENTRY wpNewDlgProc (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  MRESULT     mres = (MRESULT) FALSE ;
  PNEWDLGDATA pnewdlgdata ;
  CHAR        pszString[BUFFERLEN] ;

  switch (msg)
  {
    case WM_INITDLG:
      pnewdlgdata = PVOIDFROMMP (mp2) ;
      WinSetWindowPtr (hwnd, QWL_USER, pnewdlgdata) ;
      SetSystemMenu (hwnd) ;
      if (pnewdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (pnewdlgdata->hwndHelp, hwnd) ;
      WinLoadString (pnewdlgdata->hab,
                     NULLHANDLE,
                     IDS_SEPARATOR,
                     sizeof (pszString),
                     pszString) ;
      strcat (pnewdlgdata->pszApplName, pszString) ;
      WinLoadString (pnewdlgdata->hab,
                     NULLHANDLE,
                     IDS_NEWTITLE,
                     sizeof (pszString),
                     pszString) ;
      strcat (pnewdlgdata->pszApplName, pszString) ;
      WinSetWindowText (hwnd, pnewdlgdata->pszApplName) ;
      WinSetDlgItemText (hwnd,
                         IDD_NEWAMOUNT,
                         pnewdlgdata->lDefaultMarker ?
                         _ltoa (pnewdlgdata->lDefaultMarker, pszString, 10) :
                         "") ;
      WinSendDlgItemMsg (hwnd,
                         IDD_NEWAMOUNT,
                         EM_SETTEXTLIMIT,
                         MPFROM2SHORT (DEF_BETLEN, 0),
                         NULL) ;
      WinSendDlgItemMsg (hwnd,
                         IDD_NEWAMOUNT,
                         EM_SETSEL,
                         MPFROM2SHORT (0, DEF_BETLEN),
                         NULL) ;
      pnewdlgdata->hwndNewAmount = WinWindowFromID (hwnd, IDD_NEWAMOUNT) ;
      WinSubclassWindow (pnewdlgdata->hwndNewAmount, wpNumericEntry) ;
      break ;

    case WM_COMMAND:
      pnewdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      switch (SHORT1FROMMP (mp1))
      {
        case DID_OK:
          mres = (MRESULT) TRUE ;
          if (!WinQueryDlgItemText (hwnd,
                                    IDD_NEWAMOUNT,
                                    sizeof (pszString),
                                    pszString))
            pnewdlgdata->lMarker = 0 ;
          else
            pnewdlgdata->lMarker = atol (pszString) ;
          if (pnewdlgdata->lMarker < pnewdlgdata->lMinBet)
            EntryError (pnewdlgdata->hab,
                        hwnd,
                        pnewdlgdata->hwndNewAmount,
                        IDS_NEWTITLE,
                        IDD_NEWAMOUNT,
                        IDS_NEWMINBET,
                        pnewdlgdata->lMinBet,
                        pnewdlgdata->lDefaultMarker) ;
          else if (pnewdlgdata->lMarker > pnewdlgdata->lMaxMarker)
            EntryError (pnewdlgdata->hab,
                        hwnd,
                        pnewdlgdata->hwndNewAmount,
                        IDS_NEWTITLE,
                        IDD_NEWAMOUNT,
                        IDS_MAXMARKER,
                        pnewdlgdata->lMaxMarker,
                        pnewdlgdata->lDefaultMarker) ;
          else
          {
            mres = (MRESULT) FALSE ;
            WinDismissDlg (hwnd, TRUE) ;
          }
          break ;

        case DID_CANCEL:
          WinDismissDlg (hwnd, FALSE) ;
          break ;
      }
      break ;

    case WM_DESTROY:
      pnewdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      if (pnewdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (NULLHANDLE, hwnd) ;
      break ;

    default:
      mres = WinDefDlgProc (hwnd, msg, mp1, mp2) ;
      break ;
  }
  return mres ;
}

/****************************************************************/
/*  wpSettingsDlgProc for the settings dialog box               */
/****************************************************************/

MRESULT EXPENTRY wpSettingsDlgProc (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  MRESULT          mres = (MRESULT) FALSE ;
  PSETTINGSDLGDATA psettingsdlgdata ;
  CHAR             pszString[BUFFERLEN] ;

  switch (msg)
  {
    case WM_INITDLG:
      psettingsdlgdata = PVOIDFROMMP (mp2) ;
      WinSetWindowPtr (hwnd, QWL_USER, psettingsdlgdata) ;
      SetSystemMenu (hwnd) ;
      if (psettingsdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (psettingsdlgdata->hwndHelp, hwnd) ;
      WinLoadString (psettingsdlgdata->hab,
                     NULLHANDLE,
                     IDS_SEPARATOR,
                     sizeof (pszString),
                     pszString) ;
      strcat (psettingsdlgdata->pszApplName, pszString) ;
      WinLoadString (psettingsdlgdata->hab,
                     NULLHANDLE,
                     IDS_SETTINGSTITLE,
                     sizeof (pszString),
                     pszString) ;
      strcat (psettingsdlgdata->pszApplName, pszString) ;
      WinSetWindowText (hwnd, psettingsdlgdata->pszApplName) ;
      InitSettingsDlg (hwnd, &psettingsdlgdata->settings) ;
      psettingsdlgdata->hwndMinAmount = WinWindowFromID (hwnd, IDD_MINBET) ;
      WinSubclassWindow (psettingsdlgdata->hwndMinAmount, wpNumericEntry) ;
      psettingsdlgdata->hwndMaxAmount = WinWindowFromID (hwnd, IDD_MAXBET) ;
      WinSubclassWindow (psettingsdlgdata->hwndMaxAmount, wpNumericEntry) ;
      psettingsdlgdata->hwndDefAmount = WinWindowFromID (hwnd, IDD_DEFAULTBET) ;
      WinSubclassWindow (psettingsdlgdata->hwndDefAmount, wpNumericEntry) ;
      break ;

    case WM_COMMAND:
      psettingsdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      switch (SHORT1FROMMP (mp1))
      {
        case DID_OK:
          mres = (MRESULT) TRUE ;
          if (!WinQueryDlgItemText (hwnd,
                                    IDD_MINBET,
                                    sizeof (pszString),
                                    pszString))
            psettingsdlgdata->settings.lMinBet = 0 ;
          else
            psettingsdlgdata->settings.lMinBet = atol (pszString) ;
          if (!WinQueryDlgItemText (hwnd,
                                    IDD_MAXBET,
                                    sizeof (pszString),
                                    pszString))
            psettingsdlgdata->settings.lMaxBet = 0 ;
          else
            psettingsdlgdata->settings.lMaxBet = atol (pszString) ;
          if (!WinQueryDlgItemText (hwnd,
                                    IDD_DEFAULTBET,
                                    sizeof (pszString),
                                    pszString))
            psettingsdlgdata->settings.lDefaultBet = 0 ;
          else
            psettingsdlgdata->settings.lDefaultBet = atol (pszString) ;
          if (psettingsdlgdata->settings.lMinBet < 1)
            EntryError (psettingsdlgdata->hab,
                        hwnd,
                        psettingsdlgdata->hwndMinAmount,
                        IDS_SETTINGSTITLE,
                        IDD_MINBET,
                        IDS_ABSOLUTEMINBET,
                        0,
                        psettingsdlgdata->lOldMinBet) ;
          else if (psettingsdlgdata->settings.lMaxBet > DEF_MAXBET)
            EntryError (psettingsdlgdata->hab,
                        hwnd,
                        psettingsdlgdata->hwndMaxAmount,
                        IDS_SETTINGSTITLE,
                        IDD_MAXBET,
                        IDS_ABSOLUTEMAXBET,
                        DEF_MAXBET,
                        psettingsdlgdata->lOldMaxBet) ;
          else if (psettingsdlgdata->settings.lMinBet >
                   psettingsdlgdata->settings.lMaxBet)
          {
            EntryError (psettingsdlgdata->hab,
                        hwnd,
                        psettingsdlgdata->hwndMinAmount,
                        IDS_SETTINGSTITLE,
                        IDD_MINBET,
                        IDS_MINMAX,
                        0,
                        psettingsdlgdata->lOldMinBet) ;
            WinSetDlgItemText (hwnd,
                               IDD_MAXBET,
                               psettingsdlgdata->lOldMaxBet ?
                               _ltoa (psettingsdlgdata->lOldMaxBet, pszString, 10) :
                               "") ;
            WinSendDlgItemMsg (hwnd,
                               IDD_MAXBET,
                               EM_SETSEL,
                               MPFROM2SHORT (0, DEF_BETLEN),
                               NULL) ;
          }
          else if ((psettingsdlgdata->settings.lDefaultBet <
                   psettingsdlgdata->settings.lMinBet) &&
                   (psettingsdlgdata->settings.lDefaultBet))
            EntryError (psettingsdlgdata->hab,
                        hwnd,
                        psettingsdlgdata->hwndDefAmount,
                        IDS_SETTINGSTITLE,
                        IDD_DEFAULTBET,
                        IDS_DEFMIN,
                        0,
                        psettingsdlgdata->lOldDefaultBet) ;
          else if (psettingsdlgdata->settings.lDefaultBet >
                   psettingsdlgdata->settings.lMaxBet)
            EntryError (psettingsdlgdata->hab,
                        hwnd,
                        psettingsdlgdata->hwndDefAmount,
                        IDS_SETTINGSTITLE,
                        IDD_DEFAULTBET,
                        IDS_DEFMAX,
                        0,
                        psettingsdlgdata->lOldDefaultBet) ;
          else
          {
            mres = (MRESULT) FALSE ;
            psettingsdlgdata->settings.fBetsOnComeOut = WinQueryButtonCheckstate (hwnd, IDD_BETSONCOME) ;
            psettingsdlgdata->settings.fAutoOdds = WinQueryButtonCheckstate (hwnd, IDD_AUTOODDS) ;
            psettingsdlgdata->settings.fGuidoExtracts = WinQueryButtonCheckstate (hwnd, IDD_GUIDO) ;
            if (WinQueryButtonCheckstate (hwnd, IDD_SINGLE))
              psettingsdlgdata->settings.sOddsMultiple =  1 ;
            else
              psettingsdlgdata->settings.sOddsMultiple =  2 ;
            WinDismissDlg (hwnd, TRUE) ;
          }
          break ;

        case DID_CANCEL:
          WinDismissDlg (hwnd, FALSE) ;
          break ;

        case IDD_DEFAULT:
          InitSettings (&psettingsdlgdata->settings) ;
          InitSettingsDlg (hwnd, &psettingsdlgdata->settings) ;
          break ;
      }
      break ;

    case WM_DESTROY:
      psettingsdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      if (psettingsdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (NULLHANDLE, hwnd) ;
      break ;

    default:
      mres = WinDefDlgProc (hwnd, msg, mp1, mp2) ;
      break ;
  }
  return mres ;
}

/****************************************************************/
/*  wpMarkerDlgProc for the marker dialog box                   */
/****************************************************************/

MRESULT EXPENTRY wpMarkerDlgProc (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  MRESULT        mres = (MRESULT) FALSE ;
  SHORT          sMult ;
  BOOL           fPayBack ;
  PMARKERDLGDATA pmarkerdlgdata ;
  CHAR           pszString[BUFFERLEN] ;
  CHAR           pszTempString[BUFFERLEN] ;

  switch (msg)
  {
    case WM_INITDLG:
      pmarkerdlgdata = PVOIDFROMMP (mp2) ;
      WinSetWindowPtr (hwnd, QWL_USER, pmarkerdlgdata) ;
      SetSystemMenu (hwnd) ;
      if (pmarkerdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (pmarkerdlgdata->hwndHelp, hwnd) ;
      WinLoadString (pmarkerdlgdata->hab,
                     NULLHANDLE,
                     IDS_SEPARATOR,
                     sizeof (pszString),
                     pszString) ;
      strcat (pmarkerdlgdata->pszApplName, pszString) ;
      WinLoadString (pmarkerdlgdata->hab,
                     NULLHANDLE,
                     IDS_MARKERTITLE,
                     sizeof (pszString),
                     pszString) ;
      strcat (pmarkerdlgdata->pszApplName, pszString) ;
      WinSetWindowText (hwnd, pmarkerdlgdata->pszApplName) ;
      WinLoadString (pmarkerdlgdata->hab,
                     NULLHANDLE,
                     IDS_CURRENCY,
                     sizeof (pszString),
                     pszString) ;
      _ltoa (pmarkerdlgdata->lMarker, pszTempString, 10) ;
      strcat (pszString, pszTempString) ;
      WinSetDlgItemText (hwnd, IDD_MARKERAMOUNT, pszString) ;
      WinLoadString (pmarkerdlgdata->hab,
                     NULLHANDLE,
                     IDS_CURRENCY,
                     sizeof (pszString),
                     pszString) ;
      _ltoa (pmarkerdlgdata->lBank, pszTempString, 10) ;
      strcat (pszString, pszTempString) ;
      WinSetDlgItemText (hwnd, IDD_BANKAMOUNT, pszString) ;
      if (!pmarkerdlgdata->lBank)
      {
        WinEnableControl (hwnd, IDD_PAYBACK, FALSE) ;
        WinCheckButton (hwnd, IDD_BORROW, TRUE) ;
      }
      else if (pmarkerdlgdata->lMarker >= pmarkerdlgdata->lMaxMarker)
      {
        WinEnableControl (hwnd, IDD_BORROW, FALSE) ;
        WinCheckButton (hwnd, IDD_PAYBACK, TRUE) ;
      }
      else
        WinCheckButton (hwnd, IDD_PAYBACK, TRUE) ;
      WinSetDlgItemText (hwnd,
                         IDD_CHANGE,
                         pmarkerdlgdata->lDefaultChange ?
                         _ltoa (pmarkerdlgdata->lDefaultChange, pszString, 10)
                         : "") ;
      WinSendDlgItemMsg (hwnd,
                         IDD_CHANGE,
                         EM_SETTEXTLIMIT,
                         MPFROM2SHORT (DEF_BETLEN, 0),
                         NULL) ;
      WinSendDlgItemMsg (hwnd,
                         IDD_CHANGE,
                         EM_SETSEL,
                         MPFROM2SHORT (0, DEF_BETLEN),
                         NULL) ;
      pmarkerdlgdata->hwndAmount = WinWindowFromID (hwnd, IDD_CHANGE) ;
      WinSetFocus (HWND_DESKTOP, pmarkerdlgdata->hwndAmount) ;
      WinSubclassWindow (pmarkerdlgdata->hwndAmount, wpNumericEntry) ;
      mres = (MRESULT) TRUE ;
      break ;

    case WM_COMMAND:
      pmarkerdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      switch (SHORT1FROMMP (mp1))
      {
        case DID_OK:
          mres = (MRESULT) TRUE ;
          if (!WinQueryDlgItemText (hwnd,
                                    IDD_CHANGE,
                                    sizeof (pszString),
                                    pszString))
            pmarkerdlgdata->lChange = 0 ;
          else
            pmarkerdlgdata->lChange = atol (pszString) ;
          fPayBack = (WinQueryButtonCheckstate (hwnd, IDD_PAYBACK)) ;
          if ((fPayBack) && (pmarkerdlgdata->lChange > pmarkerdlgdata->lBank))
            EntryError (pmarkerdlgdata->hab,
                        hwnd,
                        pmarkerdlgdata->hwndAmount,
                        IDS_MARKERTITLE,
                        IDD_CHANGE,
                        IDS_NOTENOUGH,
                        pmarkerdlgdata->lBank,
                        pmarkerdlgdata->lDefaultChange) ;
          else if ((!fPayBack) && ((pmarkerdlgdata->lChange +
                                    pmarkerdlgdata->lMarker) >
                                    pmarkerdlgdata->lMaxMarker))
            EntryError (pmarkerdlgdata->hab,
                        hwnd,
                        pmarkerdlgdata->hwndAmount,
                        IDS_MARKERTITLE,
                        IDD_CHANGE,
                        IDS_MAXMARKER,
                        pmarkerdlgdata->lMaxMarker,
                        pmarkerdlgdata->lDefaultChange) ;
          else
          {
            mres = (MRESULT) FALSE ;
            sMult = (SHORT) (fPayBack ? -1 : 1) ;
            pmarkerdlgdata->lMarker += (pmarkerdlgdata->lChange * sMult) ;
            pmarkerdlgdata->lBank += (pmarkerdlgdata->lChange * sMult) ;
            WinDismissDlg (hwnd, TRUE) ;
          }
          break ;

        case DID_CANCEL:
          WinDismissDlg (hwnd, FALSE) ;
          break ;
      }
      break ;

    case WM_DESTROY:
      pmarkerdlgdata = WinQueryWindowPtr (hwnd, 0) ;
      if (pmarkerdlgdata->hwndHelp != NULLHANDLE)
        WinAssociateHelpInstance (NULLHANDLE, hwnd) ;
      break ;

    default:
      mres = WinDefDlgProc (hwnd, msg, mp1, mp2) ;
      break ;
  }
  return mres ;
}

/****************************************************************/
/*  wpNumericEntry subclasses to allow only numeric entry       */
/****************************************************************/

MRESULT EXPENTRY wpNumericEntry (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  USHORT    usFlags ;
  USHORT    usChar  ;
  CLASSINFO clinfo  ;

  WinQueryClassInfo (WinQueryAnchorBlock (hwnd), WC_ENTRYFIELD, &clinfo) ;
  switch (msg)
  {
    case WM_CHAR:
      usFlags = SHORT1FROMMP (mp1) ;
      usChar = SHORT1FROMMP (mp2) ;
      if ((usFlags & (USHORT) KC_CHAR) && !(usFlags & (USHORT) KC_KEYUP))
        if ((usChar < (USHORT) KEY_0) || (usChar > (USHORT) KEY_9))
          switch (usChar)
          {
            case KEY_TAB:
            case KEY_BSPACE:
            case KEY_ENTER:
              break ;
            default:
              WinAlarm (HWND_DESKTOP, WA_ERROR) ;
              return (MRESULT) TRUE ;
          }
      break ;
  }
  return (MRESULT) (clinfo.pfnWindowProc) (hwnd, msg, mp1, mp2) ;
}
