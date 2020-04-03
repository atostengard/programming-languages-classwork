#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTree.h"

int main(void) {
	BinaryTree binaryTree;
	bool found;
	int nextInt;
	int treeHeight;
	int numElements;
	FILE* inFile = NULL;
	
	
	inFile = fopen("myfile.txt", "r");
	initialize(&binaryTree);
	
	
	while (!feof(inFile) && (fscanf(inFile, "%d", &nextInt) == 1)) {
		insert(&binaryTree, nextInt);
	}
	
	printf("\nPrint in order\n");
	printinorder(&binaryTree);
	printf("\nPrint pre order\n");
	printpreorder(&binaryTree);
	printf("\nPrint post order\n");
	printpostorder(&binaryTree);
	printf("\n");
	found = search(&binaryTree,33);
	
	if (found){       
	   printf("FOUND 33\n");
	} 
	
	found = search(&binaryTree,38);
	
	if (found){
	   printf("FOUND 38\n");
	}    
	
	printf("Number of elements in tree: %d\n", btsize(&binaryTree));
    printf("Tree height: %d\n", treeheight(&binaryTree));	
}