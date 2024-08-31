#include <X11/X.h>
#include <unistd.h>
#include <X11/Xlib.h>

#include "window.h"

/* xevent holder */
static XEvent m_event;

void event_dispatcher( XWindow* win ) {
    XNextEvent(win->display, &m_event);
    switch (m_event.type) {
        case Expose:
            if (m_event.xexpose.count > 0)
                break;
        case ButtonPress:
            switch (m_event.xbutton.button) {
                case Button1:
                    /* highlight file if present */
                    ;
                case Button2:
                    /* invoke menu */
                    XDrawRectangle(win->display, win->win, win->gc, m_event.xbutton.x, m_event.xbutton.y, 50, 100);
                    break;
                default:
                    /* any other button */
                    break;
            }
        default:
            break;
    }
}

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
        event_dispatcher(xwin);

        XFlush(xwin->display);   /* flush events to display */
        usleep(WINRATE);        /* set a somewhat normal frame rate */
    }

    __close(xwin);
}
