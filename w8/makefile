CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = bst

$(TARGET): main.o tree.o stack.o
	$(CC) $(CFLAGS) -o $(TARGET).out main.o tree.o stack.o

main.o: main.c tree.h
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c tree.h stack.h
	$(CC) $(CFLAGS) -c tree.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o $(TARGET).out