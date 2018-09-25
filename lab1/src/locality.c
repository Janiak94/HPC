#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void row_sums(
		double *sums,
		const double **matrix,
		size_t nrs,
		size_t ncs
){
	for(size_t ix = 0; ix < nrs; ++ix){
		double sum = 0;
		for(size_t jx = 0; jx < ncs; ++jx){
			sum += matrix[ix][jx];
		}
		sums[ix] = sum;
	}
}

void col_sums(
		double *sums,
		const double **matrix,
		size_t nrs,
		size_t ncs
){
	for(size_t jx = 0; jx < ncs; ++jx){
		double sum = 0;
		for(size_t ix = 0; ix < nrs; ++ix){
			sum += matrix[ix][jx];
		}
		sums[jx] = sum;
	}
}
//this version goes through each row and add each column element to the column sums
//this is better since C stores matricies in row major order
//
//Question: Why does this version work better than Tobias version?
void col_sums_better(
			double *sums,
			const double **matrix,
			size_t nrs,
			size_t ncs
){
	for(size_t ix = 0; ix < nrs; ++ix){
		for(size_t jx = 0; jx < ncs; ++jx){
			if(ix == 0){
				sums[jx] = 0;
			}
			sums[jx] += matrix[ix][jx];
		}
	}
}

void col_sums_best(
			double *sums,
			const double **matrix,
			size_t nrs,
			size_t ncs
){
	//setting sums in a separate for-loop
	//improves performance further since we
	//only have to load it once
	for(size_t ix = 0; ix < ncs; ++ix){
		sums[ix] = 0;
	}
	for(size_t ix = 0; ix < nrs; ++ix){
		for(size_t jx = 0; jx < ncs; ++jx){
			sums[jx] += matrix[ix][jx];
		}
	}
}

int main(){
	//declare variables
	double *asentries = (double*) malloc(sizeof(double) * SIZE*SIZE);
	double **as = (double**) malloc(sizeof(double*) * SIZE);
	struct timespec start_ts, finish_ts;
	float time_diff;
	//initiate random with seed
	srand(time(NULL));
	//connect asentries to as
	for(size_t ix = 0, jx = 0; ix < SIZE; ++ix, jx+=SIZE){
		as[ix] = asentries + jx;
	}
	//initiate matrix with random double between (-1,1)
	for(size_t jx = 0; jx < SIZE; ++jx){
		for(size_t ix = 0; ix < SIZE; ++ix){
			as[ix][jx] = rand()/RAND_MAX*2.0+1.0;
		}
	}
	//initiate row and col sums
	double rows[SIZE], cols[SIZE], cols_better[SIZE], cols_best[SIZE];
	//calculate row sums and benchmark
	timespec_get(&start_ts, TIME_UTC);
	row_sums(
		rows,
		as,
		SIZE,
		SIZE
	);
	timespec_get(&finish_ts, TIME_UTC);
	time_diff = finish_ts.tv_sec - start_ts.tv_sec + 
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
	printf("Row_sums: %.10f sec\n", time_diff);

	timespec_get(&start_ts, TIME_UTC);
	col_sums(
		cols,
		as,
		SIZE,
		SIZE
	);
	timespec_get(&finish_ts, TIME_UTC);
	time_diff = finish_ts.tv_sec - start_ts.tv_sec + 
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
	printf("Col_sums: %.10f sec\n", time_diff);
	
	timespec_get(&start_ts, TIME_UTC);
	col_sums_better(
		cols_better,
		as,
		SIZE,
		SIZE
	);
	timespec_get(&finish_ts, TIME_UTC);
	time_diff = finish_ts.tv_sec - start_ts.tv_sec + 
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
	printf("Col_sums_better: %.10f sec\n", time_diff);

	timespec_get(&start_ts, TIME_UTC);
	col_sums_best(
		cols_best,
		as,
		SIZE,
		SIZE
	);
	timespec_get(&finish_ts, TIME_UTC);
	time_diff = finish_ts.tv_sec - start_ts.tv_sec + 
		(finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
	printf("Col_sums_best: %.10f sec\n", time_diff);

	free(as);
	free(asentries);
	return 0;
}
