#include<stdio.h>

typedef struct Node_{
	int key;
	struct Node_ *left;
	struct Node_ *right;
	struct Node_ *parent;
}Node;
int distance_bst(Node *x){
	int count=0;
	int right;
	int left;
	if(x==NULL){
		return count;
	}
	else{
		left=distance_bst(x->left);
		right=distance_bst(x->right);
		if(x->left!=NULL && x->key<x->left->key){
			count++;
		}
		else if(x->right!=NULL&&x->key>x->right->key){
			count++;
		}
		count=count+left+right;
		return count;
	}
}
