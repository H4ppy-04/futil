#include "events.h"


void event_dispatcher( XWindow* win, XEvent* event ) {
    if (event == NULL) {
        /*
         * This can potentially happen when window is first opened and may
         * happen in future events as well.
         */
        return;
    }

    XNextEvent(win->display, event);

    switch (event->type) {
        case Expose:
            if (event->xexpose.count > 0)
                break;
        case ButtonPress:
            switch (event->xbutton.button) {
                case Button1:
                    /* highlight file if present */
                    ;
                case Button2:
                    /* invoke menu
                     * FIXME: this isn't drawing to screen yet, possibly due to
                     * GC not being flushed? Also possible that the stroke color is
                     * also black 🤷
                     */
                    XDrawRectangle(win->display, win->win, win->gc, event->xbutton.x, event->xbutton.y, 50, 100);
                    break;
                default:
                    /* any other button */
                    break;
            }
        default:
            break;
    }
}

