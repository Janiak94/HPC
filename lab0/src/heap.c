#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000000 //this causes segmentation fault for stack

int main(){
	int *as = (int*) malloc(sizeof(int) * SIZE); //heap allocation
	for(size_t ix = 0; ix < SIZE; ++ix){
		as[ix] = 0;
	}
	printf("%d\n", as[0]);

	free(as); //give back memory to OS
}
