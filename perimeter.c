#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
int x, y; /* vertex coordinates */ 
float length; /* polygon’s side length */
} vertex;

vertex * read_polygon(char *file_name, int *count){
	*count=0;
	vertex *array;
	FILE *fp;
	fp=fopen(file_name, "r");
	if(fp != NULL)
	{
		//int n;
		fscanf(fp, "%d", count);  // to get the vertices
		array = (vertex *)malloc(sizeof(vertex) * (*count));
			// creating array of type vertex* dynamically

		int i;
		for(i=0; i< *count; i++){
			fscanf(fp,"%d %d", &(array[i].x), &(array[i].y));
		}
		fclose(fp);
		return array;
	}
	else
	{
		return NULL;
	}
}


float calc_perimeter(vertex* vrtx, int count){
	float perimeter = 0.0f;

	int i;
	for(i = 0; i < count; i++)
	{
		if(i == count - 1)
		{
			float xcomp = pow(vrtx[0].x - vrtx[i].x, 2);
			float ycomp = pow(vrtx[0].y - vrtx[i].y, 2);

			float len = sqrt(xcomp + ycomp);
			vrtx[i].length = len;
			perimeter += len;
			continue;
		}

		float xcomp = pow(vrtx[i+1].x - vrtx[i].x, 2);
		float ycomp = pow(vrtx[i+1].y - vrtx[i].y, 2);

		float len = sqrt(xcomp + ycomp);
		perimeter += len;

		vrtx[i].length = len;
	}

	return perimeter;
}

int record_polygon(char *file_name, vertex *vrtr, int count, float perimeter)
{
	FILE *fp;
	fp=fopen(file_name, "w");
	int i;

	if(fp != NULL)
	{
		fprintf(fp, "%d\n", count);
		for(i=0; i<count; i++){

			fprintf(fp, "%d %d %f\n", vrtr[i].x, vrtr[i].y , vrtr[i].length);


		}
		free(vrtr);
		fprintf(fp, "%f\n", perimeter);
		fclose(fp);
		return 1;
	}
	else
	{
		return 0;
	}




}



void main(){



	
}
