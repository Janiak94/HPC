//this program will allocate a SIZE x SIZE matrix on the heap
//but with each row placed on different places on the heap
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

int main(){
	//allocate rows of matrix on heap
	//or in other words, initiate column vector that will hold row vectors
	int **as = (int**) malloc(sizeof(int*) * SIZE);
	for(size_t ix = 0; ix < SIZE; ++ix){
		//allocate each row on the heap
		//or in other words, initiate each row vector
		//each call of malloc() will increase the fragmentation
		as[ix] = (int*) malloc(sizeof(int) * SIZE);
	}

	for(size_t ix = 0; ix < SIZE; ++ix){
		for(size_t jx = 0; jx < SIZE; ++jx){
			as[ix][jx] = 0;
		}
	}

	printf("%d\n", as[0][0]);
	
	for(size_t ix = 0; ix < SIZE; ++ix){
		free(as[ix]);
	}
	free(as);
}
