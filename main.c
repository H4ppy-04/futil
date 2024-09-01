#include <X11/X.h>
#include <unistd.h>
#include <X11/Xlib.h>

#include "window.h"
#include "events.h"

/* xevent holder */
static XEvent m_event;

int main() {
    XWindow* xwin;

    /* TODO: implement init_default_xargs() if this is all default stuff */
    XWinArgs xargs = {
        .win_parent_x  = 0,
        .win_parent_y  = 0,
        .win_width     = DEF_WIN_WIDTH,
        .win_height    = DEF_WIN_HEIGHT,
        .win_fill_c    = DEF_WIN_FILL_C,
        .win_border_w  = DEF_WIN_BORDER_W,
    };

    __XCreateSimpleWindow(xwin, xargs);
    win_init(xwin);

    while (1) {
        event_dispatcher(xwin, &m_event);

        XFlushGC(xwin->display, xwin->gc);
        XFlush(xwin->display);   /* flush events to display */
        usleep(WINRATE);        /* set a somewhat normal frame rate */
    }

    __close(xwin);
}
