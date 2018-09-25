#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 1000000
#define M 1000

void indirect_increment(float *x, float *y, float a, int *p){
	size_t jx;
	for(size_t kx = 0; kx < N; ++kx){
		jx = p[kx];
		y[jx] += a * x[jx];
	}
}

int main(){
	//create constant vectors X and Y
	float *x_c = (float*) malloc(sizeof(float)*N);	
	float *y_c = (float*) malloc(sizeof(float)*N);
	float a = 2.0;
	for(size_t ix = 0; ix < N; ++ix){
		x_c[ix] = ((float) rand())/RAND_MAX;
	}
	for(size_t ix = 0; ix < N; ++ix){
		y_c[ix] = ((float) rand())/RAND_MAX;
	}

	float *x = (float*) malloc(sizeof(float)*N);
	float *y = (float*) malloc(sizeof(float)*N);
	//copy the values of x_c and y_c
	memcpy(x, x_c, sizeof(float)*N);
	memcpy(y, y_c, sizeof(float)*N);
	
	//create first address vector
	int *p = (int*) malloc(sizeof(int)*N);;
	size_t ix = 0;
	for(size_t jx = 0; jx < M; ++jx){
		for(size_t kx = 0; kx < M; ++kx){
			p[jx + M*kx] = ix++;
		}
	}
	struct timespec start_ts, finish_ts;
	//time version 1	
	timespec_get(&start_ts, TIME_UTC);
	indirect_increment(x, y, a, p);
	timespec_get(&finish_ts, TIME_UTC);
	double diff = finish_ts.tv_sec - start_ts.tv_sec +
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
	printf("Version 1: %.9f\n", diff);
	
	memcpy(x, x_c, sizeof(float)*N);
	memcpy(y, y_c, sizeof(float)*N);
	//create second address vector
	for(size_t ix = 0; ix < N; ++ix){
		p[ix] = ix;
	}
	//time version 2
	timespec_get(&start_ts, TIME_UTC);
	indirect_increment(x, y, a, p);
	timespec_get(&finish_ts, TIME_UTC);	
	diff = finish_ts.tv_sec - start_ts.tv_sec +
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
	printf("Version 2: %.9f\n", diff);
		
	memcpy(x, x_c, sizeof(float)*N);
	memcpy(y, y_c, sizeof(float)*N);
	//time version 3
	timespec_get(&start_ts, TIME_UTC);
	for(size_t ix = 0; ix < N; ++ix){
		y[ix] += a * x[ix];
	}
	timespec_get(&finish_ts, TIME_UTC);
	diff = finish_ts.tv_sec - start_ts.tv_sec +
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
	printf("Version 3: %.9f\n", diff);
	free(x_c);
	free(y_c);
	free(x);
	free(y);
	return 0;
}
