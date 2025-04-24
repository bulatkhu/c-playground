#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* next;
} node_t;

struct ListNode head = { .data = 0, .next = NULL }; // ein Dummy Knoten mit 0 iniziert, das ignorieren wir einfach

void printListNode() {
	struct ListNode *currentNode = &head;
	currentNode = currentNode->next; // ich skippe den Dummy Knoten mit dem Wert 0

	int nodeCounter = 0;

	printf("Nodes: ");
	while (currentNode) {
		printf("%d,", currentNode->data);
		currentNode = currentNode->next;
		nodeCounter++;
	}
	printf("\n----------------------\n");
}

static int insertElement(const int value) {
	if (value < 0) { // falls ein negativer Wert eingefügt wird
		return -1;
	}

	struct ListNode *currentNode = &head;

	while (currentNode) {
		// printf("Node: %d | Value: %d\n", 1, currentNode->data);
		if (currentNode->data == value) {
			return -1;
		}

		if (currentNode->next == NULL) {
			node_t *newNode = malloc(sizeof(node_t));

			if (newNode == NULL) { // Falls die Memory allocation fehlgeschlagen hat, -1 zurückgeben
				return -1;
			}

			newNode->data = value;
			newNode-> next = NULL;
			currentNode->next = newNode;
			return value;
		}

		currentNode = currentNode->next;
	}

	return -1;
}

static int removeElement(void) {
	struct ListNode *currentNode = &head;

	if (currentNode->next == NULL) {
		// Liste ist breits leer
		return -1;
	}

	int removeInt = currentNode->next->data;
	free(currentNode->next);
	currentNode->next = currentNode->next->next; // das älteste Wert durch den nächsten ältesten Wert ersetzen
	return removeInt;
}

int main (int argc, char* argv[]) {
	printf("insert -500: %d\n", insertElement(-500)); // -1

	printf("insert 47: %d\n", insertElement(47)); // 47
	// printListNode();
	printf("insert 11: %d\n", insertElement(11)); // 11
	// printListNode();
	printf("insert 23: %d\n", insertElement(23)); // 23
	// printListNode();
	printf("insert 11: %d\n", insertElement(11)); // -1
	// printListNode();


	printf("remove: %d\n", removeElement()); // 47
	// printListNode();

	printf("remove: %d\n", removeElement()); // 11
	// printListNode();

	printf("remove: %d\n", removeElement()); // 23
	// printListNode();
	//
	printf("remove: %d\n", removeElement()); // -1
	// printListNode();
	//
	// printf("remove: %d\n", removeElement());
	// printListNode();
	//
	// printf("insert 9: %d\n", insertElement(9));
	// printListNode();
	//
	// printf("remove: %d\n", removeElement());
	// printListNode();

	exit(EXIT_SUCCESS);
}
