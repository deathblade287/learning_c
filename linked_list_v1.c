#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *createNode(void) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	return newNode;
}

Node *insertAtStart(int data, Node *header) {
	Node *newNode = createNode();
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = header;

	if (header != NULL) {  // Prevent segmentation fault
		header->prev = newNode;
	}

	return newNode;  // New node becomes the new head
}

void insertAtEnd(int data, Node *header) {
	if (header == NULL) {
		printf("Empty List! Start With insertAtStart");
		exit(1);
	}

	Node *newNode = createNode();
	newNode->data = data;
	newNode->next = NULL;

	Node *finalNode = header;
	while (finalNode->next != NULL) {
		finalNode = finalNode->next;
	}

	finalNode->next = newNode;
	newNode->prev = finalNode;
}

void insertBetween(int data, Node *header, int position) {
	if (header == NULL) {
		printf("Empty List! Start With insertAtStart");
		exit(1);
	}
	if (position == 1) {
		printf("Use insertAtStart!");
		exit(1);
	}
	position -= 2; // it starts from 0 so -1 and add to the next element so another -1
	Node *editNode = header;
	for (int i = 0; i < position; i++) {
		editNode = editNode->next;
		if (editNode == NULL) {
			printf("Index Error. The list is not big enough");
			exit(1);
		}
	}
	Node *newNode = createNode();
	newNode->data = data;
	newNode->prev = editNode;
	newNode->next = editNode->next;
	editNode->next = newNode;
}

int search(int searchTerm, Node *header) {

	Node *currentNode = header;

	int count = 1;
	while (currentNode) {
		if (currentNode->data == searchTerm) {
			return count;
		}
		currentNode = currentNode->next;
		count++;
	}
	return -1;
}

void printList(Node *header) {
	Node *temp = header;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void freeList(Node *header) {
	Node *temp;
	while (header != NULL) {
		temp = header;
		header = header->next;
		free(temp);
	}
}

int getLength(Node *header) {
	int count = 1;
	Node *currentNode = header;
	while (currentNode->next != NULL) {
		count ++;
		currentNode = currentNode->next;
	}
	return  count;
}

int main() {
	Node *header = NULL;

	header = insertAtStart(1, header);
	insertAtEnd(2, header);
	insertAtEnd(3, header);
	insertAtEnd(5, header);
	insertBetween(4, header, 4);

	printList(header);
	printf("Length : %i\n", getLength(header));

	int searchTerm;
	printf("What Do you want to search for?");
	scanf("%i", &searchTerm);
	printf("\nSearching For %i...\n", searchTerm);
	printf("It is at position %i\n", search(searchTerm, header));

	freeList(header);

	return 0;
}