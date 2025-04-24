#include <stdio.h>
#include <stdlib.h>

// TODO: structs, global variables, etc.
typedef struct ListNode {
	int data;
	struct ListNode* next;
} node_t;

struct ListNode head = { .data = 0, .next = NULL };

void printListNode() {
	struct ListNode *currentNode = &head;
	int nodeCounter = 0;

	while (currentNode) {
		printf("Node: %d | Value: %d\n", nodeCounter, currentNode->data);
		currentNode = currentNode->next;
		nodeCounter++;
	}
}

static int insertElement(int value) {
	struct ListNode *currentNode = &head;

	while (currentNode) {
		// printf("Node: %d | Value: %d\n", 1, currentNode->data);
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
	struct ListNode *currentNode = &head;

	if (currentNode->next == NULL) {
		// Liste ist breits leer
		return -1;
	}

	if (currentNode->next->next == NULL) {
		// d.h. currentNode->next ist das älteste Element in der Liste und wir müssen das entfernen
		int removeInt = currentNode->next->data;
		currentNode->next = NULL; // ich entferne das älteste Element indem ich das auf NULL setze
		free(currentNode->next);
		return removeInt;
	}

	while (currentNode->next->next != NULL) {
		// ich iterere über die Liste bis ich das älteste Element finde
		currentNode = currentNode->next;
	}
	// currentNode->next enthält das älteste Element aus der Liste

	const int removeInt = currentNode->next->data;
	currentNode->next = NULL;
	free(currentNode->next);
	return removeInt;
}

int main (int argc, char* argv[]) {
	printf("insert 47: %d\n", insertElement(47));
	printListNode();
	printf("insert 11: %d\n", insertElement(11));
	printListNode();
	printf("insert 23: %d\n", insertElement(23));
	printListNode();
	printf("insert 11: %d\n", insertElement(11));
	printListNode();


	printf("______________________\n");
	printListNode();
	printf("remove: %d\n", removeElement());
	printListNode();
	printf("______________________\n");
	printListNode();
	printf("remove: %d\n", removeElement());
	printListNode();
	printf("______________________\n");
	printListNode();
	printf("remove: %d\n", removeElement());
	printListNode();
	printf("______________________\n");
	printListNode();
	printf("remove: %d\n", removeElement());
	printListNode();
	printf("______________________\n");
	printListNode();
	printf("remove: %d\n", removeElement());
	printListNode();


	// TODO: add more tests

	exit(EXIT_SUCCESS);
}
