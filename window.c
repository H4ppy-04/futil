#include "window.h"
#include <stdio.h>

void win_init(XWindow* win) {
    XStoreName(win->display, win->win, X_NAME);   /* set window name */

    /*
     * Create graphics context.
     */
    win->gc = XCreateGC(
        win->display,     /* display    */
        win->win,         /* drawable   */
        0,                /* value mask */
        NULL);            /* XGC values */

    /*
     * Make window visible to display.
     */
    XMapWindow(win->display, win->win);     /* bind window to X display */
    XFlush(win->display);                   /* flush pending requests   */

    /* 20ms event buffer for assignment before starting dispatcher */
    usleep(20000);
}

void __XCreateSimpleWindow(XWindow* xwin, XWinArgs xargs) {
    Display *display;
    Window   win;
    GC       gc;

    xwin->display = XOpenDisplay(NULL);  /* display name re-assigned after XCreateSimpleWindow call */

    xwin->win = XCreateSimpleWindow(xwin->display,
                                   RootWindow(xwin->display, 0),
                                   xargs.win_parent_x, xargs.win_parent_y,
                                   xargs.win_width, xargs.win_height,
                                   xargs.win_border_w,
                                   xargs.win_border_c,
                                   xargs.win_fill_c);
}

/* FIXME: for some reason this doesn't work and results in a segfault.
 *
 * Double check that all the values are accurate and correspond correctly
 */
XWinArgs init_default_xargs() {
    XWinArgs xargs = {
        .win_parent_x  = 0,
        .win_parent_y  = 0,
        .win_width     = DEF_WIN_WIDTH,
        .win_height    = DEF_WIN_HEIGHT,
        .win_fill_c    = DEF_WIN_FILL_C,
        .win_border_c  = DEF_WIN_BORDER_C,
    };
    return xargs;
}

void __close(XWindow* xwin) {
    XFreeGC(xwin->display, xwin->gc);                  /* free graphics context            */
    XUnmapWindow(xwin->display, xwin->win);            /* unmap window from display        */
    XDestroyWindow(xwin->display, xwin->win);          /* remove window from memory        */
    XFlush(xwin->display);                             /* flush any pending rogue requests */
    XCloseDisplay(xwin->display);                      /* close display on x server        */
}
