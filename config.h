/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "$HOME/.config/polybar/launch.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "monospace:size=10",
					"mononoki Nerd Font:size=9:antialias=true:autohint=true",
					"Hack:size=8:antialias=true:autohint=true",
					"Noto Color Emoji:size=10:antialias=true:autohint=true"
                                      };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor    float x,y,w,h       floatborderpx */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1,        50,50,500,500,      2},
	{ "Firefox",  NULL,       NULL,       2,            0,           -1,        50,50,500,500,      2},
	{ "Pavucontrol", NULL,    NULL,       0,            1,           -1,        50,50,500,500,      2},
	{ "Alacritty", "editing", NULL,       0,            1,           -1,        50,50,500,500,      2},
	{ "Gnome-calculator", NULL, NULL,     0,            1,           -1,        50,50,360,402,      2},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachdirection = 0;    /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

#include "layouts.c"
#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
       { MODKEY,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
       { MODKEY|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
       { MODKEY|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
       { MODKEY|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#include <X11/XF86keysym.h>
#include "shiftview.c"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *roficmd[] = { "rofi", "-modi", "window,ssh,drun,run", "-show", "drun", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *logoutcmd[] = { "/home/albi/.config/scripts/shutdown_menu", NULL };
static const char *upvol[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "5%+", NULL};
static const char *downvol[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "5%-", NULL};
static const char *mutevol[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "toggle", NULL};
static const char *playpause[] = { "playerctl", "play-pause", NULL};
static const char *playnext[] = { "playerctl", "next", NULL};
static const char *playprev[] = { "playerctl", "previous", NULL};
static const char *brightup[] = { "light", "-A", "5", NULL};
static const char *brightdown[] = { "light", "-U", "5", NULL};
static const char *screenshot[] = { "flameshot", "gui", NULL};
static const char *volcontrol[] = { "pavucontrol", NULL};
static const char *polybar[] = { "/home/albi/.config/polybar/launch.sh", NULL};
static Key keys[] = {
	/* modifier          chainkey   key        function        argument */
	{ MODKEY,             -1,          XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,             -1,          XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,	      -1,          XK_d,      spawn,          {.v = roficmd } },
	{ MODKEY|ShiftMask,   XK_d,        XK_e,      spawn,          SHCMD("/home/albi/dmscripts/dmconf") },
	{ MODKEY|ShiftMask,   XK_d,        XK_b,      spawn,          SHCMD("/home/albi/dmscripts/dmsearch") },
	{ MODKEY|ShiftMask,   XK_d,        XK_x,      spawn,          SHCMD("/home/albi/dmscripts/dmkill") },
	{ MODKEY|ShiftMask,   XK_d,        XK_apostrophe,  spawn,     SHCMD("rofimoji") },
	{ MODKEY|ShiftMask,   -1,          XK_b,      togglebar,      {0} },
	{ MODKEY|ControlMask, -1,          XK_b,      spawn,          {.v = polybar } },
	{ MODKEY,             -1,          XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,             -1,          XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,   -1,          XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,   -1,          XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,             -1,          XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,             -1,          XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,             -1,          XK_y,      focusmaster,    {0} },
	{ MODKEY,             -1,          XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,             -1,          XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask, -1,          XK_Return, zoom,           {0} },
	{ MODKEY,             -1,          XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,   -1,          XK_q,      killclient,     {0} },
	{ MODKEY,             -1,          XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,             -1,          XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,             -1,          XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,             -1,          XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,             -1,          XK_c,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,   -1,          XK_c,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ControlMask, -1,          XK_r,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY|ShiftMask,   -1,          XK_r,      setlayout,      {.v = &layouts[7]} },
        { MODKEY|ControlMask, -1,          XK_comma,  cyclelayout,    {.i = -1 } },
        { MODKEY|ControlMask, -1,          XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,             -1,          XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,   -1,          XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,   -1,          XK_f,      togglefullscr,  {0} },
	{ MODKEY,             -1,          XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,   -1,          XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,             -1,          XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,             -1,          XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,   -1,          XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,   -1,          XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,             -1,          XK_n,      shiftview,      {.i = +1 } },
	{ MODKEY,             -1,          XK_b,      shiftview,      {.i = -1 } },
	{ MODKEY,             -1,          XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,             -1,          XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,   -1,          XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,   -1,          XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
	{ MODKEY|ShiftMask,   -1,          XK_v,      spawn,          {.v = volcontrol } },
	{ 0,                  -1,          XK_Print,  spawn,          {.v = screenshot } },
	{ 0,                  -1,          XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                  -1,          XF86XK_AudioMute,        spawn, {.v = mutevol } },
	{ 0,                  -1,          XF86XK_AudioRaiseVolume, spawn, {.v = upvol } },
	{ 0,                  -1,          XF86XK_AudioPlay,        spawn, {.v = playpause } },
	{ 0,                  -1,          XF86XK_AudioPause,       spawn, {.v = playpause } },
	{ 0,                  -1,          XF86XK_AudioNext,        spawn, {.v = playnext } },
	{ 0,                  -1,          XF86XK_AudioPrev,        spawn, {.v = playprev } },
	{ 0,                  -1,          XF86XK_MonBrightnessUp,  spawn, {.v = brightup } },
	{ 0,                  -1,          XF86XK_MonBrightnessDown, spawn, {.v = brightdown } },
	TAGKEYS(              -1,          XK_1,                      0)
	TAGKEYS(              -1,          XK_2,                      1)
	TAGKEYS(              -1,          XK_3,                      2)
	TAGKEYS(              -1,          XK_4,                      3)
	TAGKEYS(              -1,          XK_5,                      4)
	TAGKEYS(              -1,          XK_6,                      5)
	TAGKEYS(              -1,          XK_7,                      6)
	TAGKEYS(              -1,          XK_8,                      7)
	TAGKEYS(              -1,          XK_9,                      8)
	{ MODKEY|ShiftMask,   -1,          XK_z,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, -1,  XK_q,      quit,           {1} },
	{ MODKEY,             -1,          XK_z,      spawn,         {.v = logoutcmd } }
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
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

