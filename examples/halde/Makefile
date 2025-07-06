# Makefile für ‚halde‘-Übung
CC       = gcc
CFLAGS   = -std=c11 -pedantic -Wall -Werror -D_XOPEN_SOURCE=700
OBJ      = halde.o
REF_OBJ  = halde-ref.o

.PHONY: all test test-ref clean

all: test

test: $(OBJ) test.c
	$(CC) $(CFLAGS) -o $@ test.c $(OBJ)

test-ref: $(REF_OBJ) test.c
	$(CC) $(CFLAGS) -o $@ test.c $(REF_OBJ)

halde.o: halde.c halde.h
	$(CC) $(CFLAGS) -c halde.c -o $@

clean:
	rm -f *.o test test-ref
