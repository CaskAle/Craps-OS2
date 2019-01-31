/****************************************************************/
/*  LOGIC.C contains the actual game logic for craps            */
/****************************************************************/

#define INCL_WINPOINTERS
#define INCL_WINTIMER
#define INCL_GPITRANSFORMS

#include <os2.h>
#include <stdlib.h>
#include "define.h"
#include "craps.h"
#include "logic.h"
#include "utility.h"
#include "graphics.h"

/****************************************************************/
/* PlayGame this is the actual game playing logic               */
/****************************************************************/

VOID PlayGame (HWND hwnd, PCLIENTDATA pclientdata)
{
  LONG lWinnings = 0 ;
  SHORT sOldPoint ;
  SHORT sOldComePoint ;
  BOOL fComeOut ;
  BOOL fBetsOn = FALSE ;
  
  fComeOut = (BOOL) (((!pclientdata->dicedata.sPoint) &&
              (pclientdata->betdata.lnbetPass.lLine ||
              pclientdata->betdata.lnbetDontPass.lLine)) ? TRUE : FALSE) ;
  if ((pclientdata->settings.fBetsOnComeOut) || (!fComeOut))
    fBetsOn = TRUE ;
  sOldPoint = pclientdata->dicedata.sPoint ;
  sOldComePoint = pclientdata->dicedata.sComePoint ;
  RollDice (pclientdata->hps, pclientdata->hpsMemory, &pclientdata->dicedata) ;
  if (pclientdata->betdata.lnbetPass.lLine ||
      pclientdata->betdata.lnbetDontPass.lLine)
    lWinnings += LineBet (hwnd,
                          pclientdata->hab,
                           pclientdata->dicedata.sRoll,
                          &pclientdata->dicedata.sPoint,
                          &pclientdata->betdata.lnbetPass,
                          &pclientdata->betdata.lnbetDontPass,
                          &pclientdata->betdata.lBank,
                          fBetsOn,
                          IDS_PASS,
                          IDS_DONTPASS) ;
  if (pclientdata->betdata.lnbetCome.lLine ||
      pclientdata->betdata.lnbetDontCome.lLine)
    lWinnings += LineBet (hwnd,
                          pclientdata->hab,
                          pclientdata->dicedata.sRoll,
                          &pclientdata->dicedata.sComePoint,
                          &pclientdata->betdata.lnbetCome,
                          &pclientdata->betdata.lnbetDontCome,
                          &pclientdata->betdata.lBank,
                          fBetsOn,
                          IDS_COME,
                          IDS_DONTCOME) ;
  if (sOldPoint && !pclientdata->dicedata.sPoint)  
    ClearMarker (pclientdata->hps, sOldPoint) ;
  if (sOldComePoint && !pclientdata->dicedata.sComePoint)  
    ClearMarker (pclientdata->hps, sOldComePoint) ;
  if (!sOldPoint && pclientdata->dicedata.sPoint)  
    SetMarker (pclientdata->hps, pclientdata->dicedata.sPoint, FALSE) ;
  if (!sOldComePoint && pclientdata->dicedata.sComePoint)  
    SetMarker (pclientdata->hps, pclientdata->dicedata.sComePoint, TRUE) ;
  if (fBetsOn)
  {
    if (pclientdata->betdata.lPlaceFour)
      lWinnings += NumberBeforeSeven (hwnd,
                                      pclientdata->hab,
                                      pclientdata->dicedata.sRoll,
                                      4,
                                      &pclientdata->betdata.lPlaceFour,
                                      &pclientdata->betdata.lBank,
                                      9,
                                      5,
                                      IDS_PLACEFOUR) ;
    if (pclientdata->betdata.lPlaceFive)
      lWinnings += NumberBeforeSeven (hwnd,
                                      pclientdata->hab,
                                      pclientdata->dicedata.sRoll,
                                      5,
                                      &pclientdata->betdata.lPlaceFive,
                                      &pclientdata->betdata.lBank,
                                      7,
                                      5,
                                      IDS_PLACEFIVE) ;
    if (pclientdata->betdata.lPlaceSix)
      lWinnings += NumberBeforeSeven (hwnd,
                                      pclientdata->hab,
                                      pclientdata->dicedata.sRoll,
                                      6,
                                      &pclientdata->betdata.lPlaceSix,
                                      &pclientdata->betdata.lBank,
                                      7,
                                      6,
                                      IDS_PLACESIX) ;
    if (pclientdata->betdata.lPlaceEight)
      lWinnings += NumberBeforeSeven (hwnd,
                                      pclientdata->hab,
                                      pclientdata->dicedata.sRoll,
                                      8,
                                      &pclientdata->betdata.lPlaceEight,
                                      &pclientdata->betdata.lBank,
                                      7,
                                      6,
                                      IDS_PLACEEIGHT) ;
    if (pclientdata->betdata.lPlaceNine)
      lWinnings += NumberBeforeSeven (hwnd,
                                      pclientdata->hab,
                                      pclientdata->dicedata.sRoll,
                                      9,
                                      &pclientdata->betdata.lPlaceNine,
                                      &pclientdata->betdata.lBank,
                                      7,
                                      5,
                                      IDS_PLACENINE) ;
    if (pclientdata->betdata.lPlaceTen)
      lWinnings += NumberBeforeSeven (hwnd,
                                      pclientdata->hab,
                                      pclientdata->dicedata.sRoll,
                                      10,
                                      &pclientdata->betdata.lPlaceTen,
                                      &pclientdata->betdata.lBank,
                                      9,
                                      5,
                                      IDS_PLACETEN) ;
  }
  if (pclientdata->betdata.lAnySeven)
    lWinnings += NumberCheck (hwnd,
                              pclientdata->hab,
                              pclientdata->dicedata.sRoll,
                              7,
                              &pclientdata->betdata.lAnySeven,
                              &pclientdata->betdata.lBank,
                              4,
                              IDS_ANYSEVEN) ;
  if (pclientdata->betdata.lAnyCraps)
    lWinnings += AnyCraps (hwnd,
                           pclientdata->hab,
                           pclientdata->dicedata.sRoll,
                           &pclientdata->betdata.lAnyCraps,
                           &pclientdata->betdata.lBank) ;
  if (pclientdata->betdata.lTwo)
    lWinnings += NumberCheck (hwnd,
                              pclientdata->hab,
                              pclientdata->dicedata.sRoll,
                              2,
                              &pclientdata->betdata.lTwo,
                              &pclientdata->betdata.lBank,
                              30,
                              IDS_TWO) ;
  if (pclientdata->betdata.lThree)
    lWinnings += NumberCheck (hwnd,
                              pclientdata->hab,
                              pclientdata->dicedata.sRoll,
                              3,
                              &pclientdata->betdata.lThree,
                              &pclientdata->betdata.lBank,
                              15,
                              IDS_THREE) ;
  if (pclientdata->betdata.lEleven)
    lWinnings += NumberCheck (hwnd,
                              pclientdata->hab,
                              pclientdata->dicedata.sRoll,
                              11,
                              &pclientdata->betdata.lEleven,
                              &pclientdata->betdata.lBank,
                              15,
                              IDS_ELEVEN) ;
  if (pclientdata->betdata.lTwelve)
    lWinnings += NumberCheck (hwnd,
                              pclientdata->hab,
                              pclientdata->dicedata.sRoll,
                              12,
                              &pclientdata->betdata.lTwelve,
                              &pclientdata->betdata.lBank,
                              30,
                              IDS_TWELVE) ;
  if (pclientdata->betdata.lHardFour)
    lWinnings += HardWays (hwnd,
                           pclientdata->hab,
                           &pclientdata->dicedata,
                           2,
                           &pclientdata->betdata.lHardFour,
                           &pclientdata->betdata.lBank,
                           7,
                           IDS_HARDFOUR) ;
  if (pclientdata->betdata.lHardSix)
    lWinnings += HardWays (hwnd,
                           pclientdata->hab,
                           &pclientdata->dicedata,
                           3,
                           &pclientdata->betdata.lHardSix,
                           &pclientdata->betdata.lBank,
                           9,
                           IDS_HARDSIX) ;
  if (pclientdata->betdata.lHardEight)
    lWinnings += HardWays (hwnd,
                           pclientdata->hab,
                           &pclientdata->dicedata,
                           4,
                           &pclientdata->betdata.lHardEight,
                           &pclientdata->betdata.lBank,
                           9,
                           IDS_HARDEIGHT) ;
  if (pclientdata->betdata.lHardTen)
    lWinnings += HardWays (hwnd,
                           pclientdata->hab,
                           &pclientdata->dicedata,
                           5,
                           &pclientdata->betdata.lHardTen,
                           &pclientdata->betdata.lBank,
                           7,
                           IDS_HARDTEN) ;
  if (pclientdata->betdata.lBigSix)
    lWinnings += NumberBeforeSeven (hwnd,
                                    pclientdata->hab,
                                    pclientdata->dicedata.sRoll,
                                    6,
                                    &pclientdata->betdata.lBigSix,
                                    &pclientdata->betdata.lBank,
                                    1,
                                    1,
                                    IDS_BIGSIX) ;
  if (pclientdata->betdata.lBigEight)
    lWinnings += NumberBeforeSeven (hwnd,
                                    pclientdata->hab,
                                    pclientdata->dicedata.sRoll,
                                    8,
                                    &pclientdata->betdata.lBigEight,
                                    &pclientdata->betdata.lBank,
                                    1,
                                    1,
                                    IDS_BIGEIGHT) ;
  if (pclientdata->betdata.lField)
    lWinnings += FieldBet (hwnd,
                           pclientdata->hab,
                           pclientdata->dicedata.sRoll,
                           &pclientdata->betdata.lField,
                           &pclientdata->betdata.lBank) ;
  if ((pclientdata->settings.fGuidoExtracts) &&
      (pclientdata->betdata.lMarker) &&
      (lWinnings))
    Guido (hwnd,
           pclientdata->hab,
           &pclientdata->betdata.lBank,
           &pclientdata->betdata.lMarker,
           lWinnings) ;
  return ;
}

/****************************************************************/
/* RollDice is the dice rolling function                        */
/****************************************************************/

VOID RollDice (HPS hps, HPS hpsMemory, PDICEDATA pdicedata)
{
  SHORT  sRep ;
  SHORT  sLoop ;

  WinSetPointer (HWND_DESKTOP, 
                 WinQuerySysPointer (HWND_DESKTOP, SPTR_WAIT, FALSE)) ;
  srand (WinGetCurrentTime (NULLHANDLE)) ;
  sLoop = (SHORT) (rand () % 11 + 4) ;
  for (sRep = 1; sRep <= sLoop; sRep++)
  {
    EraseDice (hps, hpsMemory, pdicedata) ;
    DosBeep (40, 5) ;
    pdicedata->sDie1 = (SHORT) (rand () % 6 + 1) ;
    pdicedata->ptlDie1.x = (SHORT) (rand () % (TBLUNIT * (TBLHORZ - 2))) ;
    pdicedata->ptlDie1.y = (SHORT) (rand () % (TBLUNIT * (TBLVERT - 2))) ;
    pdicedata->sDie2 = (SHORT) (rand () % 6 + 1) ;
    pdicedata->ptlDie2.x = (SHORT) (rand () % (TBLUNIT * (TBLHORZ - 2))) ;
    pdicedata->ptlDie2.y = (SHORT) (rand () % (TBLUNIT * (TBLVERT - 2))) ;
    DrawDice (hps, hpsMemory, pdicedata) ;
    DosBeep (25, 5) ;
  }
  EraseDice (hps, hpsMemory, pdicedata) ;
  pdicedata->sDie1 = (SHORT) (rand () % 6 + 1) ;
  pdicedata->ptlDie1.x = DEF_DIE1POSX ;
  pdicedata->ptlDie1.y = DEF_DIEPOSY ;
  pdicedata->sDie2 = (SHORT) (rand () % 6 + 1) ;
  pdicedata->ptlDie2.x = DEF_DIE2POSX ;
  pdicedata->ptlDie2.y = DEF_DIEPOSY ;
  DrawDice (hps, hpsMemory, pdicedata) ;
  pdicedata->sRoll = (SHORT) (pdicedata->sDie1 + pdicedata->sDie2) ;
  WinSetPointer (HWND_DESKTOP, 
                 WinQuerySysPointer (HWND_DESKTOP, SPTR_ARROW, FALSE)) ;
  return ;
}

/*********************************************************************/
/* NumberCheck will check to see if a certain number has been rolled */
/*********************************************************************/

LONG NumberCheck (HWND hwnd,
                  HAB hab,
                  SHORT sRoll,
                  SHORT sNumber,
                  PLONG plBet,
                  PLONG plBank,
                  SHORT sPayoff,
                  ULONG ulBetName)
{
  LONG lWinnings = 0 ;

  if (sRoll == sNumber)
  {
    lWinnings = *plBet * sPayoff ;
    *plBank += (*plBet + lWinnings) ;
    BetResult (hab, hwnd, ulBetName, *plBet, lWinnings, *plBank, TRUE) ;
  }
  else
  {
    lWinnings = *plBet * -1 ;
    BetResult (hab, hwnd, ulBetName, *plBet, *plBet, *plBank, FALSE) ;
  }
  *plBet = 0 ;
  return (lWinnings) ;
}

/*********************************************************************/
/* HardWays will check for one of the hardways bets                  */
/*********************************************************************/

LONG HardWays (HWND hwnd,
               HAB hab,
               PDICEDATA pdicedata,
               SHORT sNumber,
               PLONG plBet,
               PLONG plBank,
               SHORT sPayoff,
               ULONG ulBetName)
{
  LONG lWinnings = 0 ;

  if ((pdicedata->sDie1 == sNumber) && (pdicedata->sDie2 == sNumber))
  {
    lWinnings = *plBet * sPayoff ;
    *plBank += (*plBet + lWinnings) ;
    BetResult (hab, hwnd, ulBetName, *plBet, lWinnings, *plBank, TRUE) ;
    *plBet = 0 ;
  }
  else if ((pdicedata->sRoll == 7) || (pdicedata->sRoll == sNumber * 2))
  {
    lWinnings = *plBet * -1 ;
    BetResult (hab, hwnd, ulBetName, *plBet, *plBet, *plBank, FALSE) ;
    *plBet = 0 ;
  }
  return (lWinnings) ;
}

/*********************************************************************/
/* AnyCraps will check to see if any craps roll has been rolled      */
/*********************************************************************/

LONG AnyCraps (HWND hwnd, HAB hab, SHORT sRoll, PLONG plBet, PLONG plBank)
{
  LONG lWinnings = 0 ;

  if ((sRoll == 2) || (sRoll == 3) || (sRoll == 12))
  {
    lWinnings = *plBet * 7 ;
    *plBank += (*plBet + lWinnings) ;
    BetResult (hab, hwnd, IDS_ANYCRAPS, *plBet, lWinnings, *plBank, TRUE) ;
  }
  else
  {
    lWinnings = *plBet * -1 ;
    BetResult (hab, hwnd, IDS_ANYCRAPS, *plBet, *plBet, *plBank, FALSE) ;
  }
  *plBet = 0 ;
  return (lWinnings) ;
}

/*********************************************************************/
/* NumberBeforeSeven will check to see if a number is rolled before 7*/
/*********************************************************************/

LONG NumberBeforeSeven (HWND hwnd,
                        HAB hab,
                        SHORT sRoll,
                        SHORT sNumber,
                        PLONG plBet,
                        PLONG plBank,
                        SHORT sPayoff,
                        SHORT sTo,
                        ULONG ulBetName)
{
  LONG lWinnings = 0 ;

  if (sRoll == sNumber)
  {
    lWinnings = ((*plBet / sTo) * sPayoff) + (*plBet % sTo) ;
    *plBank += (*plBet + lWinnings) ;
    BetResult (hab, hwnd, ulBetName, *plBet, lWinnings, *plBank, TRUE) ;
    *plBet = 0 ;
  }
  else if (sRoll == 7)
  {
    lWinnings = *plBet * -1 ;
    BetResult (hab, hwnd, ulBetName, *plBet, *plBet, *plBank, FALSE) ;
    *plBet = 0 ;
  }
  return (lWinnings) ;
}

/*********************************************************************/
/* FieldBet will check to see if a field bet was rolled              */
/*********************************************************************/

LONG FieldBet (HWND hwnd, HAB hab, SHORT sRoll, PLONG plBet, PLONG plBank)
{
  LONG lWinnings = 0 ;

  switch (sRoll)
  {
    case 2:
      lWinnings = *plBet * 2 ;
      *plBank += (*plBet + lWinnings) ;
      BetResult (hab, hwnd, IDS_FIELD, *plBet, lWinnings, *plBank, TRUE) ;
      break ;

    case 3:
    case 4:
    case 9:
    case 10:
    case 11:
      lWinnings = *plBet ;
      *plBank += (*plBet + lWinnings) ;
      BetResult (hab, hwnd, IDS_FIELD, *plBet, lWinnings, *plBank, TRUE) ;
      break ;

    case 12:
      lWinnings = *plBet * 3 ;
      *plBank += (*plBet + lWinnings) ;
      BetResult (hab, hwnd, IDS_FIELD, *plBet, lWinnings, *plBank, TRUE) ;
      break ;

    default:
      lWinnings = *plBet * -1 ;
      BetResult (hab, hwnd, IDS_FIELD, *plBet, *plBet, *plBank, FALSE) ;
      break ;
  }
  *plBet = 0 ;
  return (lWinnings) ;
}

/*********************************************************************/
/* LineBet will check to see if there is a winner on a line bet      */
/*********************************************************************/

LONG LineBet (HWND hwnd,
              HAB hab,
              SHORT sRoll,
              PSHORT psPoint,
              PLINEBET plnbetRight,
              PLINEBET plnbetWrong,
              PLONG plBank,
              BOOL fBetsOn,
              ULONG ulRightBetName,
              ULONG ulWrongBetName)
{
  LONG lWinnings = 0 ;
  LONG lTotal = 0 ;

  if (!(*psPoint))
    switch (sRoll)
    {
      case 2:
      case 3:
        if (plnbetRight->lLine)
        {
          lTotal += (plnbetRight->lLine * -1) ;
          BetResult (hab,
                     hwnd,
                     ulRightBetName,
                     plnbetRight->lLine,
                     plnbetRight->lLine,
                     *plBank,
                     FALSE) ;
          plnbetRight->lLine = 0 ;
        }
        if (plnbetWrong->lLine)
        {
          lWinnings = plnbetWrong->lLine ;
          lTotal += lWinnings ;
          *plBank += (plnbetWrong->lLine + lWinnings) ;
          BetResult (hab,
                     hwnd,
                     ulWrongBetName,
                     plnbetWrong->lLine,
                     lWinnings,
                     *plBank,
                     TRUE) ;
          plnbetWrong->lLine = 0 ;
        }
        break ;

      case 7:
      case 11:
        if (plnbetRight->lLine)
        {
          lWinnings = plnbetRight->lLine ;
          lTotal += lWinnings ;
          *plBank += (plnbetRight->lLine + lWinnings) ;
          BetResult (hab,
                     hwnd,
                     ulRightBetName,
                     plnbetRight->lLine,
                     lWinnings,
                     *plBank,
                     TRUE) ;
          plnbetRight->lLine = 0 ;
        }
        if (plnbetWrong->lLine)
        {
          lTotal += (plnbetWrong->lLine * -1) ;
          BetResult (hab,
                     hwnd,
                     ulWrongBetName,
                     plnbetWrong->lLine,
                     plnbetWrong->lLine,
                     *plBank,
                     FALSE) ;
          plnbetWrong->lLine = 0 ;
        }
        break ;

      case 12:
        if (plnbetRight->lLine)
        {
          lTotal += (plnbetRight->lLine * -1) ;
          BetResult (hab,
                     hwnd,
                     ulRightBetName,
                     plnbetRight->lLine,
                     plnbetRight->lLine,
                     *plBank,
                     FALSE) ;
          plnbetRight->lLine = 0 ;
         }
        if (plnbetWrong->lLine)
         {
          *plBank += plnbetWrong->lLine ;
          lTotal += plnbetWrong->lLine ;
          BetResult (hab,
                     hwnd,
                     ulWrongBetName,
                     plnbetWrong->lLine,
                     0,
                     *plBank,
                     FALSE) ;
          plnbetWrong->lLine = 0 ;
        }
        break ;

      default:
        *psPoint = sRoll ;
        break ;
    }
  else
    if (sRoll == *psPoint)
    {
      if (plnbetRight->lLine)
      {
        lWinnings = plnbetRight->lLine ;
        if ((fBetsOn) && (plnbetRight->lOdds))
          lWinnings += CheckOdds (*psPoint, plnbetRight->lOdds, TRUE) ;
        lTotal += lWinnings ;
        *plBank += (plnbetRight->lLine + plnbetRight->lOdds + lWinnings) ;
        BetResult (hab,
                   hwnd,
                   ulRightBetName,
                   plnbetRight->lLine + plnbetRight->lOdds,
                   lWinnings,
                   *plBank,
                   TRUE) ;
        plnbetRight->lLine = 0 ;
        plnbetRight->lOdds = 0 ;
      }
      if (plnbetWrong->lLine)
      {
        lTotal += ((plnbetWrong->lLine + plnbetWrong->lOdds) * -1) ;
        BetResult (hab,
                   hwnd,
                   ulWrongBetName,
                   plnbetWrong->lLine + plnbetWrong->lOdds,
                   plnbetWrong->lLine + plnbetWrong->lOdds,
                   *plBank,
                   FALSE) ;
        plnbetWrong->lLine = 0 ;
        plnbetWrong->lOdds = 0 ;
      }
      *psPoint = 0 ;
    }
    else if (sRoll == 7)
    {
      if (plnbetRight->lLine)
      {
        lTotal += ((plnbetRight->lLine + plnbetRight->lOdds) * -1) ;
        BetResult (hab,
                   hwnd,
                   ulRightBetName,
                   plnbetRight->lLine + plnbetRight->lOdds,
                   plnbetRight->lLine + plnbetRight->lOdds,
                   *plBank,
                   FALSE) ;
        plnbetRight->lLine = 0 ;
        plnbetRight->lOdds = 0 ;
      }
      if (plnbetWrong->lLine)
      {
        lWinnings = plnbetWrong->lLine ;
        if ((fBetsOn) && (plnbetWrong->lOdds))
          lWinnings += CheckOdds (*psPoint, plnbetWrong->lOdds, FALSE) ;
        lTotal += lWinnings ;
        *plBank += (plnbetWrong->lLine + plnbetWrong->lOdds + lWinnings) ;
        BetResult (hab,
                   hwnd,
                   ulWrongBetName,
                   plnbetWrong->lLine + plnbetWrong->lOdds,
                   lWinnings,
                   *plBank,
                   TRUE) ;
        plnbetWrong->lLine = 0 ;
        plnbetWrong->lOdds = 0 ;
      }
      *psPoint = 0 ;
    }
  return (lTotal) ;
}

/*********************************************************************/
/* CheckOdds determines how much to pay in odds on a line win        */
/*********************************************************************/

LONG CheckOdds (SHORT sPoint, LONG lOdds, BOOL fRight)
{
  LONG lWinnings = 0 ;

  switch (sPoint)
  {
    case 4:
    case 10:
      if (fRight)
        lWinnings = lOdds * 2 ;
      else
        lWinnings = lOdds / 2 ;
      break ;

    case 5:
    case 9:
      if (fRight)
        lWinnings = ((lOdds / 2) * 3) + (lOdds % 2) ;
      else
        lWinnings = (lOdds / 3) * 2 ;
      break ;

    case 6:
    case 8:
      if (fRight)
        lWinnings = ((lOdds / 5) * 6) + (lOdds % 5) ;
      else
        lWinnings = (lOdds / 6) * 5 ;
      break ;
  }
  return (lWinnings) ;
}
