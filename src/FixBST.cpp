/*
Given a Binary Search Tree, with two misplaced Node .Find those nodes and fix them .
Do not create a new tree, Modify the original tree 
Ex : In the below tree 3 and 30 is misplaced .
  5                5
 / \              / \
2   3            2  30
 \                \
  30               3
When fixed 30 will be right node of 5 , and 3 will be right node of 2.
Ex :In the below tree 1 and 20 are misplaced
         9                        9
        / \                      / \
       4   1					4  20
      /     \				   /     \
     20     30				  1      30
Nodes 1 and 20 need to be fixed here .
*/ 
#include <stdio.h>  
#include <stdlib.h>
struct node { 
	struct node * left; 
	int data; 
	struct node *right; 
}; 
void printData(struct node *root) {
	if (root->left != NULL) {
		printData(root->left);
	}
	printf("%d\n", root->data);
	if (root->right != NULL) {
		printData(root->right);
	}
}
void fix_bst(struct node *root) { 
	if (root == NULL)
		return;
	printData(root);
} 