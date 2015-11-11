#include <stdio.h>
#include <stdlib.h>

void main()
{
	
    int n , t, tmp;
	int array[7]={-3, 6, 7 ,-2,5, -5, 8};
	for(t=0; t<7; t++)
	{
		printf("%d ", array[t]);
	}
	printf("\n");
	
	for(n=0; n<7; n++)
	{
		if(array[n]<0)
		{
			t=n;
			printf("%d\n",t-1);
			while(array[t-1]>0)
			{
				tmp= array[t-1];
				array[t-1]=array[t];
				array[t]=tmp;
                t--;
			}

		}
	}

	for(t=0; t<7; t++)
	{
		printf("%d ", array[t]);
	}
}
