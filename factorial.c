#include <stdio.h>
#include <stdlib.h>

void factorial(int n){
	int fact=1;
	if(n==0) fact=1;
	else{

		while(n!=0){
		fact=fact*n;
		n--;
		}
		

	}

	printf("%d\n",fact);
}

int fact(int y){
    if(y==1) return 1;
    if(y==0) return 1;
    else{
        int n=y*fact(y-1);
        return n;
        //return fact;
    }
}

void main(){
	
	factorial(6);

    fact(5);
    printf("%d", fact(5));
    return ;
    
}

