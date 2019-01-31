/*****
 * CRAPS.H main source header file 
 *****/

/*****
 * structures
 *****/

typedef struct _SETTINGS
{
  LONG  lDefaultBet ;
  LONG  lDefaultMarker ;
  LONG  lMaxMarker ;
  LONG  lMinBet ;
  LONG  lMaxBet ;
  BOOL  fAutoOdds ;
  SHORT sOddsMultiple ;
  BOOL  fBetsOnComeOut ;
  BOOL  fGuidoExtracts ;
} SETTINGS ;
typedef SETTINGS *PSETTINGS ;

typedef struct _LINEBET
{
  LONG lLine ;
  LONG lOdds ;
} LINEBET ;
typedef LINEBET *PLINEBET ;

typedef struct _DICEDATA
{
  SHORT   sDie1 ;
  SHORT   sDie2 ;
  SHORT   sRoll ;
  SHORT   sPoint ;
  SHORT   sComePoint ;
  POINTL  ptlDie1 ;
  POINTL  ptlDie2 ;
  HBITMAP hbmDie1 ;
  HBITMAP hbmDie2 ;
  BOOL    fDrawn ;
} DICEDATA ;
typedef DICEDATA *PDICEDATA ;

typedef struct _BETDATA
{
  LINEBET lnbetPass ;
  LINEBET lnbetDontPass ;
  LINEBET lnbetCome ;
  LINEBET lnbetDontCome ;
  LONG    lBigSix ;
  LONG    lBigEight ;
  LONG    lField ;
  LONG    lPlaceFour ;
  LONG    lPlaceFive ;
  LONG    lPlaceSix ;
  LONG    lPlaceEight ;
  LONG    lPlaceNine ;
  LONG    lPlaceTen ;
  LONG    lAnySeven ;
  LONG    lAnyCraps ;
  LONG    lTwo ;
  LONG    lTwelve ;
  LONG    lThree ;
  LONG    lEleven ;
  LONG    lHorn ;
  LONG    lHop ;
  LONG    lCrapsEleven ;
  LONG    lHardFour ;
  LONG    lHardSix ;
  LONG    lHardEight ;
  LONG    lHardTen ;
  LONG    lMarker ;
  LONG    lBank ;
} BETDATA ;
typedef BETDATA *PBETDATA ;

typedef struct _CLIENTDATA
{
  HAB      hab ;
  HWND     hwndMenu ;
  HWND     hwndHelp ;
  HPS      hps ;
  HPS      hpsMemory ;
  HDC      hdcMemory ;
  POINTL   ptlWindowSize ;
  CHAR     pszApplName[MAXNAMEL + 1] ;
  BETDATA  betdata ;
  DICEDATA dicedata ;
  SETTINGS settings ;
} CLIENTDATA ;
typedef CLIENTDATA *PCLIENTDATA ;

typedef struct _INFODLGDATA
{
  CHAR pszApplName[BUFFERLEN] ;
  HAB  hab ;
} INFODLGDATA ;
typedef INFODLGDATA *PINFODLGDATA ;

typedef struct _BETDLGDATA
{
  HWND  hwndHelp ;
  HWND  hwndBetAmount ;
  HWND  hwndOddsAmount ;
  HAB   hab ;
  CHAR  pszApplName[BUFFERLEN] ;
  ULONG ulBetName ;
  BOOL  fLineBet ;
  LONG  lMinBet ;
  LONG  lMaxBet ;
  LONG  lMaxOdds ;
  LONG  lBet ;
  LONG  lOldBet ;
  LONG  lDefaultBet ;
  LONG  lOdds ;
  LONG  lOldOdds ;
  LONG  lDefaultOdds ;
  LONG  lBank ;
  SHORT sPoint ;
} BETDLGDATA ;
typedef BETDLGDATA *PBETDLGDATA ;

typedef struct _NEWDLGDATA
{
  HWND hwndHelp ;
  HWND hwndNewAmount ;
  HAB  hab ;
  CHAR pszApplName[BUFFERLEN] ;
  LONG lMinBet ;
  LONG lMaxMarker ;
  LONG lMarker ;
  LONG lDefaultMarker ;
} NEWDLGDATA ;
typedef NEWDLGDATA *PNEWDLGDATA ;

typedef struct _SETTINGSDLGDATA
{
  HWND     hwndHelp ;
  HWND     hwndMaxAmount ;
  HWND     hwndMinAmount ;
  HWND     hwndDefAmount ;
  CHAR     pszApplName[BUFFERLEN] ;
  LONG     lOldMinBet ;
  LONG     lOldMaxBet ;
  LONG     lOldDefaultBet ;
  HAB      hab ;
  SETTINGS settings ;
} SETTINGSDLGDATA ;
typedef SETTINGSDLGDATA *PSETTINGSDLGDATA ;

typedef struct _MARKERDLGDATA
{
  HWND hwndHelp ;
  HWND hwndAmount ;
  HAB  hab ;
  CHAR pszApplName[BUFFERLEN] ;
  LONG lDefaultChange ;
  LONG lChange ;
  LONG lBank ;
  LONG lMarker ;
  LONG lMaxMarker ;
} MARKERDLGDATA ;
typedef MARKERDLGDATA *PMARKERDLGDATA ;

/*****
 * function prototypes
 *****/

int main (VOID) ;
