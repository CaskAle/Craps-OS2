/************************************************************************/
/* UTILITY.H header for the utility functions                           */
/************************************************************************/

/************************************************************************/
/* Function prototypes                                                  */
/************************************************************************/

VOID   WindowSize (HWND, HPS) ;
VOID   SetSystemMenu (HWND) ;
BOOL   InitHelp (HAB, PHWND, HWND, PSZ, PSZ) ;
ULONG  MessageBox (HAB, HWND, ULONG, ULONG, ULONG, ULONG, BOOL, ...) ;
VOID   InitGame (PBETDATA, PDICEDATA) ;
VOID   InitSettings (PSETTINGS) ;
VOID   PlaceBet (HWND, ULONG, SHORT, PLONG, PLONG, PLONG, PCLIENTDATA) ;
VOID   NewGame (HWND, PLONG, PLONG, PCLIENTDATA) ;
VOID   Copyright (HWND, HAB, PSZ) ;
LONG   SetMaxOdds (SHORT, SHORT, LONG, BOOL) ;
VOID   EntryError (HAB, HWND, HWND, ULONG, ULONG, ULONG, LONG, LONG) ;
VOID   BetResult (HAB, HWND, ULONG, LONG, LONG, LONG, BOOL) ;
VOID   Settings (HWND, PCLIENTDATA) ;
VOID   InitSettingsDlg (HWND, PSETTINGS) ;
VOID   Marker (HWND, PCLIENTDATA) ;
VOID   Guido (HWND, HAB, PLONG, PLONG, LONG) ;
