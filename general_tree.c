#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  int numChildren;
  struct Node *parent;
  struct Node **children;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->numChildren = 0;
  newNode->parent = NULL;
  newNode->children = NULL;
  return newNode;
}

Node *addChild(Node *parent, Node *child) {
  if (parent == NULL || child == NULL) {
    printf("Error! Node(s) in question is/are NULL");
    exit(1);
  }

  parent->numChildren++;

  parent->children =
      realloc(parent->children, sizeof(Node *) * parent->numChildren);

  child->parent = parent;

  parent->children[parent->numChildren - 1] = child;

  return parent;
}

// 124356

void preOrderTraversal(Node *origin) {
  printf("%i", origin->data);

  for (int i = 0; i < origin->numChildren; i++) {
    preOrderTraversal(origin->children[i]);
  }
}

// 425631

void postOrderTraversal(Node *origin) {
  if (origin->children == NULL) {
    printf("%i", origin->data);
    return;
  }

  for (int i = 0; i < origin->numChildren; i++) {
    postOrderTraversal(origin->children[i]);
  }

  printf("%i", origin->data);
}

void levelTraversal(Node *origin) {
  if (origin->numChildren == 0) {
    return;
  }

  if (origin->parent == NULL) {
    printf("%i", origin->data);
  }

  for (int i = 0; i < origin->numChildren; i++) {
    printf("%i", origin->children[i]->data);
  }

  for (int i = 0; i < origin->numChildren; i++) {
    levelTraversal(origin->children[i]);
  }
}

int main(void) {

  Node *origin = createNode(1);
  Node *N2 = createNode(2);
  Node *N3 = createNode(3);
  Node *N4 = createNode(4);
  Node *N5 = createNode(5);
  Node *N6 = createNode(6);

  origin = addChild(origin, N2);
  origin = addChild(origin, N3);
  N2 = addChild(N2, N4);
  N3 = addChild(N3, N5);
  N3 = addChild(N3, N6);

  printf("Pre Order Traversal : ");
  preOrderTraversal(origin);
  printf("\n");
  printf("Post Order Traversal : ");
  postOrderTraversal(origin);
  printf("\n");
  printf("Level-Wise Traversal : ");
  levelTraversal(origin);
  printf("\n");

  free(N6);
  free(N5);
  free(N4);
  free(N2->children);
  free(N3->children);
  free(N2);
  free(N3);
  free(origin->children);
  free(origin);

  return 0;
}
