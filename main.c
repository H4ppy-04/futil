#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "events.h"
#include "window.h"

/* xevent holder */
static XEvent m_event;

int
main ()
{
  XWindow *xwin;

  struct XWinArgs *xargs = malloc (sizeof (struct XWinArgs));
  init_default_xargs (xargs);

  __XCreateSimpleWindow (xwin, *xargs);
  win_init (xwin);

  /* an emergency break is always nice */
  bool do_loop = true;

  while (do_loop)
    {
      event_dispatcher (xwin, &m_event);
      XFlushGC (xwin->display, xwin->gc);
      XFlush (xwin->display); /* flush events to display */
      usleep (WINRATE);       /* set a somewhat normal frame rate */
    }

  __close (xwin);
}
