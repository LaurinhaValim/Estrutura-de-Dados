CC = gcc
CFLAGS = -Wall -std=c99

all: main

main: main.o OrderList.o
	$(CC) $(CFLAGS) -o main main.o OrderList.o

main.o: main.c OrderList.h
	$(CC) $(CFLAGS) -c main.c

OrderList.o: OrderList.c OrderList.h
	$(CC) $(CFLAGS) -c OrderList.c

clean:
	rm -f *.o main