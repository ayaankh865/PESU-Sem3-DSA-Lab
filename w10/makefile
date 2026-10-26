CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: graph_lab.out

graph_lab.out: client.o graph.o
	$(CC) $(CFLAGS) -o graph_lab.out client.o graph.o

client.o: client.c graph.h
	$(CC) $(CFLAGS) -c client.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

clean:
	rm -f graph_lab.out client.o graph.o

.PHONY: all clean
