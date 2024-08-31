#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>

#include "window.h"

void event_dispatcher( XWindow* win ) {
    getchar();              /* wait for user input */
    XFlush(win->display);   /* flush events to display */
    usleep(WINRATE);        /* set a somewhat normal frame rate */
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

    /* start main event dispatcher loop */
    event_dispatcher(xwin);

    __close(xwin);
}
