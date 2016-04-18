/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
int height1(struct node *root) {
	int temp, temp1;
	if (root != NULL) {
		temp = height1(root->left);
		temp1 = height1(root->right);
		if (temp1 > temp)
			return temp1 + 1;
		else
			return temp + 1;
	}
	else
		return 0;
}
void levelOrderTraversal(struct node*, int*, int, int);
int* BSTRighttoLeftRows(struct node* root) {
	if (root == NULL)
		return NULL;
	int *result = (int*)malloc(sizeof(int) * 10);
	int i = 1, j = 0, temp[5] = { 0 }, k = 0;
	int max_height = height1(root); 
	while (max_height >= i) {  
		levelOrderTraversal(root, temp, 0, i);
		j = 0; 
		while (temp[j] != 0) 
			j++; 
		j = j - 1;
		while (j >= 0) {
			result[k++] = temp[j];
			temp[j--] = 0;
		}
		i++;
	}
	return result;
}
void levelOrderTraversal(struct node* root, int *temp, int i, int height) {
	if (height <= 1) {
		if (temp[0] == 0)
			i = 0;
		else if (temp[1] == 0)
			i = 1;
		temp[i++] = root->data;
		return;
	}
	if (root->left != NULL) {
		levelOrderTraversal(root->left, temp, i++, height - 1);
	}
	if (root->right != NULL) {
		levelOrderTraversal(root->right, temp, i++, height - 1);
	}
	return;
}
