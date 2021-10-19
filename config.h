/* See LICENSE file for copyright and license details. */

/* appearance and bar */
static unsigned int borderpx = 2; /* border pixel of windows */
static unsigned int snap = 32;    /* snap pixel */
static const int swallowfloating =
    1; /* 1 means swallow floating windows by default */
static const unsigned int gappih = 10; /* horiz inner gap between windows */
static const unsigned int gappiv = 10; /* vert inner gap between windows */
static const unsigned int gappoh =
    10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    10; /* vert outer gap between windows and screen edge */
static int smartgaps =
    0;                  /* 1 means no outer gap when there is only one window */
static int showbar = 1; /* 0 means no bar */
static int topbar = 1;  /* 0 means bottom bar */
static const int usealtbar = 0;             /* 1 means use non-dwm status bar */
static const char *altbarclass = "Polybar"; /* Alternate bar class name */
static const char *alttrayname = "tray";    /* Polybar tray instance name */
/* static const char *altbarcmd        = "$HOME/.config/polybar/launch.sh";
 * Alternate bar launch command */
static const char *altbarcmd = "";
static const Bool viewontag = True; /* Switch view on tag switch */
// Fonts
static char font1[] = "fixed:size=12:antialias=true:autohint=true";
static char font2[] = "mononoki Nerd Font:size=12:antialias=true:autohint=true";
static char emojifont[] =
    "Noto Color Emoji:size=12:antialias=true:autohint=true";
/* static char *fonts[] = { */
/*     "fixed:size=12:antialias=true:autohint=true", */
/*     "mononoki Nerd Font:size=12:antialias=true:autohint=true", */
/*     "Noto Color Emoji:size=12:antialias=true:autohint=true"}; */
static char *fonts[] = {font1, font2, emojifont};
static char dmenufont[] = "fixed:size=10";

/* Colors and Transparency */
// background color
static char normbgcolor[] = "#2d3442";
// inactive window border color
static char normbordercolor[] = "#444444";
// font color
static char normfgcolor[] = "#ffffff";
// current tag and current window font color
static char selfgcolor[] = "#ffffff";
// Top bar second color (under window title) and active window border color
/* static const char col_cyan[]          = "#81a1c1"; //statusbar */
/* static const char col_cyan[]          = "#ff19ff"; */
static char selbordercolor[] = "#cc00cc";
/* static const char col_cyan2[]         = "#88c0d0"; //selected tags */
/* static const char col_cyan2[]         = "#cc00cc"; */
static char selbgcolor[] = "#ff19ff";
// Alphas: 20% transparent, 10% transparent, 0% transparent
/* static const unsigned int baralpha = 0xd0; */ 
static const unsigned int baralpha = 0xE6;
/* static const unsigned int baralpha = 0xff; */
static const unsigned int borderalpha = OPAQUE;
static char normmarkcolor[] = "#775500"; /*border color for marked client*/
static char selmarkcolor[] = "#e60053"; /*border color for marked client on focus*/

static char *colors[][4] = {
    /*               fg         bg         border     mark   */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor, normmarkcolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor, selmarkcolor},
    [SchemeStatus] = {normfgcolor, selbordercolor, "#000000", normmarkcolor}, // Statusbar right {text,background,not used but cannot be empty}
    [SchemeTagsSel] = {selfgcolor, selbgcolor, "#000000", selmarkcolor}, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm] = {normfgcolor, normbgcolor, "#000000", normmarkcolor}, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel] = {selfgcolor, normbgcolor, "#000000", selmarkcolor}, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm] = {normfgcolor, normbgcolor, "#000000", normmarkcolor}, // infobar middle  unselected {text,background,not used but cannot be empty}
};
static const unsigned int alphas[][4] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeStatus] = {OPAQUE, baralpha, borderalpha},
    [SchemeTagsSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeTagsNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeInfoSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeInfoNorm] = {OPAQUE, baralpha, borderalpha},
};

// Sticky Icon
static const XPoint stickyicon[] = { {0, 0}, {4, 0}, {4, 8}, {2, 6}, {0, 8}, {0, 0}}; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb = {4, 8}; /* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* tagging */
static const char *tags[] = {" ", " ", " ", " ", " ", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask  isfloating  isterminal noswallow  monitor    float x,y,w,h       floatborderpx */
    {"Alacritty", NULL, NULL, 0, 0, 1, 0, -1, 100, 100, 750, 750, 2},
    {"Alacritty", "editing", NULL, 0, 1, 1, 0, -1, 50, 50, 500, 500, 2},
    {"Anydesk", NULL, NULL, 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Brave-browser", NULL, NULL, 1 << 1, 0, 0, -1, 1, 50, 50, 500, 500, 2},
    {"cemu.exe", NULL, NULL, 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"discord", NULL, NULL, 1 << 3, 0, 0, -1, 1, 50, 50, 500, 500, 2},
    {"epicgameslauncher.exe", NULL, NULL, 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {NULL, NULL, "Event Tester", 0, 0, 0, 1, -1, 50, 50, 500, 500, 2}, /* xev */
    {"Firefox", NULL, NULL, 1 << 1, 0, 0, -1, 1, 50, 50, 500, 500, 2},
    {"firefox", NULL, NULL, 1 << 1, 0, 0, -1, 1, 50, 50, 500, 500, 2},
    /* { "flameshot", NULL,       NULL,       0,          1,  0,  -1,  -1, -1, -1, -1, -1,      2}, */
    {"Galculator", NULL, NULL, 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    /* { "Gimp",      NULL,       NULL,       0,          1,  0,   0,  -1, 50, 50,500,500,      2}, */
    {"Gnome-calculator", NULL, NULL, 0, 1, 0, 0, -1, 50, 50, 360, 402, 2},
    {"ksnip", NULL, NULL, 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"lunarclient", NULL, NULL, 1 << 2, 0, 0, -1, 0, -1, -1, -1, -1, 2},
    {"Lunar Client (", NULL, NULL, 1 << 2, 0, 0, -1, 0, -1, -1, -1, -1, 2},
    {"Minecraft Launcher", NULL, NULL, 1 << 2, 0, 0, -1, 0, -1, -1, -1, -1, 2},
    {"Minecraft* 1", NULL, NULL, 1 << 2, 0, 0, -1, 0, -1, -1, -1, -1, 2},
    {"Minecraft 1", NULL, NULL, 1 << 2, 0, 0, -1, 0, -1, -1, -1, -1, 2},
    {"NoiseTorch", NULL, NULL, 1 << 8, 0, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Pamac-manager", NULL, NULL, 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Pavucontrol", NULL, NULL, 0, 1, 0, 0, -1, 50, 50, 500, 500, 2},
    {"Spotify", NULL, NULL, 1 << 3, 0, 0, -1, 1, 50, 50, 500, 500, 2},
    {"Steam", NULL, NULL, 1 << 2, 0, 0, -1, 0, -1, -1, -1, -1, 2},
    {"Steam", NULL, "Steam - Self Updater", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, "Friends List", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, " - Chat", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, "Settings", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, " event started", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, " CD key", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, "Screenshot Uploader", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, "Steam Guard - Computer Authorization Required", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, "Steam Keyboard", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"Steam", NULL, "Steam - News", 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
    {"trayer", NULL, NULL, 0, 1, 0, 1, -1, 50, 50, 10, 10, 0},
    {"Yad", NULL, NULL, 0, 1, 0, -1, -1, -1, -1, -1, -1, 2},
};

/* layout(s) */
static float mfact = 0.50;  /* factor of master area size [0.05..0.95] */
static int nmaster = 1;     /* number of clients in master area */
static int resizehints = 1; /* 1 means respect size hints in tiled resizals */
static const int attachdirection = 0; /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */
#define FORCE_VSPLIT 1 /* nrowgrid layout: force two clients to always split vertically */
#include "tagall.c"
#include "vanitygaps.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
    {"[D]", deck},
    {"|M|", centeredmaster},
    {">M>", centeredfloatingmaster},
    {"[@]", spiral},
    {"[\\]", dwindle},
    {"TTT", bstack},
    {"===", bstackhoriz},
    {"HHH", grid},
    {":::", gaplessgrid},
    {"###", nrowgrid},
    {"---", horizgrid},
    {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(CHAIN, KEY, TAG)                                                  \
  {MODKEY, CHAIN, KEY, view, {.ui = 1 << TAG}},                                   \
  {MODKEY | ControlMask, CHAIN, KEY, toggleview, {.ui = 1 << TAG}},               \
  {MODKEY | Mod1Mask | ControlMask, CHAIN, KEY, swaptags, {.ui = 1 << TAG}},      \
  {MODKEY | ShiftMask, CHAIN, KEY, tag, {.ui = 1 << TAG}},                        \
  {MODKEY | ControlMask | ShiftMask, CHAIN,  KEY,   toggletag,  {.ui = 1 << TAG}},\
  {MODKEY | Mod1Mask, CHAIN, KEY, tagnextmon, {.ui = 1 << TAG}},                  \
  {MODKEY | Mod1Mask | ShiftMask, CHAIN, KEY, tagprevmon, {.ui = 1 << TAG}},      \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) {.v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }}
#include "shiftviewclients.c"
#include <X11/XF86keysym.h>
#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m",  dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor,  NULL};
/* static const char *logoutcmd[] = {"$HOME/.config/scripts/shutdown_menu", NULL}; */
/* static const char *polybar[] = {"$HOME/.config/polybar/launch.sh", NULL}; */
static const char *roficmd[] = {"rofi",  "-modi", "window,ssh,drun,run", "-show", "drun",  NULL};
static const char scratchpadname[] = "scratchpad";
// static const char *scratchpadcmd[] = { "alacritty", "-t", scratchpadname, "-d", "120", "34", NULL };
static const char *scratchpadcmd[] = {"alacritty", "-t", scratchpadname, NULL};
static const char *screenshot[] = {"flameshot", "gui", NULL};
static const char *termcmd[] = {"st", NULL};
static const char *trayer[] = {"trayer", "--widthtype", "pixel", "--width", "20",     "--height",    "20",    "--align", "right",  "--edge",      "top",   NULL};
static const char *volcontrol[] = {"pavucontrol", NULL};

// Media functions //
// static const char *upvol[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "5%+", NULL};
// static const char *downvol[] = { "amixer", "-q","-D", "pulse", "sset", "Master", "5%-", NULL};
// static const char *mutevol[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "toggle", NULL};
static const char *playpause[] = {"playerctl", "play-pause", NULL};
static const char *playnext[] = {"playerctl", "next", NULL};
static const char *playprev[] = {"playerctl", "previous", NULL};
// static const char *brightup[] = { "light", "-A", "5", NULL};
// static const char *brightdown[] = { "light", "-U", "5", NULL};

// Custom functions
void resetnmaster(const Arg *arg);

// Xresources preferences to load at startup
ResourcePref resources[] = {
    {"dwmfont", STRING, &font1},
    {"dwmfontalt", STRING, &font2},
    {"fontemoji", STRING, &emojifont},
    {"dmenufont", STRING, &dmenufont},
    {"normbgcolor", STRING, &normbgcolor},
    {"normbordercolor", STRING, &normbordercolor},
    {"normfgcolor", STRING, &normfgcolor},
    {"selbgcolor", STRING, &selbgcolor},
    {"selbordercolor", STRING, &selbordercolor},
    {"selfgcolor", STRING, &selfgcolor},
    {"borderpx", INTEGER, &borderpx},
    {"snap", INTEGER, &snap},
    {"showbar", INTEGER, &showbar},
    {"topbar", INTEGER, &topbar},
    {"nmaster", INTEGER, &nmaster},
    {"resizehints", INTEGER, &resizehints},
    {"mfact", FLOAT, &mfact},
};

static Key keys[] = {
    /* modifier          chainkey   key        function        argument */
    // Program launching
    {MODKEY, -1, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, -1, XK_grave, togglescratch, {.v = scratchpadcmd}},
    {MODKEY | ShiftMask, -1, XK_b, togglebar, {0}},
    /* { MODKEY|ControlMask, -1,          XK_b,      spawn,          SHCMD("$XDG_CONFIG_HOME/polybar/launch.sh") }, */
    {MODKEY | ShiftMask, -1, XK_v, spawn, {.v = volcontrol}},
    {0, -1, XK_Print, spawn, {.v = screenshot}},
    {MODKEY | ShiftMask, -1, XK_p, spawn, {.v = trayer}},

    // Rofi/dmenu
    {MODKEY, -1, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY, -1, XK_d, spawn, {.v = roficmd}},
    {MODKEY | ShiftMask, XK_d, XK_e, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/dmconf")},
    {MODKEY | ShiftMask, XK_d, XK_s, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/dmsearch")},
    {MODKEY | ShiftMask, XK_d, XK_x, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/dmkill")},
    {MODKEY | ShiftMask, XK_d, XK_n, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/dmnotes")},
    /* { MODKEY|ShiftMask,   XK_d,   XK_apostrophe,  spawn, SHCMD("rofimoji") }, */
    {MODKEY | ShiftMask, XK_d, XK_apostrophe, spawn, SHCMD("rofi -show emoji -modi emoji")},
    {MODKEY | ShiftMask, XK_d, XK_b, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/backgroundswitcher")},
    {MODKEY | ShiftMask, XK_d, XK_t, spawn, SHCMD("~/themes/themes.sh")},

    // Stack Movement
    {MODKEY, -1, XK_j, focusstack, {.i = +1}},
    {MODKEY, -1, XK_k, focusstack, {.i = -1}},
    {MODKEY | ShiftMask, -1, XK_j, rotatestack, {.i = +1}},
    {MODKEY | ShiftMask, -1, XK_k, rotatestack, {.i = -1}},
    {MODKEY, -1, XK_y, switchcol, {0}},
    {MODKEY, -1, XK_i, incnmaster, {.i = +1}},
    {MODKEY, -1, XK_o, incnmaster, {.i = -1}},
    {MODKEY, -1, XK_u, focusmaster, {0}},
    {MODKEY | ShiftMask, -1, XK_o, resetnmaster, {0}},
    {MODKEY, -1, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, -1, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, -1, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, -1, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, -1, XK_o, setcfact, {.f = 0.00}},
    {MODKEY | ControlMask, -1, XK_j, inplacerotate, {.i = +1}},
    {MODKEY | ControlMask, -1, XK_k, inplacerotate, {.i = -1}},
    {MODKEY, -1, XK_semicolon, togglemark, {0}},
    {MODKEY, -1, XK_bracketleft, markfocus, {0}},
    {MODKEY, -1, XK_s, swapfocus, {0}},
    {MODKEY | ShiftMask, -1, XK_bracketleft, swapclient, {0}},
    {MODKEY | ShiftMask, -1, XK_u, zoom, {0}},
    {MODKEY | ShiftMask, -1, XK_q, killclient, {0}},

    //  Layouts
    {MODKEY, XK_r, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_r, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_r, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_r, XK_d, setlayout, {.v = &layouts[3]}},
    {MODKEY, XK_r, XK_c, setlayout, {.v = &layouts[4]}},
    {MODKEY, XK_r, XK_v, setlayout, {.v = &layouts[5]}},
    {MODKEY, XK_r, XK_s, setlayout, {.v = &layouts[6]}},
    {MODKEY, XK_r, XK_a, setlayout, {.v = &layouts[7]}},
    {MODKEY, XK_r, XK_b, setlayout, {.v = &layouts[8]}},
    {MODKEY, XK_r, XK_n, setlayout, {.v = &layouts[9]}},
    {MODKEY, XK_r, XK_g, setlayout, {.v = &layouts[10]}},
    {MODKEY, XK_r, XK_h, setlayout, {.v = &layouts[11]}},
    {MODKEY, XK_r, XK_k, setlayout, {.v = &layouts[12]}},
    {MODKEY, XK_r, XK_l, setlayout, {.v = &layouts[13]}},
    {MODKEY, XK_r, XK_r, resetlayout, {0}},
    {MODKEY | ControlMask, -1, XK_comma, cyclelayout, {.i = -1}},
    {MODKEY | ControlMask, -1, XK_period, cyclelayout, {.i = +1}},
    {MODKEY, -1, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, -1, XK_space, togglefloating, {0}},
    {MODKEY, -1, XK_f, togglefullscr, {0}},
    {MODKEY | ShiftMask, -1, XK_s, togglesticky, {0}},

    // Gaps
    {MODKEY | Mod1Mask, -1, XK_u, incrgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_u, incrgaps, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_i, incrigaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_i, incrigaps, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_o, incrogaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_o, incrogaps, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_9, incrovgaps, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_0, togglegaps, {0}},
    {MODKEY | Mod1Mask | ShiftMask, -1, XK_0, defaultgaps, {0}},

    // Media Keys
    /* { 0,                  -1,          XF86XK_AudioLowerVolume, spawn, {.v = downvol } }, */
    /* { 0,                  -1,          XF86XK_AudioMute,        spawn, {.v = mutevol } }, */
    /* { 0,                  -1,          XF86XK_AudioRaiseVolume, spawn, {.v = upvol } }, */
    {0, -1, XF86XK_AudioMute, spawn, SHCMD("pamixer -t; pkill -RTMIN+2 dwmblocks")},
    {0, -1, XF86XK_AudioRaiseVolume, spawn, SHCMD("pamixer -i 5; pkill -RTMIN+2 dwmblocks")},
    {0, -1, XF86XK_AudioLowerVolume, spawn, SHCMD("pamixer -d 5; pkill -RTMIN+2 dwmblocks")},
    /* { MODKEY, 	     	  -1,		   XK_F6, spawn, SHCMD("micmute; pkill -RTMIN+3 dwmblocks") }, */
    /* { MODKEY,    	      -1,		   XK_F8, spawn, SHCMD("micvolincrease; pkill -RTMIN+3 dwmblocks") }, */
    /* { MODKEY,    		  -1,		   XK_F7, spawn, SHCMD("micvoldecrease; pkill -RTMIN+3 dwmblocks") }, */
    {MODKEY, -1, XK_Home, spawn, SHCMD("micmute; pkill -RTMIN+3 dwmblocks")},
    {MODKEY, -1, XK_Prior, spawn, SHCMD("micvolincrease; pkill -RTMIN+3 dwmblocks")},
    {MODKEY, -1, XK_Next, spawn, SHCMD("micvoldecrease; pkill -RTMIN+3 dwmblocks")},
    {0, -1, XF86XK_AudioPlay, spawn, {.v = playpause}},
    {0, -1, XF86XK_AudioPause, spawn, {.v = playpause}},
    {0, -1, XF86XK_AudioNext, spawn, {.v = playnext}},
    {0, -1, XF86XK_AudioPrev, spawn, {.v = playprev}},
    /* { 0,                  -1,          XF86XK_MonBrightnessUp,   spawn, {.v = brightup } }, */
    /* { 0,                  -1,          XF86XK_MonBrightnessDown, spawn, {.v = brightdown } }, */
    /* { 0,                  -1,          XF86XK_MonBrightnessUp,   spawn, SHCMD("light -A 5; pkill -RTMIN+6 dwmblocks") }, */
    /* { 0,                  -1,          XF86XK_MonBrightnessDown, spawn, SHCMD("light -U 5; pkill -RTMIN+6 dwmblocks") }, */
    /* { MODKEY,             -1,          XK_F4,                   spawn, SHCMD("toggletouchpad") }, */

    // Tag Movement
    {MODKEY, -1, XK_0, view, {.ui = ~0}},
    {MODKEY, -1, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, -1, XK_Tab, spawn, SHCMD("skippy-xd")},
    {MODKEY | ShiftMask, -1, XK_0, tag, {.ui = ~0}},
    {MODKEY, -1, XK_comma, focusmon, {.i = -1}},
    {MODKEY, -1, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, -1, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, -1, XK_period, tagmon, {.i = +1}},
    {MODKEY | ControlMask, -1, XK_comma, tagswapmon, {.i = -1}},
    {MODKEY | ControlMask, -1, XK_period, tagswapmon, {.i = +1}},
    {MODKEY | Mod1Mask, -1, XK_comma, tagallmon, {.i = -1}},
    {MODKEY | Mod1Mask, -1, XK_period, tagallmon, {.i = +1}},
    {MODKEY, -1, XK_n, shiftviewclients, {.i = +1}},
    {MODKEY, -1, XK_b, shiftviewclients, {.i = -1}},
    {MODKEY, -1, XK_Left, viewtoleft, {0}},
    {MODKEY, -1, XK_Right, viewtoright, {0}},
    {MODKEY | ShiftMask, -1, XK_Left, tagtoleft, {0}},
    {MODKEY | ShiftMask, -1, XK_Right, tagtoright, {0}},
    {MODKEY | ShiftMask, -1, XK_F1, tagall, {.v = "1"}},
    {MODKEY | ShiftMask, -1, XK_F2, tagall, {.v = "2"}},
    {MODKEY | ShiftMask, -1, XK_F3, tagall, {.v = "3"}},
    {MODKEY | ShiftMask, -1, XK_F4, tagall, {.v = "4"}},
    {MODKEY | ShiftMask, -1, XK_F5, tagall, {.v = "5"}},
    {MODKEY | ShiftMask, -1, XK_F6, tagall, {.v = "6"}},
    {MODKEY | ShiftMask, -1, XK_F7, tagall, {.v = "7"}},
    {MODKEY | ShiftMask, -1, XK_F8, tagall, {.v = "8"}},
    {MODKEY | ShiftMask, -1, XK_F9, tagall, {.v = "9"}},
    TAGKEYS(-1, XK_1, 0) TAGKEYS(-1, XK_2, 1) TAGKEYS(-1, XK_3, 2)
        TAGKEYS(-1, XK_4, 3) TAGKEYS(-1, XK_5, 4) TAGKEYS(-1, XK_6, 5)
            TAGKEYS(-1, XK_7, 6) TAGKEYS(-1, XK_8, 7) TAGKEYS(-1, XK_9, 8)

    // Quit DWM
    {MODKEY | ShiftMask, -1, XK_z, quit, {0}},
    {MODKEY | ControlMask | ShiftMask, -1, XK_q, quit, {1}},
    {MODKEY, -1, XK_z, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/shutdown_menu")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button1, sigstatusbar, {.i = 1}},
    {ClkStatusText, 0, Button2, sigstatusbar, {.i = 2}},
    {ClkStatusText, 0, Button3, sigstatusbar, {.i = 3}},
    {ClkStatusText, 0, Button4, sigstatusbar, {.i = 4}},
    {ClkStatusText, 0, Button5, sigstatusbar, {.i = 5}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
// Reset nmaster function definition
void resetnmaster(const Arg *arg) {
  selmon->nmaster = 1;
  arrange(selmon);
}
// IPC commands
static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
    IPCCOMMAND(view, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(toggleview, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(tag, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(toggletag, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(tagmon, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(focusmon, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(focusstack, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(zoom, 1, {ARG_TYPE_NONE}),
    IPCCOMMAND(incnmaster, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(killclient, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(togglefloating, 1, {ARG_TYPE_NONE}),
    IPCCOMMAND(setmfact, 1, {ARG_TYPE_FLOAT}),
    IPCCOMMAND(setlayoutsafe, 1, {ARG_TYPE_PTR}),
    IPCCOMMAND(quit, 1, {ARG_TYPE_NONE})};
