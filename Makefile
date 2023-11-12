default: all

all: main

main: main.c
	gcc -Wall main.c -lSDL2 -lSDL2main -o main

clean:
	rm -f main