/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
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
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#EBDBB2";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#008080";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "lf", NULL };
const char *spcmd3[] = {"bitwarden", NULL };
const char *spcmd4[] = {"st", "-n", "spemacs", "-g", "144x41", "-e", "emacs", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spfm",        spcmd2},
	{"bitwarden",   spcmd3},
	{"spemacs",     spcmd4},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance       title           tags mask       isfloating  isterminal  noswallow  monitor */
	{ "Gimp",             NULL,          NULL,           0,              1,          0,           0,        -1 },
	{ "Firefox",          NULL,          NULL,           1 << 8,         0,          0,          -1,        -1 },
	{ "brave-browser",    NULL,          NULL,           1 << 8,         0,          0,          -1,        -1 },
	{ "St",               NULL,          NULL,           0,              0,          1,           0,        -1 },
	{ NULL,               NULL,          "Event Tester", 0,              0,          0,           1,        -1 }, /* xev */
	{ NULL,		          "spterm",	     NULL,		     SPTAG(0),		 1,		     1,           0,        -1 },
	{ NULL,		          "spfm",		 NULL,		     SPTAG(1),		 1,		     1,           0,        -1 },
	{ NULL,		          "bitwarden",	 NULL,		     SPTAG(2),		 1,		     1,           0,        -1 },
	{ NULL,		          "spemacs",	 NULL,		     SPTAG(3),		 1,		     1,           0,        -1 },
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
	{ "H[]",      deck },
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

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#include "shiftview.c"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };


static Key keys[] = {
	/* modifier                     key               function            argument */
	{ MODKEY|ShiftMask,             XK_Return,        spawn,              {.v = dmenucmd } },
	{ MODKEY,			            XK_Return,        spawn,              {.v = termcmd } },
	{ MODKEY,                       XK_b,             togglebar,          {0} },
	{ MODKEY|ShiftMask,             XK_b,             togglesystray,      {0} },
	{ MODKEY,                       XK_f,             togglefullscr,      {0} },
	{ MODKEY|ShiftMask,             XK_f,             togglefloating,     {0} },
	{ MODKEY,                       XK_g,             togglegaps,         {0} },
	{ MODKEY,                       XK_s,             togglesticky,       {0} },
	{ MODKEY,                       XK_j,             focusstack,         {.i = +1 } },
	{ MODKEY,                       XK_k,             focusstack,         {.i = -1 } },
	{ MODKEY,                       XK_o,             incnmaster,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,             incnmaster,         {.i = -1 } },
	{ MODKEY,                       XK_h,             setmfact,           {.f = -0.05} },
	{ MODKEY,                       XK_l,             setmfact,           {.f = +0.05} },
	{ MODKEY,                       XK_space,         zoom,               {0} },
	{ MODKEY|ShiftMask,             XK_k,             setcfact,           {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_j,             setcfact,           {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_BackSpace,     setcfact,           {.f =  0.00} },
	{ MODKEY|ControlMask,           XK_h,             incrgaps,           {.i = +1 } },
	{ MODKEY|ControlMask,           XK_l,             incrgaps,           {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_i,             incrigaps,          {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,             incrigaps,          {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_o,             incrogaps,          {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,             incrogaps,          {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_6,             incrihgaps,         {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,             incrihgaps,         {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_7,             incrivgaps,         {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,             incrivgaps,         {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_8,             incrohgaps,         {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,             incrohgaps,         {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_9,             incrovgaps,         {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,             incrovgaps,         {.i = -1 } },
	{ MODKEY|ControlMask,           XK_BackSpace,     defaultgaps,        {0} },
	{ MODKEY,                       XK_Tab,           view,               {0} },
	{ MODKEY,                       XK_q,             killclient,         {0} },
	{ MODKEY,                       XK_t,             setlayout,          {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_t,             setlayout,          {.v = &layouts[1]} },
	{ MODKEY,                       XK_y,             setlayout,          {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,             setlayout,          {.v = &layouts[3]} },
	{ MODKEY,                       XK_i,             setlayout,          {.v = &layouts[4]} },
	{ MODKEY,                       XK_y,             setlayout,          {.v = &layouts[5]} },
	{ MODKEY,                       XK_y,             setlayout,          {.v = &layouts[6]} },
	{ MODKEY,                       XK_F1,            setlayout,          {.v = &layouts[7]} },
	{ MODKEY,                       XK_F2,            setlayout,          {.v = &layouts[8]} },
	{ MODKEY,                       XK_F3,            setlayout,          {.v = &layouts[9]} },
	{ MODKEY,                       XK_F4,            setlayout,          {.v = &layouts[10]} },
	{ MODKEY,                       XK_F5,            setlayout,          {.v = &layouts[11]} },
	{ MODKEY,                       XK_F6,            setlayout,          {.v = &layouts[12]} },
//	{ MODKEY,                       XK_y,             setlayout,          {0} },
	{ MODKEY,                       XK_0,             view,               {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,             tag,                {.ui = ~0 } },
	{ MODKEY,                       XK_comma,         focusmon,           {.i = -1 } },
	{ MODKEY,                       XK_period,        focusmon,           {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,         tagmon,             {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,        tagmon,             {.i = +1 } },
	{ MODKEY,			            XK_p,	          shiftview,	      { .i = -1 } },
	{ MODKEY,			            XK_n,	          shiftview,	      { .i = 1 } },
	{ MODKEY,            			XK_z,  	          togglescratch,      {.ui = 0 } },
	{ MODKEY,            			XK_x,	          togglescratch,      {.ui = 1 } },
	{ MODKEY,            			XK_c,	          togglescratch,      {.ui = 2 } },
	TAGKEYS(                        XK_1,                                 0)
	TAGKEYS(                        XK_2,                                 1)
	TAGKEYS(                        XK_3,                                 2)
	TAGKEYS(                        XK_4,                                 3)
	TAGKEYS(                        XK_5,                                 4)
	TAGKEYS(                        XK_6,                                 5)
	TAGKEYS(                        XK_7,                                 6)
	TAGKEYS(                        XK_8,                                 7)
	TAGKEYS(                        XK_9,                                 8)
	{ MODKEY|ShiftMask,             XK_q,             quit,               {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

