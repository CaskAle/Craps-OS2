/****************************************************************/
/* GRAPHICS.H header for the graphic functions                  */
/****************************************************************/

/****************************************************************/
/* Function prototypes                                          */
/****************************************************************/

VOID DrawTable (PVOID) ;
VOID TextInBox (HPS, RECTL, PSZ) ;
VOID DiceBox (HPS, PPOINTL, LONG) ;
VOID InitFont (HPS) ;
VOID DrawDice (HPS, HPS, PDICEDATA) ;
VOID EraseDice (HPS, HPS, PDICEDATA) ;
VOID SetMarker (HPS, SHORT, BOOL) ;
VOID ClearMarker (HPS, SHORT) ;
