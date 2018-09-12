#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(){
	FILE *fp;
	int *asentries = malloc(sizeof(int) * SIZE*SIZE);
	int **as = malloc(sizeof(int*) * SIZE);
	for(size_t ix = 0, jx = 0; ix < SIZE; ++ix, jx+=SIZE){
		as[ix] = asentries + jx;
	}

	for(size_t ix = 0; ix < SIZE; ++ix){
		for(size_t jx = 0; jx < SIZE; ++jx){
			as[ix][jx] = rand()%10;
		}
	}

	fp = fopen("textfile.txt","w");
	//with contiguous allocation it is possible to point to asentries since
	//that block isn't fragmented.
	//if it were fragmentet we would have to write a for loop and refer
	//to each element in as:
	//for(size_t ix = 0; ix < SIZE; ++ix){
	//	fwrite(as[ix], sizeof(int), SIZE, fp);
	//}
	fwrite(asentries, sizeof(int), SIZE*SIZE, fp);
	fclose(fp);
	
	fp = fopen("textfile.txt","r");
	int mat[SIZE][SIZE];
	fread(mat, sizeof(int), SIZE*SIZE, fp);
	fclose(fp);

	for(size_t ix = 0; ix < SIZE; ++ix){
		for(size_t jx = 0; jx < SIZE; ++jx){
			if(mat[ix][jx] != as[ix][jx]){
				printf("Not equal!");
				return 0;
			}
		}
	}
	printf("Equal\n");
	free(asentries);
	free(as);
}
