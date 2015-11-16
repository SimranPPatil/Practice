#include <stdio.h>

void main()
{

	int m=0, i, l=0,k;
	char a[8]="cdefidef";
	char b[3]="eef";
	for(i=0;i<8;i++)
	{
		if(a[i]==b[m])
		{   l=0;
		    printf("i=  %d\n ", i);
            k=i;
			while(a[k++]==b[m++])
			{
				l=l+1;
				//printf("l=%d\n",l);
				//continue;
		
			}
        m=0;   
        	if(l==3)
        {
        printf("%d for k\n", k);
		printf("yes at a[%d]\n", k-l-1);
		}
	    
		}
	}




}
