CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: infixtopostfix.out evaluatepostfix.out

infixtopostfix.out: stack1.c infixtopostfix.c stack1.h
	$(CC) $(CFLAGS) stack1.c infixtopostfix.c -o infixtopostfix.out

evaluatepostfix.out: stack2.c evaluatepostfix.c stack2.h
	$(CC) $(CFLAGS) stack2.c evaluatepostfix.c -lm  -o evaluatepostfix.out

clean:
	rm -f infixtopostfix.out evaluatepostfix.out