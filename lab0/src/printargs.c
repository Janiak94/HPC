#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//structure that describes the args and if they are set
struct arg_t{
	bool is_set;
	int val;
}a,b;

int main(int argc, char *argv[]){
	if(argc != 5){
		printf("Invalid number of arguments, supposed to be four\n");
		return -1;
	}
	char *ptr;
	for(size_t ix = 1; ix < 5; ++ix){
		if(strcmp(argv[ix],"-a") == 0){
			a.is_set = true;
			a.val = (int) strtol(argv[ix+1],&ptr,10);
		}
		if(strcmp(argv[ix],"-b") == 0){
			b.is_set = true;
			b.val = (int) strtol(argv[ix+1],&ptr,10);
		}
	}
	if(!a.is_set || !b.is_set){
		printf("Invalid flags\n");
		return 1;
	}
	printf("A is %d and B is %d\n",a.val,b.val);
	
	return 0;	
}
