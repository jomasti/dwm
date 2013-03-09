/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-droid sans-medium-r-*-*-10-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#181818";
static const char normbgcolor[]     = "#181818";
static const char normfgcolor[]     = "#757575";
static const char selbordercolor[]  = "#181818";
static const char selbgcolor[]      = "#181818";
static const char selfgcolor[]      = "#93d44f";
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gappx     = 0;		/* gap between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool clicktofocus		  = True;		/* Focus client on click */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "luakit",   NULL,       NULL,       1,            False,        -1 },
  { "Chromium", NULL,       NULL,       1,            False,        -1 },
	{ "URxvt",    NULL,       NULL,       1 << 1,       False,        -1 },
	{ "Smplayer", NULL,		    NULL,		    1 << 2,	      True,		      -1 },
	{ "Zathura",  NULL,		    NULL,		    1 << 3,		    False,		    -1 },
  { "Nautilus", NULL,       NULL,       1 << 3,       False,        -1 },
  { "Skype",    NULL,       NULL,       1 << 4,       True,         -1 },
};

/* layout(s) */
static const int nmaster      = 1;    /* clients in the master area */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
        /* symbol     gaps       arrange function */
        { "[T]",      True,      tile },        /* first entry is default */
        { "[F]",      False,     NULL },        /* no layout function means floating behavior */
        { "[M]",      False,     monocle },
        { "[G]",      True,      gaplessgrid },
        { "[B]",      True,      bstack },
};

/* tagging */
static const Tag tags[] = {
	/* name       layout           mfact    nmaster */
	{ "web",      &layouts[3],     -1,      -1 },
	{ "term",     &layouts[3],     -1,      -1 },
	{ "media",    &layouts[1],     -1,      -1 },
	{ "file",     &layouts[2],     -1,    	-1 },
	{ "im",       &layouts[3],     -1,      -1 },
	{ "misc",	    &layouts[3],	   -1	      -1 },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *lockcmd[] = { "slock", NULL };
static const char *suspendcmd[] = { "systemctl", "suspend", NULL };
static const char *hibernatecmd[] = { "systemctl", "hibernate", NULL };
static const char *rebootcmd[] = { "systemctl", "reboot", NULL };
static const char *shutdowncmd[] = { "systemctl", "shutdown", NULL };

#include "selfrestart.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_a,      incnmaster,     {.i = +1} },
	{ MODKEY,                       XK_z,      incnmaster,     {.i = -1} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,      pushup,         {0} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ControlMask,           XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,			      XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,			      XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY|ControlMask,           XK_g,      setlayout,      {.v = &layouts[3]} },
  { MODKEY|ControlMask,           XK_b,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { MODKEY,                       XK_Left,   cycle,          {.i = -1} },
  { MODKEY,                       XK_Right,  cycle,          {.i = +1} },
  { MODKEY|ControlMask,           XK_Left,   tagcycle,       {.i = -1} },
  { MODKEY|ControlMask,           XK_Right,  tagcycle,       {.i = +1} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  { MODKEY|ShiftMask,             XK_r,      self_restart,   {0} },
	{ 0,                            XK_Pause,  spawn,          {.v = lockcmd} },
	{ ControlMask|ALTKEY,           XK_s,      spawn,          {.v = suspendcmd} },
	{ ControlMask|ALTKEY,           XK_h,      spawn,          {.v = hibernatecmd} },
	{ ControlMask|ALTKEY,           XK_r,      spawn,          {.v = rebootcmd} },
	{ ControlMask|ALTKEY,           XK_q,      spawn,          {.v = shutdowncmd} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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

