CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = er_system

$(TARGET): main.o patient.o
	$(CC) $(CFLAGS) -o $(TARGET).out main.o patient.o

main.o: main.c patient.h
	$(CC) $(CFLAGS) -c main.c

patient.o: patient.c patient.h
	$(CC) $(CFLAGS) -c patient.c

clean:
	rm -f $(TARGET).out *.o