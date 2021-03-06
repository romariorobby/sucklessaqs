/* See LICENSE file for copyright and license details. */
/*constant */
#define TERMINAL "st"
#define TERMCLASS "St"
/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
//static const int showsystray        = 1;     /* 0 means no systray | no need anymore change with toggle */
static int showsystray              = 1;
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10","Noto Color Emoji:pixelsize=10","JoyPixels:pixelsize=10:antialias=true:autohint=true","Siji:size=10","AppleEmoji:pixelsize=10:antialias=true:autohint=true","Hack Nerd Font:size=10", "Hasklug Nerd Font:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_bg[]          = "#141414";
static const char col_fg[]          = "#EBDBB2";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#008080";
static const char col_red[]         = "#fb4934";
static const char col_green[]       = "#b8bb26";
static const char col_blue[]        = "#458588";
static const char col_white[]       = "#ffffff";
static const char col_yellow[]      = "#fabd2f";
//static const char col6[]            = "#ffffff";
//static const char col7[]            = "#ffffff";
//static const char col8[]            = "#ffffff";
//static const char col9[]            = "#ffffff";
//static const char col10[]           = "#ffffff";
//static const char col11[]           = "#ffffff";
//static const char col12[]           = "#ffffff";
static const char *colors[][10]      = {
//	/*               fg         bg         border   */
//	[SchemeNorm]  = { col_gray3, col_gray1, col_gray2 },
//	[SchemeCol1]  = { col1,      col_gray1, col_gray2 },
//	[SchemeCol2]  = { col2,      col_gray1, col_gray2 },
//	[SchemeCol3]  = { col3,      col_gray1, col_gray2 },
//	[SchemeCol4]  = { col4,      col_gray1, col_gray2 },
//	[SchemeCol5]  = { col5,      col_gray1, col_gray2 },
//	[SchemeCol6]  = { col6,      col_gray1, col_gray2 },
//	[SchemeCol7]  = { col7,      col_gray1, col_gray2 },
//	[SchemeCol8]  = { col8,      col_gray1, col_gray2 },
//	[SchemeCol9]  = { col8,      col_gray1, col_gray2 },
//	[SchemeCol10] = { col10,     col_gray1, col_gray2 },
//	[SchemeCol11] = { col11,     col_gray1, col_gray2 },
//	[SchemeCol12] = { col12,     col_gray1, col_gray2 },
//	[SchemeCol13] = { col12,     col_gray1, col_gray2 },
//	[SchemeCol14] = { col12,     col_gray1, col_gray2 },
//	[SchemeCol15] = { col12,     col_gray1, col_gray2 },
//	[SchemeSel]   = { col_gray4, col_cyan,  col_cyan  },
//};
    /*                   fg          bg         border   */
    [SchemeNorm]  = { "#d5c4a1", "#141414", "#282828" },        /* [0]  01 - Client normal */
    [SchemeCol1]  = { "#458588", "#141414", "#ebdbb2" },        /* [1]  02 - Client selected */
    [SchemeCol2]  = { "#fb4934", "#141414", "#83a598" },        /* [2]  03 - Client urgent */
    [SchemeCol3]  = { "#83a598", "#141414", "#83a598" },        /* [3]  04 - Client occupied */
    [SchemeCol4]  = { "#fb4934", "#141414", "#282828" },        /* [4]  05 - Red */
    [SchemeCol5]  = { "#fabd2f", "#141414", "#282828" },        /* [5]  06 - Yellow */
    [SchemeCol6]  = { "#b8bb26", "#141414", "#282828" },        /* [6]  07 - Green */
    [SchemeCol7]  = { "#928374", "#141414", "#282828" },        /*> [7]  08 - Dark grey */
    [SchemeCol8]  = { "#d5c4a1", "#141414", "#282828" },        /* [8]  09 - Light grey */
    [SchemeCol9]  = { "#928374", "#141414", "#928374" },        /* [9]  0A - Bar normal*/
    [SchemeCol10] = { "#a89985", "#141414", "#3c3836" },        /* [10] 0B - Bar selected*/
    [SchemeCol11] = { "#fb4934", "#141414", "#fb4934" },        /* [11] 0C - Bar urgent*/
    [SchemeCol12] = { "#458588", "#141414", "#928374" },        /* [12] 0D - Bar occupied*/
    [SchemeCol13] = { "#ebdbb2", "#141414", "#008080" },        /* [13] 0E - Tag normal*/
    [SchemeCol14] = { "#83a598", "#141414", "#83a598" },        /* >[14] 0F - Tag selected*/
    [SchemeCol15] = { "#fb4934", "#141414", "#fb4934" },        /* [15] 10 - Tag urgent*/
    [SchemeSel]   = { "#458588", "#141414", "#458588" },        /* [16] 11 - Tag occupied*/
    [SchemeInv]   = { "#fb4934", "#458588", "#458588" },        /* [17] 11 - Invert*/
};
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spfm", "-g", "144x41", "-e", "lf", NULL };
/* const char *spcmd3[] = {"bitwarden", NULL }; */
/* const char *spcmd4[] = {TERMINAL, "-n", "spemacs", "-g", "144x41", "-e", "emacs", NULL }; */
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spfm",        spcmd2},
	/* {"bitwarden",   spcmd3}, */
	/* {"spemacs",     spcmd4}, */
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "8" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance       title           tags mask       isfloating  isterminal  noswallow  monitor */
	{ "Gimp",             NULL,          NULL,           0,              1,          0,           0,        -1 },
	{ "Firefox",          NULL,          NULL,           1 << 8,         0,          0,          -1,        -1 },
	{ "Brave-browser",    NULL,          NULL,           1 << 2,         0,          0,          -1,        -1 },
	{ "Pcmanfm",          NULL,          NULL,           1 << 5,         0,          0,          -1,        -1 },
	/* { "Emacs",			  NULL,          NULL,           1 << 5,         0,          0,          -1,        -1 }, */
	{ "Rambox",           NULL,          NULL,           1 << 4,         0,          0,          -1,        -1 },
	{ "Kodi",             NULL,          NULL,           1 << 3,         0,          0,          -1,        -1 },
	{ "Spotify",          NULL,          NULL,           4,              0,          0,          -1,        -1 },
	{ "Notion",           NULL,          NULL,           2,              0,          0,          -1,        -1 },
	{ "TeamViewer",       NULL,          NULL,           1 << 6,         1,          0,          -1,        -1 },
	{ "obsidian",         NULL,          NULL,           2,              0,          0,          -1,        -1 },
	{ TERMINAL,           NULL,          NULL,           0,              0,          1,           0,        -1 },
	{ TERMCLASS,          NULL,          NULL,           0,              0,          1,           0,        -1 },
	{ NULL,               NULL,          "Event Tester", 0,              0,          0,           1,        -1 }, /* xev */
	{ NULL,		          "spterm",	     NULL,		     SPTAG(0),		 1,		     1,           0,        -1 },
	{ NULL,		          "spfm",		 NULL,		     SPTAG(1),		 1,		     1,           0,        -1 },
	/* { NULL,		          "bitwarden",	 NULL,		     SPTAG(2),		 1,		     1,           0,        -1 }, */
	/* { NULL,		          "spemacs",	 NULL,		     SPTAG(3),		 1,		     1,           0,        -1 }, */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachdirection = 2;    /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "[D]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_v,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#include <X11/XF86keysym.h>
#include "shiftview.c"

//static const char col_gray1[]       = "#222222";
//static const char col_gray2[]       = "#444444";
//static const char col_gray3[]       = "#EBDBB2";
//static const char col_gray4[]       = "#eeeeee";
//static const char col_cyan[]        = "#008080";
/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bg, "-nf", col_fg, "-sb", col_blue, "-sf", col_fg, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };


static Key keys[] = {
	/* modifier                     key               function            argument */
	STACKKEYS(MODKEY,                                 focus)
	STACKKEYS(MODKEY|ShiftMask,                       push)
	{ MODKEY|ShiftMask,             XK_Return,        spawn,              {.v = dmenucmd } },
	/* { MODKEY|ShiftMask,             XK_Return,        spawn,              SHCMD("dmenu_run") }, */
	/* { MODKEY,			            XK_Return,        spawn,              {.v = termcmd } }, */
	{ MODKEY,                       XK_b,             togglebar,          {0} },
	{ MODKEY|ShiftMask,             XK_b,             togglesystray,      {0} },
	{ MODKEY,                       XK_f,             togglefullscr,      {0} },
	{ MODKEY|ShiftMask,             XK_f,             togglefloating,     {0} },
	{ MODKEY,                       XK_g,             togglegaps,         {0} },
	{ MODKEY,                       XK_s,             togglesticky,       {0} },
	/* { MODKEY,                       XK_j,             focusstack,         {.i = +1 } }, */
	/* { MODKEY,                       XK_k,             focusstack,         {.i = -1 } }, */
	{ MODKEY,                       XK_o,             incnmaster,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,             incnmaster,         {.i = -1 } },
	{ MODKEY,                       XK_h,             setmfact,           {.f = -0.05} },
	{ MODKEY,                       XK_l,             setmfact,           {.f = +0.05} },
	{ MODKEY,                       XK_space,         zoom,               {0} },
	{ MODKEY|ControlMask,           XK_k,             setcfact,           {.f = +0.25} },
	{ MODKEY|ControlMask,           XK_j,             setcfact,           {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_BackSpace,     setcfact,           {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_h,             incrgaps,           {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_l,             incrgaps,           {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_i,             incrigaps,          {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,             incrigaps,          {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_o,             incrogaps,          {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,             incrogaps,          {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_6,             incrihgaps,         {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,             incrihgaps,         {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_7,             incrivgaps,         {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,             incrivgaps,         {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_8,             incrohgaps,         {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,             incrohgaps,         {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_9,             incrovgaps,         {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,             incrovgaps,         {.i = -1 } },
	{ MODKEY|ControlMask,           XK_BackSpace,     defaultgaps,        {0} },
	{ MODKEY,                       XK_Tab,           view,               {0} },
	{ MODKEY,                       XK_q,             killclient,         {0} },
	{ MODKEY,                       XK_t,             setlayout,          {.v = &layouts[0]} }, /* tile */
	{ MODKEY,                       XK_y,             setlayout,          {.v = &layouts[1]} }, /* Monocle */
	{ MODKEY|ShiftMask,             XK_y,             setlayout,          {.v = &layouts[2]} }, /* Spiral */
	{ MODKEY|ControlMask,           XK_y,             setlayout,          {.v = &layouts[3]} }, /* Dwindle */
	{ MODKEY|Mod1Mask,              XK_y,             setlayout,          {.v = &layouts[4]} }, /* Deck */ 
	{ MODKEY,                       XK_u,             setlayout,          {.v = &layouts[5]} }, /* Bstack*/
	{ MODKEY|ShiftMask,             XK_u,             setlayout,          {.v = &layouts[6]} }, /* Bstack Horizontal */
	{ MODKEY|ControlMask,           XK_u,             setlayout,          {.v = &layouts[7]} }, /* Grid */
	{ MODKEY|Mod1Mask,              XK_u,             setlayout,          {.v = &layouts[8]} }, /* nrowgrid */
	{ MODKEY,                       XK_i,             setlayout,          {.v = &layouts[9]} }, /* horizontal grid */
	{ MODKEY|ShiftMask,             XK_i,             setlayout,          {.v = &layouts[10]} }, /* gaplessgrid */
	{ MODKEY|ControlMask,           XK_i,             setlayout,          {.v = &layouts[11]} }, /* centeredmaster */
	{ MODKEY|Mod1Mask,              XK_i,             setlayout,          {.v = &layouts[12]} }, /* Centered Floating Master */
//	{ MODKEY|ShiftMask,             XK_t,             setlayout,          {0} },
	{ MODKEY,                       XK_grave,         view,               {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_grave,         tag,                {.ui = ~0 } },
	{ MODKEY,                       XK_comma,         focusmon,           {.i = -1 } },
	{ MODKEY,                       XK_period,        focusmon,           {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,         tagmon,             {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,        tagmon,             {.i = +1 } },
	/* { MODKEY,			            XK_p,	          shiftview,	      { .i = -1 } }, */
	/* { MODKEY,			            XK_n,	          shiftview,	      { .i = 1 } }, */
	{ MODKEY,			            XK_comma,	      shiftview,	      { .i = -1 } },
	{ MODKEY,			            XK_period,	      shiftview,	      { .i = 1 } },
	{ MODKEY,            			XK_z,  	          togglescratch,      {.ui = 0 } },
	{ MODKEY,            			XK_x,	          togglescratch,      {.ui = 1 } },
	/* { MODKEY,            			XK_c,	          togglescratch,      {.ui = 2 } }, */
	/* { MODKEY|ControlMask,			XK_space,		  spawn,		      SHCMD("dmenuunicode") }, */
	/* { MODKEY|ShiftMask,             XK_q,			  spawn,			  SHCMD("sysact") }, */
//	{ MODKEY|ShiftMask,             XK_q,             quit,               {0} },
	{ MODKEY|ShiftMask,             XK_Escape,        quit,               {0} },
	TAGKEYS(                        XK_1,                                 0)
	TAGKEYS(                        XK_2,                                 1)
	TAGKEYS(                        XK_3,                                 2)
	TAGKEYS(                        XK_4,                                 3)
	TAGKEYS(                        XK_5,                                 4)
	TAGKEYS(                        XK_6,                                 5)
	TAGKEYS(                        XK_7,                                 6)
	TAGKEYS(                        XK_8,                                 7)
	TAGKEYS(                        XK_9,                                 8)
// Apps Launcher
	/* { Mod1Mask,                     XK_w,			  spawn,			  SHCMD("netw-app") }, */
	/* { Mod1Mask|ShiftMask,			XK_w,		      spawn,	          SHCMD("networkmanager_dmenu") }, */
	/* { Mod1Mask,                     XK_m,			  spawn,			  SHCMD("med-app") }, */
	/* { Mod1Mask,                     XK_e,			  spawn,			  SHCMD("entert-app") }, */
	/* { Mod1Mask,                     XK_x,			  spawn,			  SHCMD("mics-app") }, */
	/* { MODKEY,                       XK_e,			  spawn,			  SHCMD(TERMINAL " -e neomutt ; sigdwmblocks 6") }, */
	/* { Mod1Mask,                     XK_n,			  spawn,			  SHCMD("notes-app") }, */
// MOD + F{N}
	/* { MODKEY,			            XK_F1,		                spawn,	  SHCMD("groff -mom /usr/local/share/dwm/info.mom -Tpdf | zathura -") }, */
	{ MODKEY,			            XK_F2,		                spawn,	  SHCMD(TERMINAL " -e pulsemixer") },
	{ MODKEY,			            XK_F3,		                spawn,	  SHCMD(TERMINAL " -e pavucontrol") },
	{ MODKEY,			            XK_F8,		                spawn,	  SHCMD("networkmanager_dmenu") },
	{ MODKEY,			            XK_F10,		                spawn,	  {.v = dmenucmd } },
	{ MODKEY,			            XK_F11,		                spawn,	  SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
	/* { MODKEY,						XK_F12,						spawn,	  SHCMD("remaps & notify-send \\\"⌨️ Keyboard remapping...\\\" \\\"Re-running keyboard defaults for any newly plugged-in keyboards.\\\"") }, */
	{ MODKEY,			            XK_F12,		                spawn,	  SHCMD("mw -Y; sigdwmblocks 6") },
	/* { MODKEY,			            XK_Print,		            spawn,	  SHCMD("maimpick") }, */
	/* { MODKEY,			            XK_Home,		            spawn,	  SHCMD("dmenumount") }, */
	/* { MODKEY,			            XK_End,		                spawn,	  SHCMD("dmenuumount") }, */
	/* { 0,			                XK_Print,		            spawn,	  SHCMD("maim ~/media/images/screenshots/pic-full-$(date '+%d%m%y-%H%M-%s').png; notify-send -t 10000 'screenshot(full) saved'") }, */
// Multimedia Keys
	/* { MODKEY,			            XK_minus,		            spawn,	  SHCMD("pamixer --allow-boost -d 2; sigdwmblocks 5") }, */
	/* { MODKEY,			            XK_equal,		            spawn,	  SHCMD("pamixer --allow-boost -i 2; sigdwmblocks 5") }, */
	{ MODKEY,			            XK_minus,		            spawn,	  SHCMD("mpc volume -5") },
	{ MODKEY,			            XK_equal,		            spawn,	  SHCMD("mpc volume +5") },
	/* { 0,			                XF86XK_Display,		        spawn,	  SHCMD("displayselect") }, */
	{ 0,                            XF86XK_AudioMute,		    spawn,	  SHCMD("pamixer -t; sigdwmblocks 5") },
//	{ 0,                            XF86XK_TaskPane,		    spawn,    SHCMD(TERMINAL " -e htop") },
//	{ 0,                            XF86XK_MyComputer,		    spawn,	  SHCMD(TERMINAL " -e lf /") },
//	{ 0,                            XF86XK_AudioMicMute,		spawn,	  SHCMD("pamixer --default-source -t; sigdwmblocks 5") },
//	{ 0,                            XF86XK_ScreenSaver,	        spawn,	  SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
//	{ 0,                            XF86XK_PowerOff,		    spawn,    SHCMD("sysact") },
	{ MODKEY,						XK_p,						spawn,	  SHCMD("mpc toggle") },
	{ MODKEY,						XK_bracketleft,				spawn,	  SHCMD("mpc seek -10") },
	{ MODKEY|ShiftMask,			    XK_bracketleft,				spawn,	  SHCMD("mpc prev") },
	{ MODKEY|ShiftMask,			    XK_bracketright,			spawn,	  SHCMD("mpc next") },
	{ MODKEY,						XK_bracketright,			spawn,	  SHCMD("mpc seek +10") },
	{ MODKEY,						XK_backslash,				spawn,	  SHCMD("mpc repeat") },
	{ 0,                            XF86XK_AudioRaiseVolume,	spawn,	  SHCMD("pamixer --allow-boost -i 3; sigdwmblocks 5") },
	{ 0,                            XF86XK_AudioLowerVolume,	spawn,	  SHCMD("pamixer --allow-boost -d 3; sigdwmblocks 5") },
	{ 0,                            XF86XK_MonBrightnessUp,		spawn,	  SHCMD("xbacklight -inc 5") },
	{ 0,                            XF86XK_MonBrightnessDown,	spawn,	  SHCMD("xbacklight -dec 5") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[9]} },
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/yadav-dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,		    MODKEY,		    Button4,	    incrgaps,	    {.i = +1} },
	{ ClkClientWin,		    MODKEY,		    Button5,	    incrgaps,	    {.i = -1} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,    {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkRootWin,		    MODKEY,		    Button2,	    togglebar,	    {0} },
	{ ClkRootWin,		    ShiftMask,		Button1,	    spawn,	        SHCMD(TERMINAL " -e nvim ~/.local/src/st/config.h") },
	{ ClkRootWin,		    ShiftMask,		Button3,	    spawn,	        SHCMD(TERMINAL " -e nvim ~/.local/src/dwm/config.h") },
	{ ClkRootWin,		    0,		        Button2,	    spawn,	        SHCMD("sysact") },
//	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
};

