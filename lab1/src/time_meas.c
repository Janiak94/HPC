#include <time.h>
#include <stdio.h>
#include <string.h>

#define SIZE 1000000000


int main(int argc, char *argv[]){
	struct timespec start_ts, finish_ts;
	int sum = 0;
	timespec_get(&start_ts, TIME_UTC);
	for(size_t ix = 0; ix < SIZE; ++ix){
		sum+=ix;
	}
	timespec_get(&finish_ts, TIME_UTC);
	float time_sec = finish_ts.tv_sec - start_ts.tv_sec + (finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;	
	
	char *flag;
	flag = strrchr(argv[0],'-') + 1;
	printf("%s: %.10f\n",flag,time_sec);
	return 0;
}
