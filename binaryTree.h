#include <stdbool.h>
#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Node {
	int value;
	struct Node* leftPtr;
	struct Node* rightPtr;
}Node;

typedef struct BinaryTree {
	int numElements;
	struct Node* rootPtr;
}BinaryTree;

void initialize(BinaryTree* binaryTree);
bool search(BinaryTree* binaryTree, int key);
void insert(BinaryTree* binaryTree, int item);
void printinorder(BinaryTree* binaryTree);
void printpreorder(BinaryTree* binaryTree);
void printpostorder(BinaryTree* binaryTree);
int btsize(BinaryTree* binaryTree);
int treeheight(BinaryTree* binaryTree);

#endif


