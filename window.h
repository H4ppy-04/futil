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
#define DEF_WIN_FILL_C    0x000000     /* mustard yellow window fill */
#define DEF_WIN_BORDER_C  0x000000     /* window border color */
#define DEF_WIN_BORDER_W  2            /* window border stroke size */

struct XWinArgs {
    int win_parent_x;         /* win parent x */
    int win_parent_y;         /* win parent y */

    int win_width;            /* window width  */
    int win_height;           /* window height */

    int win_border_w;         /* window border width            */
    int win_border_c;         /* border colour (mustard yellow) */

    int win_fill_c;           /* window fill colour             */
};


typedef struct {
    Display* display;   /* display */
    Window   win;       /* window  */
    GC      gc;         /* graphics context */
} XWindow;

void win_init( XWindow* xwin );

/*
 * Wrapper for XCreateSimpleWindow
 */
void __XCreateSimpleWindow(XWindow* xwin, struct XWinArgs xargs);

/*
 * Unmap display and move display and window out of memory
 */
void __close( XWindow* xwin );

/*
 * Initialize default XWinArgs object with defaults.
 */
struct XWinArgs init_default_xargs();

#endif
