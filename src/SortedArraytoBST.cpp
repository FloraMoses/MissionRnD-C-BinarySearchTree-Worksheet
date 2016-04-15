/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node * new_node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node(struct node *root, int data){
	if (root == NULL) return new_node(data);

	if (data < root->data)
		root->left = add_node(root->left, data);
	else if (data > root->data)
		root->right = add_node(root->right, data);
	return root;
}
struct node * recurFunction(int *arr, int high, int low, int len) {
	if (high > low || ((high + low) / 2) == len) {
		return NULL;
	}
	int mid = (low + high) / 2;
	//printf("Mid: %d Low: %d High: %d\n", arr[mid], low, high);
	struct node *root = new_node(arr[mid]);
	root->left = recurFunction(arr, high, mid - 1, len);
	root->right = recurFunction(arr, mid + 1, low, len);
	return root;
}
void printElements(struct node *root) {
	if (root->left != NULL) {
		printElements(root->left);
	}
	printf("%d\n", root->data);
	if (root->right != NULL) {
		printElements(root->right);
	}
}
struct node * convert_array_to_bst(int *arr, int len) {
	if (arr == NULL)
		return NULL;
	int count = 0;
	struct node *root = NULL;
	root = recurFunction(arr, 0, len, len);
	printElements(root);
	return root;
}