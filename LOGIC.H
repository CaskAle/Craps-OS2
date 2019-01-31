/****************************************************************/
/* LOGIC.H header for the logic functions                       */
/****************************************************************/

/****************************************************************/
/* Function prototypes                                          */
/****************************************************************/

VOID PlayGame (HWND, PCLIENTDATA) ;
VOID RollDice (HPS, HPS, PDICEDATA) ;
LONG NumberCheck (HWND, HAB, SHORT, SHORT, PLONG, PLONG, SHORT, ULONG) ;
LONG HardWays (HWND, HAB, PDICEDATA, SHORT, PLONG, PLONG, SHORT, ULONG) ;
LONG AnyCraps (HWND, HAB, SHORT, PLONG, PLONG) ;
LONG NumberBeforeSeven (HWND, HAB, SHORT, SHORT, PLONG, PLONG,
                        SHORT , SHORT, ULONG) ;
LONG FieldBet (HWND, HAB, SHORT, PLONG, PLONG) ;
LONG LineBet (HWND, HAB, SHORT, PSHORT, PLINEBET, PLINEBET, PLONG,
              BOOL, ULONG, ULONG) ;
LONG CheckOdds (SHORT, LONG, BOOL) ;
