//this program will allocate a SIZE x SIZE matrix on the heap
//it does so by only calling malloc() twice to reduce fragmentation
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

int main(){
	//allocate all elements at once
	int *asentries = (int*) malloc(sizeof(int) * SIZE*SIZE);
	//allocate all rows
	int **as = (int**) malloc(sizeof(int*) * SIZE);
	for(size_t ix = 0, jx = 0; ix < SIZE; ++ix, jx+=SIZE){
		//make sure the rows point at the the first element of each row vector
		as[ix] = asentries + jx;
	}

	for(size_t ix = 0; ix < SIZE; ++ix){
		for(size_t jx = 0; jx < SIZE; ++jx){
			//initiate values, otherwise the values will be garbage
			as[ix][jx] = 0;
		}
	}
	
	printf("%d\n", as[0][0]);
	
	free(as);
	free(asentries);
}
