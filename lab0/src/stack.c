#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000000 //causes segmentation fault on stack

int main(){
	int as[SIZE]; //stack allocation
	for(size_t ix = 0; ix < SIZE; ++ix){
		as[ix] = 0;
	}
	printf("%d\n", as[0]);
}
