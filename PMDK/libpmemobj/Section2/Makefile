# CFLAGS REFERENCE: https://pmem.io/pmdk/manpages/linux/master/libpmemobj/libpmemobj.7/

CC=gcc
CFLAGS= -lpmemobj -lpmem
DEPS = layout.h 
OBJ = writer.o reader.o
EXEC = writer reader

all:
	$(CC) -std=gnu99 writer.c -o writer $(CFLAGS)
	$(CC) -std=gnu99 reader.c -o reader $(CFLAGS)

.PHONEY = clean

clean:
	rm -f $(EXEC)
