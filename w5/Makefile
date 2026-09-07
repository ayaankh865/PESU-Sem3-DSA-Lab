CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
.PHONY: all clean step1 step2

all: step1 step2

step1: client1
step2: client2

client1: client1.o clist.o
	$(CC) $(CFLAGS) -o $@ $^

client2: client2.o clist.o
	$(CC) $(CFLAGS) -o $@ $^

client1.o: client1.c clist.h
	$(CC) $(CFLAGS) -c client1.c

client2.o: client2.c clist.h
	$(CC) $(CFLAGS) -c client2.c

clist.o: clist.c clist.h
	$(CC) $(CFLAGS) -c clist.c

clean:
	rm -f *.o client1 client2