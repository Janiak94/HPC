#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 30000

void mul_cpx(
	double *a_re,
 	double *a_im,
	double *b_re, 
	double *b_im, 
	double *c_re, 
	double *c_im
){
	*c_re = *a_re * *b_re - *a_im * *b_im;
	*c_im = *a_re * *b_im + *a_im * *b_re;
}
	
int main(){
	struct timespec start_ts, finish_ts;

	double as[SIZE], bs[SIZE], cs[SIZE];
	for(size_t ix = 0; ix < SIZE; ++ix){
		as[ix] = rand()%10;
		bs[ix] = rand()%10;
	}

	timespec_get(&start_ts, TIME_UTC);
	for(size_t ix = 0; ix < SIZE; ix+=2){
		mul_cpx(
			&as[ix],
			&as[ix+1],
			&bs[ix],
			&bs[ix+1],
			&cs[ix],
			&cs[ix+1]
		);
	}
	timespec_get(&finish_ts, TIME_UTC);

	printf(
		"Run time mul_cpx_mainfile: %.10f \n",
		finish_ts.tv_sec - start_ts.tv_sec +
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9
	);
	return 0;
}	
