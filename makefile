CC=cc
CFLAGS=-I -std=c99 -pedantic -Wall
OBJ = calendar.o

calendar: $(OBJ)
	$(CC) -o calendar $(OBJ)
	chmod 755 calendar
	./calendar

clean:
	rm -f *.o calendar