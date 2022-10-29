CC = gcc
CFLAGS = -Wall -g -Werror -std=c99 -pedantic

all: main

main:
	$(CC) $(CFLAGS) src/game.c src/main.c src/color.c src/ordinateur.c -o bataille_navale

clean:
	rm -f main src/*.o
