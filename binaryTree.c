#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"

void initialize (BinaryTree* binaryTree) {
	Node* rootNode = (Node*) malloc(sizeof(Node));	//create root node
	binaryTree->numElements = 0;					//set numElements to 0
	binaryTree->rootPtr = rootNode;					//rootPtr points to root
	rootNode->value = 0;							//initialize value to NULL
	rootNode->leftPtr = NULL;						//set both ptrs to NULL
	rootNode->rightPtr = NULL;
}

bool search(BinaryTree* binaryTree, int key) {
	Node* currentNode = binaryTree->rootPtr;		//start at root
	bool found = 0;									//return value to mark whether key is found
	while (currentNode != NULL) {					//stops when there are no nodes left to visit
		if (key == currentNode->value) {
			return found = 1;						//return if found key match
		}
		else if (key < currentNode->value) {
			currentNode = currentNode->leftPtr;		//if key is less than current node, keep looking to the left
		}
		else {
			currentNode = currentNode->rightPtr;	//if key is greater than current node, keep looking to right
		}
	}
	return found;
}

void insert(BinaryTree* binaryTree, int item) {
	
	if (binaryTree->numElements == 0) {				//if tree is empty, assigns new item to the root
		binaryTree->rootPtr->value = item;			//assigns value of item to root
		binaryTree->numElements++;
	}
	else {
		Node* currentNode = binaryTree->rootPtr;	//start currentNode at root
		while (currentNode != NULL) {				//searches for insertion point
			if (item < currentNode->value) {		//if value is less than current node's value
				if (currentNode->leftPtr == NULL) { //insert to left if theres not a node there already
					Node* newNode = (Node*) malloc(sizeof(Node));
					newNode->value = item;			//assign new node's value to the item to insert and sets up ptrs
					newNode->leftPtr = NULL;
					newNode->rightPtr = NULL;
					currentNode->leftPtr = newNode;
				}
				else {
					currentNode = currentNode->leftPtr; //if node not inserted, current node points to next node to the left
				}
			}
			else {										//if value is greater than current node's value
				if (currentNode->rightPtr == NULL) {	//insert node if no node to the right
					Node* newNode = (Node*) malloc(sizeof(Node));
					newNode->value = item;				//assign new node's value to the item to insert and set up ptrs
					newNode->leftPtr = NULL;
					newNode->rightPtr = NULL;
					currentNode->rightPtr = newNode;
				}
				else {
					currentNode = currentNode->rightPtr;	//get right node if item is not inserted yet
				}
			}
		}
		binaryTree->numElements++;
	}
}

void BSTprintinorder(Node* node) {				//recursive printinorder function
	if (node == NULL) {
		return;
	}
	BSTprintinorder(node->leftPtr);
	printf("%d ", node->value);
	BSTprintinorder(node->rightPtr);
}

void printinorder(BinaryTree* binaryTree) {		//function to get node to send to printinorder
	Node* currentNode = binaryTree->rootPtr;	//function to get node to send to printinorder
	BSTprintinorder(currentNode);
}

void BSTprintpreorder(Node* node) {				//recursive printpreorder function
	if (node == NULL) {
		return;
	}
	printf("%d ", node->value);
	BSTprintpreorder(node->leftPtr);
	BSTprintpreorder(node->rightPtr);
}

void printpreorder(BinaryTree* binaryTree) {	//function to get node to send to preorder
	Node* currentNode = binaryTree->rootPtr;
	BSTprintpreorder(currentNode);
}

void BSTprintpostorder(Node* node) {			//recursive printpostorder function
	if (node == NULL) {
		return;
	}
	BSTprintpostorder(node->leftPtr);
	BSTprintpostorder(node->rightPtr);
	printf("%d ", node->value);
}

void printpostorder(BinaryTree* binaryTree) {	//function to get node to send to postorder
	Node* currentNode = binaryTree->rootPtr;
	BSTprintpostorder(currentNode);
}

int btsize(BinaryTree* binaryTree) {			//returns number of elements in tree
	return binaryTree->numElements;
}


int max (int a, int b) {
	if (a > b) return a;
	else return b;
}

int BTHeight(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return (max(BTHeight(node->leftPtr), BTHeight(node->rightPtr)) + 1);
	}
}

int treeheight (BinaryTree* binaryTree) {
	Node* currentNode = binaryTree->rootPtr;
	int treeHeight = BTHeight(currentNode);
	return treeHeight;
}
