#include<stdio.h>

int main(){
	int list[6]={5,2,4,6,1,3};
	int i,j,temp;
	for(j=1;j<6;j++){
		i=j-1;
		while(i>=0 && list[i]>list[i+1]){
			temp=list[i+1];
			list[i+1]=list[i];
			list[i]=temp;
			i=i-1;
		}
	}
	for(int a=0;a<6;a++){
		printf("%d ",list[a]);
	}
	printf("\n");
}

