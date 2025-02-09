FLAGS = -Wall -Wextra -O3
LIBS = -lSDL2 -lSDL2_ttf

powermenu: main.c powermenu.c powermenu.h
	gcc $(FLAGS) $(LIBS) main.c powermenu.c -o powermenu

install: powermenu
	sudo cp powermenu /bin
