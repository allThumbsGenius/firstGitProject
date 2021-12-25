#include<stdio.h>
void insert_node_array(int *next, int *key, int *prev, int n, int *L, int *free, int k){
	int temp;
	temp = next[*free];
	prev[*L] = *free;
	next[*free]=*L;
	key[*free] = k;
	prev[*free] = -1;
	*L=*free;
	*free = temp;
}
void delete_node_array(int *next, int *key, int *prev, int n, int *L, int *free){
	int temp;
	temp=*L;
	*L=next[temp];
	prev[next[temp]]=-1;
	next[temp]=*free;
	*free=temp;
	
}
