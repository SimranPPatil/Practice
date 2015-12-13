#include <stdio.h>
#include <stdlib.h>


void main(){
    
char array[10];
gets(array);
//cout<<A;
int m;
int i;
char t;

while(array[i] != '\0'){
    i++;
}
printf("%d \n", i);
int n=i;
for(m=0; m!=n-m-1 ; m++){

    t=array[m];
    array[m]=array[n-m-1];
    array[n-m-1]=t;
    
}
puts(array);
}
