#include<stdio.h>
#include<stdlib.h>
int linearHash(int key, int i, int M){
	return (key+i)%M;
}
int quadraticHash(int key, int i, int M){
	return (key+i+i*i)%M;
}
int linearInsert(int *list, int k, int M){
	int i;
	int j;
	i=0;
	while(1){
		j=linearHash(k, i, M);
		if(list[j]==-1){
			list[j]=k;
			return i;
		}
		else{
			i++;
		}
	}	
}
int quadraticInsert(int *list, int k, int M){
	int i;
	int j;
	i=0;
	while(1){
		j=quadraticHash(k, i, M);
		if(list[j]==-1){
			list[j]=k;
			return i;
		}
		else{
			i++;
		}
	}
}
int compare_hash(int M, int *key, int N){
	int *quadraticList;
	int *linearList;
	int i;
	int linearCount=0, quadraticCount=0;

	quadraticList=(int *)malloc(M*sizeof(int));
	linearList=(int *)malloc(M*sizeof(int));
	
    for(i=0;i<M;i++){
        linearList[i]=quadraticList[i]=-1;
    }
	for(i=0;i<N;i++){
		linearCount+=linearInsert(linearList, key[i], M);
	}
	for(i=0;i<N;i++){
		quadraticCount+=quadraticInsert(quadraticList, key[i], M);
	}
	return linearCount-quadraticCount;
}
