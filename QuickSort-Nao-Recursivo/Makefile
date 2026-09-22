CC = gcc
CFLAGS = -Wall -std=c99

all: main

main: main.o quickSort.o stack.o
	$(CC)$(CFLAGS) -o main main.o quickSort.o stack.o

main.o: main.c quickSort.h
	$(CC)$(CFLAGS) -c main.c

quickSort.o: quickSort.c quickSort.h stack.h
	$(CC)$(CFLAGS) -c quickSort.c

stack.o: stack.c stack.h
	$(CC)$(CFLAGS) -c stack.c

clean:
	rm -f *.o main