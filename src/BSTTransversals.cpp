#include <stdio.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};
void inorderFunction(struct node*, int*, int);
void preorderFunction(struct node*, int*, int);
void postorderFunction(struct node*, int*, int);
void inorder(struct node *root, int *arr) {
	if (root == NULL || arr == NULL)
		return;
	inorderFunction(root, arr, 0);
}
void inorderFunction(struct node *root, int *arr, int i) {
	if (root->left != NULL) {
		inorderFunction(root->left, arr, i++);
	}
	arr[i++] = root->data;
	if (root->right != NULL) {
		inorderFunction(root->right, arr, i);
	}
}
void preorder(struct node *root, int *arr) {
	if (root == NULL || arr == NULL)
		return;
	preorderFunction(root, arr, 0);
}
void preorderFunction(struct node *root, int *arr, int i) {
	arr[i++] = root->data;
	if (root->left != NULL) {
		preorderFunction(root->left, arr, i++);
	}
	if (root->right != NULL) {
		preorderFunction(root->right, arr, i);
	}
}
void postorder(struct node *root, int *arr) {
	if (root == NULL || arr == NULL)
		return;
	postorderFunction(root, arr, 0);
}
void postorderFunction(struct node *root, int *arr, int i) {
	if (root->left != NULL) {
		postorderFunction(root->left, arr, i++);
	}
	if (root->right != NULL) {
		postorderFunction(root->right, arr, i++);
	}
	arr[i++] = root->data;
}
