#include <stdio.h>
#include <stdlib.h>

// struct listelement {
// 	int value;
// 	struct listelement *next;
// };
// typedef struct listelement FIFO_List; // optional
// FIFO_List elements;

static int insertElement(int value) {
	printf("value: %d\n", value);

	// TODO: implement me!
	return -1;
}

static int removeElement(void) {
	// TODO: implement me!
	return -1;
}


int main (int argc, char* argv[]) {
	printf("insert 47: %d\n", insertElement(47)); // 47
	printf("insert 11: %d\n", insertElement(11)); // 11
	printf("insert 23: %d\n", insertElement(23)); // 23
	printf("insert 11: %d\n", insertElement(11)); // -1

	printf("remove: %d\n", removeElement()); // 23
	printf("remove: %d\n", removeElement()); // 11

	// TODO: add more tests
	exit(EXIT_SUCCESS);
}
