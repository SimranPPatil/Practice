#include <stdio.h>
#include <stdlib.h>


int point_cnv(int *A, int *B, int N, int M, int x, int y){

	int i,j,s,t;

			int acc= 0;

			for( s=-1; s<=1; s++){
				for(t=-1; t<=1; t++){

					if(x+s<0 || x+s >= N || y+t<0 || y+t >=M){
						continue;
					}

					acc += A[(y+t)*M + (x+s)] * B[(t+1)*3 +(s+1)];
				}
			}


	
	return acc;



}

void im_convolution(int *A, int *B, int *C, int N, int M){
int x,y;
for(x=0; x<N; x++){

	for(y=0; y<M; y++){

		C[y*N + x]= point_cnv(A,B,N,M,x,y);

	}
}


}

int main()
{ int x,y;
	int A[] = {
		1, 1, 1, 1, 1,
		9, 9, 9, 9, 9,
		9, 9, 9, 9, 9,
		5, 5, 5, 5, 5,
		2, 2, 2, 2, 2
	};
int B[] = {-1, -2, -1,
			0, 0, 0,
			1, 2, 1};
/* a 5×5 pixels image */
/* a 3×3 convolution kernel */
	int C[25];
	im_convolution(A, B, C, 5, 5); /* C = A convolved with B */
int M=5;
int N=5;

	for(x=0; x<N; x++){
		for(y=0; y<M; y++){
			
			printf("%d\n", C[ y*M+x]);

		}
	}
	return 0;

}
