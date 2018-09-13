#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 30000

int main(){
	struct timespec start_ts, finish_ts;
	double as[SIZE], bs[SIZE], cs[SIZE];
	for(size_t ix = 0; ix < SIZE; ++ix){
		as[ix] = rand()%10;
		bs[ix] = rand()%10;
	}

	timespec_get(&start_ts, TIME_UTC);
	for(size_t ix = 0; ix < SIZE; ix+=2){
		cs[ix] = as[ix]*bs[ix] - as[ix+1]*bs[ix+1];
		cs[ix+1] = as[ix]*bs[ix+1] + as[ix+1]*bs[ix];
	}
	timespec_get(&finish_ts, TIME_UTC);

	printf(
		"Run time mul_cpx_inline: %.10f \n",
		finish_ts.tv_sec - start_ts.tv_sec +
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9
	);
	return 0;
}	
