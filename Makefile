build:
	gcc main.c window.c events.c menu.c -ansi -I./ -lX11 -lm -o win

format:
	find . -name "*.c" -exec clang-format --style=GNU -i {} \;

clean:
	rm *.o win
