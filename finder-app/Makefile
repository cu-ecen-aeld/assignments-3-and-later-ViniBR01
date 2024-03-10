CC=$(CROSS_COMPILE)gcc
CFLAGS=-I. -Wall
OBJ= writer.o

writer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f writer *.o
