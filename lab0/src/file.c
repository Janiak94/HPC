#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(){
	//declare a file pointer
	FILE *fp;
	//allocate the matrix
	int *asentries = malloc(sizeof(int) * SIZE*SIZE);
	int **as = malloc(sizeof(int*) * SIZE);
	for(size_t ix = 0, jx = 0; ix < SIZE; ++ix, jx+=SIZE){
		//make sure the rows point to the first element of each intended row
		as[ix] = asentries + jx;
	}
	
	//assign a random int to each element of the matrix
	for(size_t ix = 0; ix < SIZE; ++ix){
		for(size_t jx = 0; jx < SIZE; ++jx){
			as[ix][jx] = rand()%10;
		}
	}
	
	//open the file
	fp = fopen("matrix.bin","w");

	//with contiguous allocation it is possible to point to asentries since
	//that block isn't fragmented.
	//if it were fragmentet we would have to write a for loop and refer
	//to each element in as:
	//for(size_t ix = 0; ix < SIZE; ++ix){
	//	fwrite(as[ix], sizeof(int), SIZE, fp);
	//}
	
	//write the whole memory block asentries to a file in binary
	fwrite(asentries, sizeof(int), SIZE*SIZE, fp);
	//close the file pointet to by fp
	fclose(fp);
	
	//reopen the file
	fp = fopen("matrix.bin","r");
	//declare a new matrix
	int mat[SIZE][SIZE];
	//read the data from the file into mat
	fread(mat, sizeof(int), SIZE*SIZE, fp);
	//make sure to close the file now that we don't need it anymore
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
