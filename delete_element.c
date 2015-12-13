#include <stdio.h>
#include <stdlib.h>

void swap(int array[10], int size){

	int i, temp;
	for(i=0; i<size; i++){
		scanf("%d", &array[i]);
	}


	for(i=0; i<size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	for(i=0; i<size; i++){
		if(i-1>=0 && (i-1)%2==0 && i-1<size){
			temp = array[i];}
			
		if((i+3)%4==0 && i+3<=size){
			array[i]=array[i+2];
			array[i+2]=temp;
			}	
		}
	


	for(i=0; i<size; i++){
		printf("%d ", array[i]);
	}





	return;
}


void main(){
	int A[10];
	swap(A, 8);

	return;
}
