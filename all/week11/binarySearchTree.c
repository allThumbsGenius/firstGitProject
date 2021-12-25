#include<stdio.h>
#include<stdlib.h>
typedef struct _node {
	struct _node *prev;
	struct _node *right;
	struct _node *left;
	int key;
}node;
void init(node *s);
node *treeSearch(node *x, int k);
void transplant(node *T, node *u, node *v);
void treeDelete(node *T, int k);
void inorderTreeWalk(node *x);
node *treeMinimum(node *x);
node *treeMaximum(node *x);
node *treeSuccessor(node *x);
node *treePredecessor(node *x);
void treeInsert(node *T, int z);
void printTree(node *T);

void init(node *s) {
	s->key = NULL;
	s->prev = NULL;
	s->left = NULL;
	s->right = NULL;
}
node *treeSearch(node *x, int k) {
	while (x != NULL && k != x->key) {
		if (k < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}
void transplant(node *T, node *u, node *v) {
	if (u->prev == NULL) {
		T = v;
	}
	else if (u == u->prev->left) {
		u->prev->left = v;
	}
	else {
		u->prev->right = v;
	}
	if (v != NULL) {
		v->prev = u->prev;
	}
}
void treeDelete(node *T, int k) {
	node *z;
	node *y;
	node *temp;
	z = treeSearch(T, k);
	temp=z;
	if (z->left == NULL) {
		transplant(T, z, z->right);
	}
	else if (z->right == NULL) {
		transplant(T, z, z->left);
	}
	else {
		y = treeMinimum(z->right);
		if (y->prev != z) {
			transplant(T, y, y->right);
			y->right = z->right;
			y->right->prev = y;
		}
		transplant(T, z, y);
		y->left = z->left;
		y->left->prev = y;
	}
	free(temp);
}
void inorderTreeWalk(node *x) {
	if (x != NULL) {
		inorderTreeWalk(x->left);
		printf("%d ", x->key);
		inorderTreeWalk(x->right);
	}
}

node *treeMinimum(node *x) {
	while (x->left != NULL) {
		x = x->left;
	}
	return x;
}
node *treeMaximum(node *x) {
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}
node *treeSuccessor(node *x) {
	node *y;
	if (x->right != NULL) {
		return treeMinimum(x->right);
	}
	y = x->prev;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->prev;
	}
	return y;
}
node *treePredecessor(node *x) {
	node *y;
	if (x->left != NULL) {
		return treeMaximum(x->left);
	}
	y = x->prev;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->prev;
	}
	return y;
}

void treeInsert(node *T, int z) {
	node *y;
	node *x = T;
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->key = z;
	temp->right = NULL;
	temp->left = NULL;
	while (x != NULL) {
		y = x;
		if (temp->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	temp->prev = y;
	if (y == NULL) {
		T = temp;
	}
	else if (temp->key < y->key) {
		y->left = temp;
	}
	else {
		y->right = temp;
	}
}
void printTree(node *T) {
	T=T->right;
	printf("Tree print: ");
	inorderTreeWalk(T);
	printf("\n");
}
int main() {
	node *root;
	root = (node*)malloc(sizeof(node));
	init(root);

	treeInsert(root, 8);
	printTree(root);
	treeInsert(root, 15);
	treeInsert(root, 6);
	treeInsert(root, 4);
	treeInsert(root, 7);
	treeInsert(root, 10);
	printTree(root);
	treeDelete(root, 7);
	printTree(root);
}
