#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{

char a[6] = "srujun";
char b[6] = "uunsjr";
int m,c=0,i;
//printf("%d", strlen(a));
if(strlen(a)==strlen(b))
{
	for(m=0; m<6; m++)
	{

		for(i=0;i<6;i++)
		{
			if(a[m]==b[i])
			{
			c += 1;
			b[i]=' ';
			break;
			}
		}
	}

	if(c==strlen(a))
	{
		printf("Anagram\n");
	}
	else
	{
	    printf("Not Anagram\n");
	}
}
}
