CC = gcc
CFLAGS = -std=c11 -pedantic -Wall -Werror -D_XOPEN_SOURCE=700 -pthread
TARGET = patric_test


SRCS = patric_test.c triangle.c
OBJS = $(SRCS:.c=.o)


# Standard-Ziel
all: $(TARGET)

# Linker-Regel
$(TARGET): $(OBJS) sem.o
	$(CC) $(CFLAGS) -o $@ $^

# Kompilierungsregel
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean-Ziel
clean:
	rm -f $(OBJS) $(TARGET)