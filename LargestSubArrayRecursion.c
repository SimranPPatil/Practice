#include <stdio.h>

int largestSubArray(int* A, int start, int end);

int main()
{
        int A[]={0,1,1,1,1,0,0,0,1};
        int start=0,end=sizeof(A)/4-1;
        int maxsize=largestSubArray(A, start, end);
        if(maxsize==0)
        {
                printf("No subarray found\n");

        }
        else
        {
                printf("largest subarray with equal number of 0's and 1's is: %d \n",maxsize);
        }
        return 0;
}

int largestSubArray(int* arr, int start, int end)
{	int i, counterzero=0, counterone=0; int len=0;
	//YOUR CODE HERE
	if(start==end)
	return 0;
	else{

		for(i=start; i<end; i++){
			if (arr[i]==0)
				counterzero=counterzero+1;
			else
				counterone=counterone+1;
		}

	if(counterzero==counterone){
		len= counterzero*2;

		return len;

	}

	int s=largestSubArray(arr,start+1,end);
	int e=largestSubArray(arr, start, end+1);
	if(s>e)
	return s;
	else
	return e;
}
}
