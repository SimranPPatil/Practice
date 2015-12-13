#include <stdio.h>
#include <stdlib.h>

int fib(int n){
	



	if(n<=0)
	return 0;
	if(n==1)
	return 1;
	
	else
	{
	    
		return fib(n-1) +fib(n-2);
		
	    
	}
}


void main(){
	
	fib(5);
    printf("%d ",fib(6));
}
