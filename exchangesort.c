#include <stdio.h>
#include <stdlib.h>


void main(){
	
	int k,i,t,n=5;
	int array[5]={3,2,7,1,9};
	
    for(i=0; i <5; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
	for(k-0;k<n;k++){
    for(i=0;i<n;i++){
    printf("%d\n",i);
        if(i+1!=n){
    	if(array[i]>array[i+1]){
    		t=array[i];
    		array[i]=array[i+1];
    		array[i+1]=t;
            
    	}}
    	
    }
	i=k;
	}

	for(i=0; i <n; i++){
        printf("%d ", array[i]);
    }

}
