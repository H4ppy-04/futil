#ifndef __WINDOW_H__
#define __WINDOW_H__  1

#include <unistd.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#define WINRATE    500          /* update time in microseconds 0.05 ms */
#define X_NAME     "XWindow"    /* X window storename value */

/* XWinArgs defaults */
#define DEF_WIN_WIDTH     1200         /* default window width */
#define DEF_WIN_HEIGHT    800          /* default window height */
#define DEF_WIN_FILL_C    0xFFDD00     /* mustard yellow window fill */
#define DEF_WIN_BORDER_C  0x000000     /* window border color */
#define DEF_WIN_BORDER_W  2            /* window border stroke size */

typedef struct {
    unsigned int win_parent_x;         /* win parent x */
    unsigned int win_parent_y;         /* win parent y */

    unsigned int win_width;            /* window width  */
    unsigned int win_height;           /* window height */

    unsigned int win_border_w;         /* border width                   */
    unsigned int win_border_c;         /* border colour (mustard yellow) */

    unsigned int win_fill_c;           /* window fill colour             */
} XWinArgs;


typedef struct {
    Display* display;   /* display */
    Window   win;       /* window  */
    GC      gc;         /* graphics context */
} XWindow;

void win_init( XWindow* xwin );

/*
 * Wrapper for XCreateSimpleWindow
 */
void __XCreateSimpleWindow(XWindow* xwin, XWinArgs xargs);

/*
 * Unmap display and move display and window out of memory
 */
void __close( XWindow* xwin );

/*
 * Initialize default XWinArgs object with defaults.
 */
XWinArgs init_default_xargs();

#endif
