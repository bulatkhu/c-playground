#include "halde.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/// Magic value for occupied memory chunks.
#define MAGIC ((void*)0xbaadf00d)

/// Size of the heap (in bytes).
#define SIZE (1024*1024*1)

/// Memory-chunk structure.
struct mblock {
	struct mblock *next;
	size_t size;
	char memory[];
};

/// Heap-memory area.
static char memory[SIZE];

/// Pointer to the first element of the free-memory list.
static struct mblock *head = NULL;

/// Helper function to visualise the current state of the free-memory list.
void printList(void) {

	// printf("printList	/n");

	struct mblock *lauf = head;

	// Empty list
	if (head == NULL) {
		char empty[] = "(empty)\n";
		write(STDERR_FILENO, empty, sizeof(empty));
		return;
	}

	// Print each element in the list
	const char fmt_init[] = "(off: %7zu, size:: %7zu)";
	const char fmt_next[] = " --> (off: %7zu, size:: %7zu)";
	const char * fmt = fmt_init;
	char buffer[sizeof(fmt_next) + 2 * 7];

	while (lauf) {
		size_t n = snprintf(buffer, sizeof(buffer), fmt
			, (uintptr_t) lauf - (uintptr_t)memory, lauf->size);
		if (n) {
			write(STDERR_FILENO, buffer, n);
		}

		lauf = lauf->next;
		fmt = fmt_next;
	}
	write(STDERR_FILENO, "\n", 1);
}

void *malloc (size_t size) {

	if (size == 0) return NULL;

	struct mblock *prev = NULL, *cur = head;
	while(cur && cur->size < size) {
		prev = cur;
		cur = cur->next;
	}

	printf("Hello from malloc! %zu\n", size);

	if (!cur) {
		errno = ENOMEM;
		return NULL;
	}

	if (cur->size >= size + sizeof(struct mblock) + 1) {
		struct mblock *newblock = (struct mblock*)cur->memory + size;
		newblock->size = cur->size - size - sizeof(struct mblock);
		newblock->next = cur->next;

		cur->size = size;

		if (prev)
			prev->next = newblock;
		else
			head = newblock;
	} else {
		if (prev)
			prev->next = cur->next;
		else
			head = cur->next;
	}

	cur->next = (struct mblock*)MAGIC;
	// printf("Cur -> size! %d", cur->size);

	return cur->memory;
}
//
// void free (void *ptr) {
// 	// TODO: implement me!
// }
//
// void *realloc (void *ptr, size_t size) {
// 	// TODO: implement me!
// 	return NULL;
// }
//
// void *calloc (size_t nmemb, size_t size) {
// 	// TODO: implement me!
// 	return NULL;
// }
