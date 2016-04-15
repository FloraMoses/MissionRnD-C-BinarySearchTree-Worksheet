/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int main() {
	int arr[10] = { 1, 2, 3, 4, 5 };
	//int arr[10] = { -123, 12, 120, 455, 1160, 2100, 4545, 12124, 12344 };
	struct node *root = NULL;
	root = convert_array_to_bst(arr, 3);
	getchar();
	return 0;
}
