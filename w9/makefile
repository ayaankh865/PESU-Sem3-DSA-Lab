CC     = gcc
CFLAGS = -Wall
TARGET = lab
SRCS   = client.c tree.c queue.c
HDRS   = tree.h queue.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean