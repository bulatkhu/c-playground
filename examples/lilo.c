#include <stdio.h>
#include <stdlib.h>

// TODO: structs, global variables, etc.
typedef struct ListNode {
	int data;
	struct ListNode* next;
} node_t;

struct ListNode head = { .data = 0, .next = NULL };

static node_t* findElementByInt(const int value) {

	struct ListNode *currentNode = &head;

	while (currentNode) {
		printf("Node: %d | Value: %d\n", 1, currentNode->data);
		if (currentNode->data == value) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}

static int insertElement(int value) {
	struct ListNode *currentNode = &head;

	while (currentNode) {
		printf("Node: %d | Value: %d\n", 1, currentNode->data);
		if (currentNode->data == value) {
			return -1;
		}

		if (currentNode->next == NULL) {
			node_t *newNode = malloc(sizeof(node_t));
			newNode->data = value;
			newNode-> next = NULL;
			currentNode->next = newNode;
			return value;
		}

		currentNode = currentNode->next;
	}

	// TODO: implement me!
	return -1;
}

static int removeElement(void) {
	// TODO: implement me!
	return -1;
}

int main (int argc, char* argv[]) {
	printf("insert 47: %d\n", insertElement(47));
	printf("insert 11: %d\n", insertElement(11));
	printf("insert 23: %d\n", insertElement(23));
	printf("insert 11: %d\n", insertElement(11));

	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());

	// TODO: add more tests

	exit(EXIT_SUCCESS);
}
