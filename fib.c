

#include <stdio.h>
#include <stdlib.h>

int fib(int n){


int n3;
int n2;
int n1,i;
n2=1;
n1=0;
printf("%d ", n1);
	printf("%d ", n2);
	
for(i=0; i<n; i++){
	
	n3=n1+n2;
	printf("%d ", n3);
	n1=n2;
	n2=n3;
	continue;
}
	



}



void main(){
    
    
    fib(5);
}
