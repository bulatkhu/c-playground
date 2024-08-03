#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listelement {
	int value;
	struct listelement *next;
} FIFO_List;
// typedef struct listelement FIFO_List; // optional
FIFO_List *elements;

static char* listToString(FIFO_List const *list) {
	char* result = malloc(50 * sizeof(char));  // Adjust size as needed
	sprintf(result, "value %d", list->value);
	return result;
}

static void printList(FIFO_List const *list) {
	printf("%s\n", listToString(list));
}

static int insertElement(int const value) {
	if (elements->value == 0 && elements->next == NULL) {
		elements->value = value;
		return elements->value;
	}

	// printf("boolean %d | \n", current.next != NULL);

	// while (current.value != value) {
		// if (current.next != NULL) {
		// 	current = current.next;
		// }
	// }


	// TODO: implement me!
	return -1;
}

static int removeElement(void) {
	// TODO: implement me!
	return -1;
}


int main (int argc, char* argv[]) {
	printf("insert 47: %d\n", insertElement(47)); // 47

	printf("%s \n", listToString(elements));

	printf("insert 11: %d\n", insertElement(11)); // 11
	printf("insert 23: %d\n", insertElement(23)); // 23
	printf("insert 11: %d\n", insertElement(11)); // -1

	printf("remove: %d\n", removeElement()); // 23
	printf("remove: %d\n", removeElement()); // 11

	// TODO: add more tests
	exit(EXIT_SUCCESS);
}
