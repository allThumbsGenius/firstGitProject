#include<stdio.h>

int main(){
	int list[6]={5,2,4,6,1,3};
	int i,j,key;
	for(j=1;j<6;j++){
		key=list[j];
		i=j-1;
		while(i>=0 && list[i]>key){
			list[i+1]=list[i];
			i=i-1;
		}
		list[i+1]=key;
	}
	for(int a=0;a<6;a++){
		printf("%d ",list[a]);
	}
	printf("\n");
}

