/*****                    
 *  DEFINE.H various definitions
 *****/

/*****
 * to use the borland c++ compiler
 *****/

#ifdef BORLAND
  #define _ltoa                   ltoa
#endif

/***** 
 * main resource identifier
 *****/

#define ID_MAIN                   10
#define ID_HELP                   "craps.hlp"
#define WC_CRAPS                  "wc_craps" 

/*****
 * table drawing sizes                       
 *****/                                      

#define TBLUNIT                   100        
#define TBLVERT                   14   /*14*/
#define TBLHORZ                   40   /*40*/

/*****
 * defaults for the settings choices
 *****/

#define DEF_BET                   50                         
#define DEF_MARKER                5000                       
#define DEF_MINBET                5                          
#define DEF_MAXBET                100000000                  
#define DEF_BETLEN                9                          
#define DEF_ODDSMULTIPLE          2                          
#define DEF_AUTOODDS              TRUE                       
#define DEF_BETSONCOME            FALSE                      
#define DEF_GUIDO                 TRUE                       
#define DEF_DIE1POSX              1753
#define DEF_DIE2POSX              2023
#define DEF_DIEPOSY               1100
#define BUFFERLEN                 255                        

/*****
 * keys
 *****/

#define KEY_0                     0X30
#define KEY_9                     0X39
#define KEY_TAB                   0X09
#define KEY_ENTER                 0X0D
#define KEY_BSPACE                0X08
                            
/*****
 * menu ids
 *****/

#define IDM_FILE                  1000
#define IDM_FILENEW               1100
#define IDM_BET                   2000
#define IDM_BETLINE               2100
#define IDM_BETPASS               2110
#define IDM_BETDONTPASS           2120
#define IDM_BETCOME               2130
#define IDM_BETDONTCOME           2140
#define IDM_BETPLACE              2200
#define IDM_BETPLACEFOUR          2210
#define IDM_BETPLACEFIVE          2220
#define IDM_BETPLACESIX           2230
#define IDM_BETPLACEEIGHT         2240
#define IDM_BETPLACENINE          2250         
#define IDM_BETPLACETEN           2260
#define IDM_BETPROPOSITION        2300
#define IDM_BETANYSEVEN           2310
#define IDM_BETANYCRAPS           2320
#define IDM_BETTHREE              2330
#define IDM_BETTWO                2340
#define IDM_BETTWELVE             2350
#define IDM_BETELEVEN             2360
#define IDM_BETHARDWAYS           2400
#define IDM_BETHARDSIX            2410
#define IDM_BETHARDTEN            2420
#define IDM_BETHARDEIGHT          2430
#define IDM_BETHARDFOUR           2440
#define IDM_BETBIGSIX             2500
#define IDM_BETBIGEIGHT           2600
#define IDM_BETFIELD              2700
#define IDM_ROLL                  3000
#define IDM_ROLLROLL              3100
#define IDM_OPTIONS               4000
#define IDM_OPTIONSMARKER         4100
#define IDM_OPTIONSSETTINGS       4200
#define IDM_OPTIONSBETWINDOW      4300
#define IDM_HELP                  5000
#define IDM_HELPHELP              5300
#define IDM_HELPABOUT       5400

/*****
 * help ids
 *****/

#define IDH_MAIN_EXT              10000
#define IDH_NEW_EXT               11000
#define IDH_ABOUT_EXT       12000
#define IDH_SETTINGS_EXT          13000
#define IDH_MARKER_EXT            14000
#define IDH_BET_EXT               15000
#define IDH_HELPINDEX             16000
#define IDH_HELPEXTENDED          17000
#define SUBTABLE_MAIN             20000
#define IDH_FILE                  IDM_FILE
#define IDH_FILENEW               IDM_FILENEW
#define IDH_BET                   IDM_BET
#define IDH_BETLINE               IDM_BETLINE
#define IDH_BETPASS               IDM_BETPASS
#define IDH_BETDONTPASS           IDM_BETDONTPASS
#define IDH_BETCOME               IDM_BETCOME
#define IDH_BETDONTCOME           IDM_BETDONTCOME
#define IDH_BETPLACE              IDM_BETPLACE
#define IDH_BETPLACEFOUR          IDM_BETPLACEFOUR
#define IDH_BETPLACEFIVE          IDM_BETPLACEFIVE
#define IDH_BETPLACESIX           IDM_BETPLACESIX
#define IDH_BETPLACEEIGHT         IDM_BETPLACEEIGHT
#define IDH_BETPLACENINE          IDM_BETPLACENINE
#define IDH_BETPLACETEN           IDM_BETPLACETEN
#define IDH_BETPROPOSITION        IDM_BETPROPOSITION
#define IDH_BETANYSEVEN           IDM_BETANYSEVEN
#define IDH_BETANYCRAPS           IDM_BETANYCRAPS
#define IDH_BETTHREE              IDM_BETTHREE
#define IDH_BETTWO                IDM_BETTWO
#define IDH_BETTWELVE             IDM_BETTWELVE
#define IDH_BETELEVEN             IDM_BETELEVEN
#define IDH_BETHARDWAYS           IDM_BETHARDWAYS
#define IDH_BETHARDSIX            IDM_BETHARDSIX
#define IDH_BETHARDTEN            IDM_BETHARDTEN
#define IDH_BETHARDEIGHT          IDM_BETHARDEIGHT
#define IDH_BETHARDFOUR           IDM_BETHARDFOUR
#define IDH_BETBIGSIX             IDM_BETBIGSIX
#define IDH_BETBIGEIGHT           IDM_BETBIGEIGHT
#define IDH_BETFIELD              IDM_BETFIELD
#define IDH_ROLL                  IDM_ROLL
#define IDH_ROLLROLL              IDM_ROLLROLL
#define IDH_OPTIONS               IDM_OPTIONS
#define IDH_OPTIONSMARKER         IDM_OPTIONSMARKER
#define IDH_OPTIONSSETTINGS       IDM_OPTIONSSETTINGS
#define IDH_HELP                  IDM_HELP
#define IDH_HELPHELP              IDM_HELPHELP
#define IDH_HELPABOUT       IDM_HELPABOUT

/*****
 * string ids
 *****/

#define IDS_APPLNAME              100
#define IDS_AUTHOR                101
#define IDS_VERSION               103
#define IDS_PRODUCTINFO           104
#define IDS_CURRENCY              106
#define IDS_SEPARATOR             107
#define IDS_CLOSETITLE            108
#define IDS_MARKERTITLE           109
#define IDS_NEWTITLE              110
#define IDS_WINTITLE              111
#define IDS_LOSETITLE             112
#define IDS_PUSHTITLE             113
#define IDS_GUIDOTITLE            114
#define IDS_SETTINGSTITLE         115
#define IDS_HELPERRORTITLE        116
#define IDS_ENTRYERROR            117
#define IDS_HELPERROR             118
#define IDS_CLOSEMESSAGE          119
#define IDS_MINBET                120
#define IDS_MAXBET                121
#define IDS_NOTENOUGH             122
#define IDS_MAXODDS               123
#define IDS_COLON                 124
#define IDS_NEWMINBET             125
#define IDS_MAXMARKER             126
#define IDS_WINNER                127
#define IDS_LOSER                 128
#define IDS_PUSH                  129
#define IDS_ABSOLUTEMINBET        130
#define IDS_ABSOLUTEMAXBET        131
#define IDS_MINMAX                132
#define IDS_DEFMAX                133
#define IDS_DEFMIN                134
#define IDS_GUIDO                 135
#define IDS_PASS                  IDM_BETPASS         
#define IDS_DONTPASS              IDM_BETDONTPASS     
#define IDS_COME                  IDM_BETCOME         
#define IDS_DONTCOME              IDM_BETDONTCOME     
#define IDS_PLACEFOUR             IDM_BETPLACEFOUR
#define IDS_PLACEFIVE             IDM_BETPLACEFIVE
#define IDS_PLACESIX              IDM_BETPLACESIX
#define IDS_PLACEEIGHT            IDM_BETPLACEEIGHT
#define IDS_PLACENINE             IDM_BETPLACENINE
#define IDS_PLACETEN              IDM_BETPLACETEN
#define IDS_ANYSEVEN              IDM_BETANYSEVEN
#define IDS_ANYCRAPS              IDM_BETANYCRAPS
#define IDS_THREE                 IDM_BETTHREE
#define IDS_TWO                   IDM_BETTWO
#define IDS_TWELVE                IDM_BETTWELVE
#define IDS_ELEVEN                IDM_BETELEVEN
#define IDS_HARDSIX               IDM_BETHARDSIX
#define IDS_HARDTEN               IDM_BETHARDTEN
#define IDS_HARDEIGHT             IDM_BETHARDEIGHT
#define IDS_HARDFOUR              IDM_BETHARDFOUR
#define IDS_BIGSIX                IDM_BETBIGSIX
#define IDS_BIGEIGHT              IDM_BETBIGEIGHT
#define IDS_FIELD                 IDM_BETFIELD

/*****
 * graphic segment and tag ids
 *****/

#define SEG_DIE1                  1
#define SEG_DIE2                  2
#define SEG_DIE3                  3
#define SEG_DIE4                  4
#define SEG_DIE5                  5
#define SEG_DIE6                  6
#define SEG_LINE                  7
#define SEG_TEXT                  8
#define TAG_PASS                  IDM_BETPASS         
#define TAG_DONTPASS              IDM_BETDONTPASS     
#define TAG_COME                  IDM_BETCOME         
#define TAG_DONTCOME              IDM_BETDONTCOME
#define TAG_PLACEFOUR             IDM_BETPLACEFOUR
#define TAG_PLACEFIVE             IDM_BETPLACEFIVE
#define TAG_PLACESIX              IDM_BETPLACESIX
#define TAG_PLACEEIGHT            IDM_BETPLACEEIGHT
#define TAG_PLACENINE             IDM_BETPLACENINE
#define TAG_PLACETEN              IDM_BETPLACETEN
#define TAG_ANYSEVEN              IDM_BETANYSEVEN
#define TAG_ANYCRAPS              IDM_BETANYCRAPS
#define TAG_THREE                 IDM_BETTHREE
#define TAG_TWO                   IDM_BETTWO
#define TAG_TWELVE                IDM_BETTWELVE
#define TAG_ELEVEN                IDM_BETELEVEN
#define TAG_HARDSIX               IDM_BETHARDSIX
#define TAG_HARDTEN               IDM_BETHARDTEN
#define TAG_HARDEIGHT             IDM_BETHARDEIGHT
#define TAG_HARDFOUR              IDM_BETHARDFOUR
#define TAG_BIGSIX                IDM_BETBIGSIX
#define TAG_BIGEIGHT              IDM_BETBIGEIGHT
#define TAG_FIELD                 IDM_BETFIELD

/*****
 * font ids
 *****/

#define FONT_NORMAL               100
#define FONT_ITALIC               101
