#include <stdio.h>
#include <stdlib.h>


void main()
{

int a[10]= {3,8,8,6,9,13,25,3,5,8};

int m,c,i,x;

for(m=0; m<10; m++)
{

	while(a[m]==-1)
	{
		m++;
	}
	if(m>=10)
        break;
	x=a[m];
	c=0;

	for(i=m;i<10;i++)
	{
		if(a[i]==x)
		{
			c += 1;
			a[i]=-1;
		}
	}
	printf("%d-%d\n", x,c);
}
}
