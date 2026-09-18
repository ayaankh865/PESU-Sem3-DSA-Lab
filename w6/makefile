CC = gcc
CFLAGS = -Wall -Wextra

PARTA_TARGET = pothole_pq
PARTB_TARGET = queue_via_deque

.PHONY: all partA partB clean

all: partA partB

partA: $(PARTA_TARGET)
$(PARTA_TARGET): pqueue.c main.c
	$(CC) $(CFLAGS) pqueue.c main.c -o $(PARTA_TARGET)

partB: $(PARTB_TARGET)
$(PARTB_TARGET): deque.c queue.c main_queue.c
	$(CC) $(CFLAGS) deque.c queue.c main_queue.c -o $(PARTB_TARGET)

clean:
	rm -f $(PARTA_TARGET) $(PARTB_TARGET)