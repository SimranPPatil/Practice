#include <stdio.h>
#include <stdlib.h>

void main(){

int i,j,k,len=5;
char str[5]= "abcde";


for(i=0; i<5; i++){
	for(j=len-1;j>0;j--){
		for(k = i; k <= j; k++)
			printf("%c",str[k]);
		printf("\n");
	}
}
}
