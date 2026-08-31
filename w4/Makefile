CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g
LDLIBS  = -lm

COMMON_OBJS = term.o poly.o

.PHONY: all clean run-add run-integrate

all: poly_add poly_integrate

poly_add: client_add.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

poly_integrate: client_integrate.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c term.h poly.h
	$(CC) $(CFLAGS) -c $< -o $@

run-add: poly_add
	./poly_add

run-integrate: poly_integrate
	./poly_integrate

clean:
	rm -f *.o poly_add poly_integrate