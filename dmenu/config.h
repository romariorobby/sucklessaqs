/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 500;                    /* minimum width when centered */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=10",
	"AppleEmoji:pixelsize=10:antialias=true:autohint=true",
	"JoyPixels:pixelsize=10:antialias=true:autohint=true",
	"Hasklug Nerd Font:size=10",
	"Siji:size=10"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	          /*     fg         bg       */
	[SchemeNorm] = { "#ebdbb2", "#141414" },
	[SchemeSel] = { "#008080", "#141414" },
	[SchemeSelHighlight] = { "#00ffff", "#141414" },
	[SchemeNormHighlight] = { "#ffc978", "#222222" },
	[SchemeNormBorder] = { "#008080", "#008080" },
	[SchemeOut] = { "#008080", "#ff0000" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
/* size of the window border */
static const unsigned int border_width = 1;
