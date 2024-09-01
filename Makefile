build:
	gcc main.c window.c events.c menu.c -ansi -I./ -lX11 -lm -o win
