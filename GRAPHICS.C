/*****
 * GRAPHICS.C does the graphics drawing
 *****/

#define INCL_GPI

#include <os2.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"
#include "craps.h"
#include "graphics.h"

/*****
 * This function Draws the table and dice.
 * This sets up a retained segment that will draw the table
 * and the dice.  The table is a chained segment that can
 * be drawn as a unit.  The dice are not chained so they 
 * can be drawn individually
 *****/

VOID DrawTable (PVOID pvoidHps)
{
  PSZ       apszDontCome[]    = {"Don't", "Come", "Bar"} ;
  PSZ       apszFieldNumber[] = {"2", "3", "4", "9", "10", "11", "12"} ;
  PSZ       apszNumber[]      = {"4", "5", "SIX", "8", "NINE", "10"} ;
  PSZ       pszCome           = "COME" ;
  PSZ       pszPassLine       = "PASS LINE" ;
  PSZ       pszDontPass       = "Don't Pass Bar" ;
  PSZ       pszDontPassV      = "Don't Pass" ;
  PSZ       pszAnySeven       = "Seven" ;
  PSZ       pszAnyCraps       = "Any Craps" ;
  PSZ       pszField          = "FIELD" ;
  PSZ       psz10For1         = "10 for 1" ;
  PSZ       psz15For1         = "15 for 1" ;
  PSZ       psz30For1         = "30 for 1" ;
  PSZ       psz5For1          = "5 for 1" ;
  PSZ       psz8For1          = "8 for 1" ;
  PSZ       pszSix            = "6" ;
  PSZ       pszEight          = "8" ;
  PSZ       pszBig            = "BIG" ;
  HPS       hps               = *(PHPS) pvoidHps ;
  LONG      lDotSize          = 8 ;
  LONG      lDiceSize         = 56 ;
  LONG      lSegTag ;
  SHORT     sRep ;
  POINTL    aptl[5] ;
  RECTL     rcl ;
  SIZEF     sizef ;
  MATRIXLF  matlf ;
  GRADIENTL gradientl ;

  GpiSetDrawingMode (hps, DM_DRAWANDRETAIN) ;
  GpiSetInitialSegmentAttrs (hps, ATTR_CHAINED , ATTR_OFF) ;
  GpiSetInitialSegmentAttrs (hps, ATTR_DETECTABLE, ATTR_OFF) ;

  /*****
   * Dice face 1
   *****/

  GpiOpenSegment (hps, SEG_DIE1) ;
  GpiSetTag (hps, SEG_DIE1) ;
  GpiSetPattern (hps, PATSYM_SOLID) ;
  GpiSetColor (hps, CLR_RED) ;
  aptl[0].x = 0 ;
  aptl[0].y = 0 ;
  DiceBox (hps, aptl, lDiceSize) ;
  GpiSetColor (hps, CLR_WHITE) ;
  aptl[0].x = 24 ;
  aptl[0].y = 24 ;
  DiceBox (hps, aptl, lDotSize) ; /* center center */
  GpiCloseSegment (hps) ;

  /*****
   * Dice face 2
   *****/

  GpiOpenSegment (hps, SEG_DIE2) ;
  GpiSetTag (hps, SEG_DIE2) ;
  GpiSetPattern (hps, PATSYM_SOLID) ;
  GpiSetColor (hps, CLR_RED) ;
  aptl[0].x = 0 ;
  aptl[0].y = 0 ;
  DiceBox (hps, aptl, lDiceSize) ;
  GpiSetColor (hps, CLR_WHITE) ;
  aptl[0].x = 8 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper left  */
  aptl[0].x = 40 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower right */
  GpiCloseSegment (hps) ;

  /*****
   * Dice face 3
   *****/

  GpiOpenSegment (hps, SEG_DIE3) ;
  GpiSetTag (hps, SEG_DIE3) ;
  GpiSetPattern (hps, PATSYM_SOLID) ;
  GpiSetColor (hps, CLR_RED) ;
  aptl[0].x = 0 ;
  aptl[0].y = 0 ;
  DiceBox (hps, aptl, lDiceSize) ;
  GpiSetColor (hps, CLR_WHITE) ;
  aptl[0].x = 8 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper left    */
  aptl[0].x = 24 ;
  aptl[0].y = 24 ;
  DiceBox (hps, aptl, lDotSize) ; /* center center */
  aptl[0].x = 40 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower right   */
  GpiCloseSegment (hps) ;

  /*****
   * Dice face 4
   *****/

  GpiOpenSegment (hps, SEG_DIE4) ;
  GpiSetTag (hps, SEG_DIE4) ;
  GpiSetPattern (hps, PATSYM_SOLID) ;
  GpiSetColor (hps, CLR_RED) ;
  aptl[0].x = 0 ;
  aptl[0].y = 0 ;
  DiceBox (hps, aptl, lDiceSize) ;
  GpiSetColor (hps, CLR_WHITE) ;
  aptl[0].x = 8 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper left  */
  aptl[0].x = 8 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower left  */
  aptl[0].x = 40 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper right */
  aptl[0].x = 40 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower right */
  GpiCloseSegment (hps) ;

  /*****
   * Dice face 5
   *****/

  GpiOpenSegment (hps, SEG_DIE5) ;
  GpiSetTag (hps, SEG_DIE5) ;
  GpiSetPattern (hps, PATSYM_SOLID) ;
  GpiSetColor (hps, CLR_RED) ;
  aptl[0].x = 0 ;
  aptl[0].y = 0 ;
  DiceBox (hps, aptl, lDiceSize) ;
  GpiSetColor (hps, CLR_WHITE) ;
  aptl[0].x = 8 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper left    */
  aptl[0].x = 8 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower left    */
  aptl[0].x = 24 ;
  aptl[0].y = 24 ;
  DiceBox (hps, aptl, lDotSize) ; /* center center */
  aptl[0].x = 40 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper right   */
  aptl[0].x = 40 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower right   */
  GpiCloseSegment (hps) ;

  /*****
   * Dice face 6
   *****/

  GpiOpenSegment (hps, SEG_DIE6) ;
  GpiSetTag (hps, SEG_DIE6) ;
  GpiSetPattern (hps, PATSYM_SOLID) ;
  GpiSetColor (hps, CLR_RED) ;
  aptl[0].x = 0 ;
  aptl[0].y = 0 ;
  DiceBox (hps, aptl, lDiceSize) ;
  GpiSetColor (hps, CLR_WHITE) ;
  aptl[0].x = 8 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper left   */
  aptl[0].x = 8 ;
  aptl[0].y = 24 ;
  DiceBox (hps, aptl, lDotSize) ; /* center left  */
  aptl[0].x = 8 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower left   */
  aptl[0].x = 40 ;
  aptl[0].y = 40 ;
  DiceBox (hps, aptl, lDotSize) ; /* upper right  */
  aptl[0].x = 40 ;
  aptl[0].y = 24 ;
  DiceBox (hps, aptl, lDotSize) ; /* center right */
  aptl[0].x = 40 ;
  aptl[0].y = 8 ;
  DiceBox (hps, aptl, lDotSize) ; /* lower right  */
  GpiCloseSegment (hps) ;

  /*****
   * Set some values for the table segment
   *****/

  GpiSetInitialSegmentAttrs (hps, ATTR_CHAINED, ATTR_ON) ;
  GpiOpenSegment (hps, SEG_LINE) ;
  GpiSetColor (hps, CLR_WHITE) ;
  GpiSetPattern (hps, PATSYM_NOSHADE) ;

  /*****
   * draw the numbers boxes
   *****/

  aptl[0].y = 900 ;
  aptl[1].y = 1300 ;
  lSegTag = TAG_PLACEFOUR ;
  for (sRep = 0; sRep <= 5; sRep++)
  {
    GpiSetTag (hps, lSegTag) ;
    aptl[0].x = 500 + sRep * 200 ;
    aptl[1].x = 700 + sRep * 200 ;
    GpiMove (hps, aptl) ;
    GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
    aptl[0].x = 2300 + sRep * 200 ;
    aptl[1].x = 2500 + sRep * 200 ;
    GpiMove (hps, aptl) ;
    GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
    lSegTag += 10 ;
  }

  /*****
   * draw the don't come box
   *****/
   
  GpiSetTag (hps, TAG_DONTCOME) ;
  aptl[0].x = 300 ;
  aptl[0].y = 900 ;
  aptl[1].x = 500 ;
  aptl[1].y = 1300 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
  aptl[0].x = 3500 ;
  aptl[1].x = 3700 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
  
  /*****
   * draw the the 2 lines that 
   * are in the numbers boxes. 
   *****/
     
  GpiSetTag (hps, 0) ;
  aptl[0].x = 500 ;
  aptl[0].y = 1100 ;
  aptl[1].x = 1700 ;
  aptl[1].y = 1150 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINE, aptl + 1, 0, 0) ;
  aptl[0].x = 2300 ;
  aptl[1].x = 3500 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINE, aptl + 1, 0, 0) ;
  
  /*****
   * draw the come box
   *****/
   
  GpiSetTag (hps, TAG_COME) ;
  aptl[0].x = 300 ;
  aptl[0].y = 700 ;
  aptl[1].x = 1600 ;
  aptl[1].y = 900 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
  aptl[0].x = 2400 ;
  aptl[1].x = 3700 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
    
  /*****
   * draw the field box
   *****/
    
  GpiSetTag (hps, TAG_FIELD) ;
  aptl[0].x = 500 ;
  aptl[0].y = 500 ;
  aptl[1].x = 1600 ;
  aptl[1].y = 500 ;
  aptl[2].x = 1600 ;
  aptl[2].y = 700 ;
  aptl[3].x = 300 ;
  aptl[3].y = 700 ;
  GpiMove (hps, aptl + 3) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 4, aptl) ;
  GpiEndArea(hps) ;
  aptl[0].x = 3500 ;
  aptl[1].x = 2400 ;
  aptl[2].x = 2400 ;
  aptl[3].x = 3700 ;
  GpiMove (hps, aptl + 3) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 4, aptl) ;
  GpiEndArea(hps) ;

  /*****
   * draw the horizontal don't pass box
   *****/
   
  GpiSetTag (hps, TAG_DONTPASS) ;
  aptl[0].x = 500 ;
  aptl[0].y = 400 ;
  aptl[1].x = 1600 ;
  aptl[1].y = 500 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
  aptl[0].x = 2400 ;
  aptl[1].x = 3500 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
    
  /*****
   * draw the vertical don't pass box
   *****/
   
  aptl[0].x = 200 ;
  aptl[0].y = 700 ;
  aptl[1].x = 200 ;
  aptl[1].y = 1250 ;
  aptl[2].x = 300 ;
  aptl[2].y = 1300 ;
  aptl[3].x = 300 ;
  aptl[3].y = 700 ;
  GpiMove (hps, aptl + 3) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 4, aptl) ;
  GpiEndArea(hps) ;
  aptl[0].x = 3800 ;
  aptl[1].x = 3800 ;
  aptl[2].x = 3700 ;
  aptl[3].x = 3700 ;
  GpiMove (hps, aptl + 3) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 4, aptl) ;
  GpiEndArea(hps) ;

  /*****
   * draw the big 6 box
   *****/
   
  GpiSetTag (hps, TAG_BIGSIX) ;
  aptl[0].x = 300 ;
  aptl[0].y = 700 ;
  aptl[1].x = 200 ;
  aptl[1].y = 700 ;
  aptl[2].x = 200 ;
  aptl[2].y = 500 ;
  aptl[3].x = 250 ;
  aptl[3].y = 450 ;
  aptl[4].x = 400 ;
  aptl[4].y = 600 ;
  GpiMove (hps, aptl + 4) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 5, aptl) ;
  GpiEndArea(hps) ;
  aptl[0].x = 3500 ;
  aptl[0].y = 500 ;
  aptl[1].x = 3500 ;
  aptl[1].y = 400 ;
  aptl[2].x = 3700 ;
  aptl[2].y = 400 ;
  aptl[3].x = 3750 ;
  aptl[4].x = 3600 ;
  GpiMove (hps, aptl + 4) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 5, aptl) ;
  GpiEndArea(hps) ;

  /*****
   * draw the big 8 box
   *****/
   
  GpiSetTag (hps, TAG_BIGEIGHT) ;
  aptl[0].x = 500 ;
  aptl[0].y = 500 ;
  aptl[1].x = 500 ;
  aptl[1].y = 400 ;
  aptl[2].x = 300 ;
  aptl[2].y = 400 ;
  aptl[3].x = 250 ;
  aptl[3].y = 450 ;
  aptl[4].x = 400 ;
  aptl[4].y = 600 ;
  GpiMove (hps, aptl + 4) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 5, aptl) ;
  GpiEndArea(hps) ;
  aptl[0].x = 3700 ;
  aptl[0].y = 700 ;
  aptl[1].x = 3800 ;
  aptl[1].y = 700 ;
  aptl[2].x = 3800 ;
  aptl[2].y = 500 ;
  aptl[3].x = 3750 ;
  aptl[4].x = 3600 ;
  GpiMove (hps, aptl + 4) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 5, aptl) ;
  GpiEndArea(hps) ;

  /*****
   * draw the passline
   *****/
     
  GpiSetTag (hps, TAG_PASS) ;
  aptl[0].x = 300 ;
  aptl[0].y = 400 ;
  aptl[1].x = 1600 ;
  aptl[1].y = 400 ;
  aptl[2].x = 1600 ;
  aptl[2].y = 300 ;
  aptl[3].x = 300 ;
  aptl[3].y = 300 ;
  GpiMove (hps, aptl) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 3, aptl + 1) ;
  aptl[0].x = 100 ;
  aptl[0].y = 300 ;
  aptl[1].x = 100 ;
  aptl[1].y = 500 ;
  GpiPolyFillet (hps, 2, aptl) ;
  aptl[0].x = 100 ;
  aptl[0].y = 1200 ;
  aptl[1].x = 200 ;
  aptl[1].y = 1250 ;
  aptl[2].x = 200 ;
  aptl[2].y = 500 ;
  GpiPolyLine (hps, 3, aptl) ;
  GpiEndArea(hps) ;
  aptl[0].x = 3700 ;
  aptl[0].y = 400 ;
  aptl[1].x = 2400 ;
  aptl[1].y = 400 ;
  aptl[2].x = 2400 ;
  aptl[2].y = 300 ;
  aptl[3].x = 3700 ;
  aptl[3].y = 300 ;
  GpiMove (hps, aptl) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 3, aptl + 1) ;
  aptl[0].x = 3900 ;
  aptl[0].y = 300 ;
  aptl[1].x = 3900 ;
  aptl[1].y = 500 ;
  GpiPolyFillet (hps, 2, aptl) ;
  aptl[0].x = 3900 ;
  aptl[0].y = 1200 ;
  aptl[1].x = 3800 ;
  aptl[1].y = 1250 ;
  aptl[2].x = 3800 ;
  aptl[2].y = 500 ;
  GpiPolyLine (hps, 3, aptl) ;
  GpiEndArea(hps) ;
  
  /*****
   * draw the seven box
   *****/
   
  GpiSetTag (hps, TAG_ANYSEVEN) ;
  aptl[0].x = 2250 ;
  aptl[0].y = 950 ;
  aptl[1].x = 2250 ;
  aptl[1].y = 850 ;
  aptl[2].x = 1750 ;
  aptl[2].y = 850 ;
  aptl[3].x = 1750 ;
  aptl[3].y = 950 ;
  GpiMove (hps, aptl) ;
  GpiBeginArea (hps, BA_BOUNDARY) ;
  GpiPolyLine (hps, 3, aptl + 1) ;
  aptl[0].x = 1900 ;
  aptl[0].y = 1000 ;
  aptl[1].x = 2100 ;
  aptl[1].y = 1000 ;
  aptl[2].x = 2250 ;
  aptl[2].y = 950 ;
  GpiPolyFillet (hps, 3, aptl) ;
  GpiEndArea (hps) ;
 
  /*****
   * draw the hard six box
   *****/

  GpiSetTag (hps, TAG_HARDSIX) ;
  aptl[0].x = 1700 ;
  aptl[0].y = 700 ;
  aptl[1].x = 2000 ;
  aptl[1].y = 850 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;

  /*****
   * draw the hard ten box
   *****/

  GpiSetTag (hps, TAG_HARDTEN) ;
  aptl[0].x = 2000 ;
  aptl[1].x = 2300 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
  
  /*****
   * draw the hard eight box
   *****/

  GpiSetTag (hps, TAG_HARDEIGHT) ;
  aptl[0].x = 1700 ;
  aptl[0].y = 550 ;
  aptl[1].x = 2000 ;
  aptl[1].y = 700 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;

  /*****
   * draw the hard four box
   *****/

  GpiSetTag (hps, TAG_HARDFOUR) ;
  aptl[0].x = 2000 ;
  aptl[1].x = 2300 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;

  /*****
   * draw the three, two, and twelve boxes
   *****/
   
  lSegTag = TAG_THREE ; 
  aptl[0].y = 400 ;
  aptl[1].y = 550 ;
  for (sRep = 0; sRep <= 2; sRep++)
  {
    GpiSetTag (hps, lSegTag) ;
    aptl[0].x = 1700 + sRep * 200 ;
    aptl[1].x = 1900 + sRep * 200 ;
    GpiMove (hps, aptl) ;
    GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
    lSegTag += 10 ;
  }
  
  /*****
   * draw the eleven boxes
   *****/
   
  GpiSetTag (hps, TAG_ELEVEN) ;
  aptl[0].x = 1700 ;
  aptl[0].y = 250 ;
  aptl[1].x = 2300 ;
  aptl[1].y = 400 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;
  aptl[0].x = 2000 ;
  aptl[1].x = 2000 ;
  GpiMove (hps, aptl) ;
  GpiLine (hps, aptl + 1) ;

  /*****
   * draw the any craps box
   *****/
   
  GpiSetTag (hps, TAG_ANYCRAPS) ;
  aptl[0].x = 1700 ;
  aptl[0].y = 100 ;
  aptl[1].x = 2300 ;
  aptl[1].y = 250 ;
  GpiMove (hps, aptl) ;
  GpiBox (hps, DRO_OUTLINEFILL, aptl + 1, 0, 0) ;

  /*****
   * close the table segment
   *****/
   
  GpiCloseSegment (hps) ;
  
  /*****
   * set some values for the font segment
   *****/

  GpiOpenSegment (hps, SEG_TEXT) ;
  GpiSetTag (hps, 0) ;
   
  /*****
   * draw the numbers text
   *****/

  GpiSetCharSet (hps, FONT_NORMAL) ;
  sizef.cx = MAKEFIXED (150, 0) ;
  sizef.cy = MAKEFIXED (150, 0) ;
  GpiSetCharBox (hps, &sizef) ;
  GpiSetColor (hps, CLR_YELLOW) ;
  rcl.yBottom = 900 ;
  rcl.yTop = 1100 ;
  for (sRep = 0; sRep <= 5; sRep++)
  {
    rcl.xLeft = 500 + sRep * 200 ;
    rcl.xRight = 700 + sRep * 200 ;
    if (sRep != 2 && sRep != 4)
      TextInBox (hps, rcl, apszNumber[sRep]) ;
    rcl.xLeft = 2300 + sRep * 200 ;
    rcl.xRight = 2500 + sRep * 200 ;
    if (sRep != 2 && sRep != 4)
      TextInBox (hps, rcl, apszNumber[sRep]) ;
  }

  /*****
   * draw the come text
   *****/

  GpiSetColor (hps, CLR_DARKRED) ;
  rcl.xLeft = 300 ;
  rcl.yBottom = 700 ;
  rcl.xRight = 1600 ;
  rcl.yTop = 900 ;
  TextInBox (hps, rcl, pszCome) ;
  rcl.xLeft = 2400 ;
  rcl.xRight = 3700 ;
  TextInBox (hps, rcl, pszCome) ;

  /*****
   * draw the big six and eight text
   *****/

  gradientl.x = 1 ;
  gradientl.y = -1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  aptl[0].x = 204 ;
  aptl[0].y = 550 ;
  aptl[1].x = 290 ;
  aptl[1].y = 464 ;
  GpiCharStringAt (hps, aptl, (LONG) strlen (pszSix), pszSix) ;
  GpiCharStringAt (hps, 
                   aptl + 1, 
                   (LONG) strlen (pszEight), 
                   pszEight) ;
  gradientl.y = 1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  aptl[0].x = 3653 ;
  aptl[0].y = 405 ;
  aptl[1].x = 3740 ;
  aptl[1].y = 493 ;
  GpiCharStringAt (hps, aptl, (LONG) strlen (pszSix), pszSix) ;
  GpiCharStringAt (hps, 
                   aptl + 1, 
                   (LONG) strlen (pszEight), 
                   pszEight) ;

  /*****
   * draw the dont come text
   *****/

  GpiSetCharSet (hps, FONT_ITALIC) ;
  sizef.cx = MAKEFIXED (58, 0) ;
  sizef.cy = MAKEFIXED (58, 0) ;
  GpiSetCharBox (hps, &sizef) ;
  gradientl.x = 0 ;
  gradientl.y = 0 ;
  GpiSetCharAngle (hps, &gradientl) ;
  GpiSetColor (hps, CLR_BLACK) ;
  rcl.xLeft = 300 ;
  rcl.xRight = 500 ;
  rcl.yTop = 1250 ;
  for (sRep = 0; sRep <= 2; sRep++)
  {
    rcl.yBottom = rcl.yTop - 65 ;
    TextInBox (hps, rcl, apszDontCome[sRep]) ;
    rcl.yTop = rcl.yBottom ;
  }
  rcl.xLeft = 3500 ;
  rcl.xRight = 3700 ;
  rcl.yTop = 1250 ;
  for (sRep = 0; sRep <= 2; sRep++)
  {
    rcl.yBottom = rcl.yTop - 65 ;
    TextInBox (hps, rcl, apszDontCome[sRep]) ;
    rcl.yTop = rcl.yBottom ;
  }

  /*****
   * don't come dice
   *****/

  aptl[0].x = 331 ;
  aptl[0].y = 950 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 413 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 3531 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 3613 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the horizontal don't pass text
   *****/

  GpiSetColor (hps, CLR_BLACK) ;
  rcl.xLeft = 500 ;
  rcl.yBottom = 400 ;
  rcl.xRight = 1600 ;
  rcl.yTop = 500 ;
  TextInBox (hps, rcl, pszDontPass) ;
  rcl.xLeft = 2400 ;
  rcl.xRight = 3500 ;
  TextInBox (hps, rcl, pszDontPass) ;

  /*****
   * horizontal don't pass dice
   *****/

  aptl[0].x = 1435 ;
  aptl[0].y = 422 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 1517 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 3335 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 3417 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
    
  /*****
   * draw the vertical don't pass text
   *****/

  gradientl.x = 0 ;
  gradientl.y = -1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  GpiSetColor (hps, CLR_BLACK) ;
  aptl[0].x = 229 ;
  aptl[0].y = 1225 ;
  GpiCharStringAt (hps, 
                   aptl,
                   (LONG) strlen (pszDontPassV),
                   pszDontPass) ;
  gradientl.y = 1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  aptl[0].x = 3771 ;
  aptl[0].y = 725 ;
  GpiCharStringAt (hps, 
                   aptl, 
                   (LONG) strlen (pszDontPassV),
                   pszDontPass) ;

  /*****
   * vertical don't pass dice
   *****/

  aptl[0].x = 222 ;
  aptl[0].y = 810 ;
  aptl[1].x = 28 ;
  aptl[1].y = 28 ;
  GpiRotate (hps, 
             &matlf, 
             TRANSFORM_REPLACE, 
             MAKEFIXED (90, 0), 
             aptl + 1) ;
  GpiTranslate (hps, &matlf, TRANSFORM_ADD, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].y = 728 ;
  GpiRotate (hps, 
             &matlf, 
             TRANSFORM_REPLACE, 
             MAKEFIXED (90, 0), 
             aptl + 1) ;
  GpiTranslate (hps, &matlf, TRANSFORM_ADD, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 3722 ;
  aptl[0].y = 1085 ;
  GpiRotate (hps, 
             &matlf, 
             TRANSFORM_REPLACE, 
             MAKEFIXED (90, 0), 
             aptl + 1) ;
  GpiTranslate (hps, &matlf, TRANSFORM_ADD, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].y = 1167 ;
  GpiRotate (hps, 
             &matlf, 
             TRANSFORM_REPLACE, 
             MAKEFIXED (90, 0), 
             aptl + 1) ;
  GpiTranslate (hps, &matlf, TRANSFORM_ADD, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the slanted six text
   *****/

  gradientl.x = 1 ;
  gradientl.y = 1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  GpiSetColor (hps, CLR_YELLOW) ;
  aptl[0].y = 930 ;
  aptl[0].x = 975 ;
  GpiMove (hps, aptl) ;
  GpiCharStringAt (hps,
                   aptl,
                   (LONG) strlen (apszNumber[2]),
                   apszNumber[2]) ;
  aptl[0].x = 2775 ;
  GpiMove (hps, aptl) ;
  GpiCharStringAt (hps,
                   aptl,
                   (LONG) strlen (apszNumber[2]),
                   apszNumber[2]) ;

  /*****
   * draw the slanted nine text
   *****/

  aptl[0].x = 1350 ;
  GpiMove (hps, aptl) ;
  GpiCharStringAt (hps,
                   aptl,
                   (LONG) strlen (apszNumber[4]),
                   apszNumber[4]) ;
  aptl[0].x = 3150 ;
  GpiMove (hps, aptl) ;
  GpiCharStringAt (hps,
                   aptl,
                   (LONG) strlen (apszNumber[4]),
                   apszNumber[4]) ;

  /*****
   * draw the field text
   *****/

  GpiSetCharSet (hps, FONT_NORMAL) ;
  sizef.cx = MAKEFIXED (76, 0) ;
  sizef.cy = MAKEFIXED (76, 0) ;
  GpiSetCharBox (hps, &sizef) ;
  gradientl.x = 0 ;
  gradientl.y = 0 ;
  GpiSetCharAngle (hps, &gradientl) ;
  GpiSetColor (hps, CLR_YELLOW) ;
  rcl.xLeft = 500 ;
  rcl.yBottom = 500 ;
  rcl.xRight = 1600 ;
  rcl.yTop = 600 ;
  TextInBox (hps, rcl, pszField) ;
  rcl.xLeft = 2400 ;
  rcl.xRight = 3500 ;
  TextInBox (hps, rcl, pszField) ;
  aptl[0].x = 550 ;
  aptl[0].y = 550 ;
  for (sRep = 0; sRep <= 6; sRep++)
  {
    GpiCharStringAt (hps,
                     aptl,
                     (LONG) strlen (apszFieldNumber[sRep]),
                     apszFieldNumber[sRep]) ;
    aptl[0].x += 150 ;
    if (sRep < 2)
      aptl[0].y += 34 ;
    else if (sRep > 3)
      aptl[0].y -= 34 ;
  }
  aptl[0].x = 2475 ;
  aptl[0].y = 550 ;
  for (sRep = 0; sRep <= 6; sRep++)
  {
    GpiCharStringAt (hps,
                     aptl,
                     (LONG) strlen (apszFieldNumber[sRep]),
                     apszFieldNumber[sRep]) ;
    aptl[0].x += 150 ;
    if (sRep < 2)
      aptl[0].y += 34 ;
    else if (sRep > 3)
      aptl[0].y -= 34 ;
  }

  /*****
   * draw the field circles
   *****/

   GpiSetColor (hps, CLR_BLUE) ;
   aptl[0].x = 569 ;
   aptl[0].y = 573 ;
   GpiMove (hps, aptl) ;
   GpiFullArc (hps, DRO_OUTLINE, MAKEFIXED (58, 0)) ;
   aptl[0].x = 2496 ;
   GpiMove (hps, aptl) ;
   GpiFullArc (hps, DRO_OUTLINE, MAKEFIXED (58, 0)) ;
   aptl[0].x = 1492 ;
   GpiMove (hps, aptl) ;
   GpiFullArc (hps, DRO_OUTLINE, MAKEFIXED (58, 0)) ;
   aptl[0].x = 3421 ;
   GpiMove (hps, aptl) ;
   GpiFullArc (hps, DRO_OUTLINE, MAKEFIXED (58, 0)) ;

  /*****
   * draw the horizontal pass line text
   *****/

  GpiSetColor (hps, CLR_WHITE) ;
  rcl.xLeft = 400 ;
  rcl.yBottom = 300 ;
  rcl.xRight = 1600 ;
  rcl.yTop = 400 ;
  TextInBox (hps, rcl, pszPassLine) ;
  rcl.xLeft = 2400 ;
  rcl.xRight = 3600 ;
  TextInBox (hps, rcl, pszPassLine) ;

  /*****
   * draw the vertical pass line text
   *****/

  gradientl.x = 0 ;
  gradientl.y = -1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  aptl[0].x = 122 ;
  aptl[0].y = 1100 ;
  GpiCharStringAt (hps, 
                   aptl, 
                   (LONG) strlen (pszPassLine),
                   pszPassLine) ;
  gradientl.y = 1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  aptl[0].x = 3879 ;
  aptl[0].y = 700 ;
  GpiCharStringAt (hps, 
                   aptl, 
                   (LONG) strlen (pszPassLine),
                   pszPassLine) ;

  /*****
   * draw the text for the any seven bet
   *****/

  GpiSetCharSet (hps, FONT_ITALIC) ;
  gradientl.x = 0 ;
  gradientl.y = 0 ;
  GpiSetCharAngle (hps, &gradientl) ;
  GpiSetColor (hps, CLR_DARKBLUE) ;
  rcl.xLeft = 1800 ;
  rcl.xRight = 2200 ;
  rcl.yBottom = 900 ;
  rcl.yTop = 1000 ;
  TextInBox (hps, rcl, pszAnySeven) ;

  /*****
   * draw the text for the any craps bet
   *****/

  rcl.xLeft = 1700 ;
  rcl.xRight = 2300 ;
  rcl.yBottom = 150 ;
  rcl.yTop = 250 ;
  TextInBox (hps, rcl, pszAnyCraps) ;

  /*****
   * draw the bigs of big 6 and 8 text
   *****/

  GpiSetCharSet (hps, FONT_NORMAL) ;
  sizef.cx = MAKEFIXED (50, 0) ;
  sizef.cy = MAKEFIXED (50, 0) ;
  GpiSetCharBox (hps, &sizef) ;
  gradientl.x = 1 ;
  GpiSetColor (hps, CLR_YELLOW) ;
  gradientl.y = -1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  aptl[0].x = 290 ;
  aptl[0].y = 640 ;
  aptl[1].x = 383 ;
  aptl[1].y = 547 ;
  GpiCharStringAt (hps, aptl, (LONG) strlen (pszBig), pszBig) ;
  GpiCharStringAt (hps, aptl + 1, (LONG) strlen (pszBig), pszBig) ;
  gradientl.y = 1 ;
  GpiSetCharAngle (hps, &gradientl) ;
  aptl[0].x = 3559 ;
  aptl[0].y = 486 ;
  aptl[1].x = 3655 ;
  aptl[1].y = 583 ;
  GpiCharStringAt (hps, aptl, (LONG) strlen (pszBig), pszBig) ;
  GpiCharStringAt (hps, aptl + 1, (LONG) strlen (pszBig), pszBig) ;
 
  /*****
   * draw the odds text for the seven bet
   *****/
  gradientl.x = 0 ;
  gradientl.y = 0 ;
  GpiSetCharAngle (hps, &gradientl) ;
  GpiSetColor (hps, CLR_WHITE) ;
  rcl.yBottom = 850 ;
  rcl.yTop = 925 ;
  rcl.xLeft = 1700 ;   
  rcl.xRight = 2000 ;
  TextInBox (hps, rcl, psz5For1) ;
  rcl.xLeft = 2000 ;
  rcl.xRight = 2300 ;
  TextInBox (hps, rcl, psz5For1) ;

  /*****
   * draw the odds text for the hard six bet
   *****/

  rcl.xLeft = 1700 ;
  rcl.yBottom = 700 ;
  rcl.xRight = 2000 ;
  rcl.yTop = 775 ;
  TextInBox (hps,
             rcl,
             psz10For1) ;
  /*****
   * hard six dice
   *****/

  aptl[0].x = 1781 ;
  aptl[0].y = 775 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps,
                        SEG_DIE3, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 1863 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE3, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the odds text for the hard ten bet
   *****/

  rcl.xLeft = 2000 ;
  rcl.xRight = 2300 ;
  TextInBox (hps,
             rcl,
             psz8For1) ;

  /*****
   * hard ten dice
   *****/

  aptl[0].x = 2081 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps,
                        SEG_DIE5,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 2163 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE5,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the odds text for the hard eight bet
   *****/

  rcl.xLeft = 1700 ;
  rcl.yBottom = 550 ;
  rcl.xRight = 2000 ;
  rcl.yTop = 625 ;
  TextInBox (hps,
             rcl,
             psz10For1) ;

  /*****
   * hard eight dice
   *****/

  aptl[0].x = 1781 ;
  aptl[0].y = 625 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps,
                        SEG_DIE4,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 1863 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE4,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the odds text for the hard four bet
   *****/

  rcl.xLeft = 2000 ;
  rcl.xRight = 2300 ;
  TextInBox (hps,
             rcl,
             psz8For1) ;
  /*****
   * hard four dice
   *****/

  aptl[0].x = 2081 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps,
                        SEG_DIE2,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 2163 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE2,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the odds text for the three, two, and twelve bets
   *****/

  rcl.yBottom = 400 ;
  rcl.yTop = 475 ;
  for (sRep = 0; sRep <= 2; sRep++)
  {
    rcl.xLeft = 1700 + sRep * 200 ;
    rcl.xRight = 1900 + sRep * 200 ;
    TextInBox (hps, 
               rcl, 
               (sRep ? psz30For1 : psz15For1)) ;
  }
    
  /*****
   * three, two, twelve dice
   *****/ 
   
  aptl[0].x = 1731 ;
  aptl[0].y = 475 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE1, 
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 1813 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE2,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 1931 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE1,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 2013 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE1,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 2131 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 2213 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE6,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the odds text for the eleven bet
   *****/

  rcl.xLeft = 1700 ;
  rcl.yBottom = 250 ;
  rcl.xRight = 2000 ;
  rcl.yTop = 325 ;
  TextInBox (hps, rcl, psz15For1) ;
  rcl.xLeft = 2000 ;
  rcl.xRight = 2300 ;
  TextInBox (hps, rcl, psz15For1) ;

  /*****
   * eleven dice
   *****/ 

  aptl[0].x = 1781 ;
  aptl[0].y = 325 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps,
                        SEG_DIE6,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 1863 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE5,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 2081 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps,
                        SEG_DIE6,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;
  aptl[0].x = 2163 ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, aptl) ;
  GpiCallSegmentMatrix (hps, 
                        SEG_DIE5,
                        9, 
                        &matlf, 
                        TRANSFORM_REPLACE) ;

  /*****
   * draw the odds text for the any craps bet
   *****/

  rcl.xLeft = 1700 ;
  rcl.yBottom = 100 ;
  rcl.xRight = 1900 ;
  rcl.yTop = 175 ;
  TextInBox (hps, rcl, psz8For1) ;
  rcl.xLeft = 2100 ;
  rcl.xRight = 2300 ;
  TextInBox (hps, rcl, psz8For1) ;

  /*****
   * close the text segment and end the DrawTable function
   *****/

  GpiCloseSegment (hps) ;
  return ;
}

/*****
 * Center text in a box
 *****/

VOID TextInBox (HPS hps,  RECTL rcl, PSZ pszString)
{
  LONG        lStrLen ;
  POINTL      aptl[TXTBOX_COUNT] ;
  POINTL      ptl ;
  FONTMETRICS fm ;

  ptl.x = rcl.xLeft ;
  ptl.y = rcl.yBottom ;
  lStrLen = (LONG) strlen (pszString) ;
  GpiQueryTextBox (hps, lStrLen, pszString, TXTBOX_COUNT, aptl) ;
  GpiQueryFontMetrics (hps, sizeof (FONTMETRICS), &fm) ;
  ptl.x += (rcl.xRight - rcl.xLeft - aptl[TXTBOX_TOPRIGHT].x) / 2 ;
  ptl.y += (rcl.yTop - rcl.yBottom - (fm.lEmHeight - fm.lMaxDescender)) / 2 ;
  GpiCharStringAt (hps, &ptl, lStrLen, pszString) ;
  return ;
}

/*****
 * Draw the boxes that make up dice
 *****/

VOID DiceBox (HPS hps, PPOINTL pptl, LONG lChange)
{
  GpiMove (hps, pptl) ;
  pptl->x += lChange ;
  pptl->y += lChange ;
  GpiBox (hps, DRO_OUTLINEFILL, pptl, 0, 0) ;
  return ;
}

/******************************************/
/* Initialize the fonts used by the table */
/******************************************/

VOID InitFont (HPS hps)
{
  LONG        lNumFonts = 1 ;
  FONTMETRICS fm ;
  FATTRS      fattrs ;

  GpiQueryFonts(hps,
                QF_PUBLIC,
                "Helvetica",
                &lNumFonts,
                (LONG) sizeof (FONTMETRICS),
                &fm) ;
  fattrs.usRecordLength = sizeof(FATTRS) ;
  fattrs.fsSelection = fm.fsSelection ;
  fattrs.lMatch = 0 ;
  strcpy (fattrs.szFacename, fm.szFacename) ;
  fattrs.idRegistry = fm.idRegistry ;
  fattrs.usCodePage = fm.usCodePage ;
  fattrs.lMaxBaselineExt = 0 ;
  fattrs.lAveCharWidth = 0 ;
  fattrs.fsType = 0 ;
  fattrs.fsFontUse = (USHORT) FATTR_FONTUSE_OUTLINE |
                     (USHORT) FATTR_FONTUSE_TRANSFORMABLE |
                     (USHORT) FATTR_FONTUSE_NOMIX ;
  GpiCreateLogFont(hps, (PSTR8) NULL, FONT_NORMAL, &fattrs) ;
  fattrs.fsSelection = FATTR_SEL_ITALIC ;
  GpiCreateLogFont(hps, (PSTR8) NULL, FONT_ITALIC, &fattrs) ;
  return ;                                          
}                                                         
                     
/***************************************/
/* Draw the rolling dice on the screen */
/***************************************/

VOID DrawDice (HPS hps, HPS hpsMemory, PDICEDATA pdicedata)
{
  POINTL            aptl[3] ;
  BITMAPINFOHEADER2 bmapinfo ;
  MATRIXLF          matlf ;
  MATRIXLF          matlfOld ;
  FIXED             afxScale[2] ;

  if (!pdicedata->fDrawn)
  {
    /* capture die 1 area here  */
    aptl[0] = pdicedata->ptlDie1 ;
    aptl[1].x = aptl[0].x + 200 ;
    aptl[1].y = aptl[0].y + 200 ;
    aptl[2] = pdicedata->ptlDie1 ;
    GpiConvert (hps, CVTC_MODEL, CVTC_DEVICE, 3, aptl) ;
    aptl[1].x += 10 ;
    aptl[1].y += 10 ;
    memset (&bmapinfo, 0, sizeof (bmapinfo)) ;
    bmapinfo.cbFix =  sizeof (bmapinfo) ;
    bmapinfo.cx = aptl[1].x ;
    bmapinfo.cy = aptl[1].y ;
    bmapinfo.cPlanes = 1 ;
    bmapinfo.cBitCount = 24 ;
    pdicedata->hbmDie1 = GpiCreateBitmap (hpsMemory, 
                                          &bmapinfo, 
                                          0, 
                                          NULL, 
                                          NULL) ;
    GpiSetBitmap (hpsMemory, pdicedata->hbmDie1) ;
    GpiBitBlt (hpsMemory, hps, 3, aptl, ROP_SRCCOPY, BBO_IGNORE) ;
    GpiSetBitmap (hpsMemory, NULLHANDLE) ;
  
    /* capture die 2 area here */
    aptl[0] = pdicedata->ptlDie2 ;
    aptl[1].x = aptl[0].x + 200 ;
    aptl[1].y = aptl[0].y + 200 ;
    aptl[2] = pdicedata->ptlDie2 ;
    GpiConvert (hps, CVTC_MODEL, CVTC_DEVICE, 3, aptl) ;
    aptl[1].x += 10 ;
    aptl[1].y += 10 ;
    memset (&bmapinfo, 0, sizeof (bmapinfo)) ;
    bmapinfo.cbFix =  sizeof (bmapinfo) ;
    bmapinfo.cx = aptl[1].x ;
    bmapinfo.cy = aptl[1].y ;
    bmapinfo.cPlanes = 1 ;
    bmapinfo.cBitCount = 24 ;
    pdicedata->hbmDie2 = GpiCreateBitmap (hpsMemory, 
                                          &bmapinfo, 
                                          0, 
                                          NULL, 
                                          NULL) ;
    GpiSetBitmap (hpsMemory, pdicedata->hbmDie2) ;
    GpiBitBlt (hpsMemory, hps, 3, aptl, ROP_SRCCOPY, BBO_IGNORE) ;
    GpiSetBitmap (hpsMemory, NULLHANDLE) ;
  }

  afxScale[0] = MAKEFIXED (4, 0) ;
  afxScale[1] = afxScale[0] ;
  GpiQueryModelTransformMatrix (hps, 9, &matlfOld) ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, &pdicedata->ptlDie1) ;
  GpiScale (hps, &matlf, TRANSFORM_ADD, afxScale, &pdicedata->ptlDie1) ;
  GpiSetModelTransformMatrix (hps, 9, &matlf, TRANSFORM_REPLACE) ;
  GpiDrawSegment (hps, pdicedata->sDie1) ;
  GpiTranslate (hps, &matlf, TRANSFORM_REPLACE, &pdicedata->ptlDie2) ;
  GpiScale (hps, &matlf, TRANSFORM_ADD, afxScale, &pdicedata->ptlDie2) ;
  GpiSetModelTransformMatrix (hps, 9, &matlf, TRANSFORM_REPLACE) ;
  GpiDrawSegment (hps, pdicedata->sDie2) ;
  GpiSetModelTransformMatrix (hps, 9, &matlfOld, TRANSFORM_REPLACE) ;
  pdicedata->fDrawn = TRUE ;
  return ;
}

/******************************************/
/* Erase the rolling dice from the screen */
/******************************************/

VOID EraseDice (HPS hps, HPS hpsMemory, PDICEDATA pdicedata)
{
  POINTL aptl[3] ;

  /* erase die 1 area here */
  GpiSetBitmap (hpsMemory, pdicedata->hbmDie1) ;
  aptl[0] = pdicedata->ptlDie1 ;
  aptl[1].x = aptl[0].x + 200 ;
  aptl[1].y = aptl[0].y + 200 ;
  aptl[2] = pdicedata->ptlDie1 ;
  GpiConvert (hps, CVTC_MODEL, CVTC_DEVICE, 3, aptl) ;
  aptl[1].x += 10 ;
  aptl[1].y += 10 ;
  GpiBitBlt (hps, hpsMemory, 3, aptl, ROP_SRCCOPY, BBO_IGNORE) ;
  GpiSetBitmap (hpsMemory, NULLHANDLE) ;
  GpiDeleteBitmap (pdicedata->hbmDie1) ;

  /* erase die 2 area here */
  GpiSetBitmap (hpsMemory, pdicedata->hbmDie2) ;
  aptl[0] = pdicedata->ptlDie2 ;
  aptl[1].x = aptl[0].x + 200 ;
  aptl[1].y = aptl[0].y + 200 ;
  aptl[2] = pdicedata->ptlDie2 ;
  GpiConvert (hps, CVTC_MODEL, CVTC_DEVICE, 3, aptl) ;
  aptl[1].x += 10 ;
  aptl[1].y += 10 ;
  GpiBitBlt (hps, hpsMemory, 3, aptl, ROP_SRCCOPY, BBO_IGNORE) ;
  GpiSetBitmap (hpsMemory, NULLHANDLE) ;
  GpiDeleteBitmap (pdicedata->hbmDie2) ;
  pdicedata->fDrawn = FALSE ;
  return ;
}

/******************************/
/* Set the marker for a point */
/******************************/

VOID SetMarker (HPS hps, SHORT sPoint, BOOL fCome)
{
  SHORT  sRep ;
  POINTL ptl ;
  RECTL  rcl ;
  SIZEF  sizef ;

  GpiSetCharSet (hps, FONT_NORMAL) ;
  sizef.cx = MAKEFIXED ((fCome ? 50 : 40), 0) ;
  sizef.cy = MAKEFIXED ((fCome ? 50 : 40), 0) ;
  GpiSetCharBox (hps, &sizef) ;
  ptl.y = 1225 ;
  for (sRep = 0; sRep <= 1; sRep++)
  {
    switch (sPoint)
    {
      case  4:
        ptl.x = TBLUNIT * (sRep ? 24 : 6) ;
        break ;
      case  5:
        ptl.x = TBLUNIT * (sRep ? 26 : 8) ;
        break ;
      case  6:
        ptl.x = TBLUNIT * (sRep ? 28 : 10) ;
        break ;
      case  8:
        ptl.x = TBLUNIT * (sRep ? 30 : 12) ;
        break ;
      case  9:
        ptl.x = TBLUNIT * (sRep ? 32 : 14) ;
        break ;
      case 10:
        ptl.x = TBLUNIT * (sRep ? 34 : 16) ;
        break ;
    }
    GpiMove (hps, &ptl) ;
    GpiSetColor (hps, fCome ? CLR_PALEGRAY : CLR_WHITE) ;
    GpiFullArc (hps, DRO_FILL, MAKEFIXED (TBLUNIT / 2, 0)) ;
    GpiSetColor (hps, CLR_BLACK) ;
    GpiFullArc (hps, DRO_OUTLINE, MAKEFIXED (TBLUNIT / 2, 0)) ;
    rcl.xLeft = ptl.x - TBLUNIT / 2 ;
    rcl.xRight = ptl.x + TBLUNIT / 2 ;
    rcl.yBottom = ptl.y - TBLUNIT / 2 ;
    rcl.yTop = ptl.y + TBLUNIT / 2 ;
    GpiSetColor (hps, fCome ? CLR_DARKRED : CLR_BLACK) ;
    TextInBox (hps, rcl, fCome ? "C" : "O N") ;
  }
  GpiSetCharSet (hps, LCID_DEFAULT) ;
  return ;
}

/******************************/
/* Clear a marker for a point */
/******************************/

VOID ClearMarker (HPS hps, SHORT sPoint)
{
  SHORT  sRep ;
  POINTL ptl ;

  GpiSetColor (hps, CLR_DARKGREEN) ;
  ptl.y = TBLUNIT * 49 / 4 ;
  for (sRep = 0; sRep <= 1; sRep++)
  {
    switch (sPoint)
    {
      case  4:
        ptl.x = TBLUNIT * (sRep ? 24 : 6) ;
        break ;
      case  5:
        ptl.x = TBLUNIT * (sRep ? 26 : 8) ;
        break ;
      case  6:
        ptl.x = TBLUNIT * (sRep ? 28 : 10) ;
        break ;
      case  8:
        ptl.x = TBLUNIT * (sRep ? 30 : 12) ;
        break ;
      case  9:
        ptl.x = TBLUNIT * (sRep ? 32 : 14) ;
        break ;
      case 10:
        ptl.x = TBLUNIT * (sRep ? 34 : 16) ;
        break ;
    }
    GpiMove (hps, &ptl) ;
    GpiFullArc (hps, DRO_FILL, MAKEFIXED (50, 0)) ;
  }
  return ;
}
