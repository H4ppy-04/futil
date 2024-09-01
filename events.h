#ifndef __EVENTS_H__
#define __EVENTS_H__

#include <X11/Xlib.h>

#include "window.h"

/* Event dispatcher and handler function.
*
* event: static instance of `XEvent`.
*/
void event_dispatcher( XWindow* win, XEvent* event );

#endif
