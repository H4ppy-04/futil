#include "window.h"
#ifndef __MENU_H__
#define __MENU_H__  1

#include <stdbool.h>

/* Draw interactive menu for a given file.
 *
 * on_file: the mouse is hovering over a directory or file.
 *
 * */
void draw_menu(XWindow xwin, bool on_file);

#endif
