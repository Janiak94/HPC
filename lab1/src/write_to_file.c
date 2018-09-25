#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 1048576

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("Write 1 for hdd performance and 2 for ssd performance\n");
		return 1;
	}else if(argc != 2){
		printf("Wrong number of arguments\n");
		return -1;
	}
	FILE *file;
	struct timespec start_ts, finish_ts;
	double time_diff;
	int *int_write = (int*) malloc(sizeof(int)*2*N);
	int *int_read = int_write + N;
	
	printf("\n");

	if(strcmp(argv[1],"1") == 0){
		for(size_t ix = 0; ix < N; ++ix){
			int_write[ix]=ix;
		}

		file = fopen("/run/mount/scratch/hpcuser122/integers.bin","w");
		//write to ssd
		timespec_get(&start_ts, TIME_UTC);
		fwrite(int_write, sizeof(int), N, file);
		timespec_get(&finish_ts, TIME_UTC);
		time_diff = finish_ts.tv_sec - start_ts.tv_sec + (finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
		printf("Write to ssd: %.9f\n",time_diff);
		fclose(file);
	
		file = fopen("/run/mount/scratch/hpcuser122/integers.bin","r");
		//read from ssd
		timespec_get(&start_ts, TIME_UTC);
		fread(int_read, sizeof(int), N, file);
		timespec_get(&finish_ts, TIME_UTC);
		time_diff = finish_ts.tv_sec - start_ts.tv_sec + (finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
		printf("Read from ssd: %.9f\n",time_diff);
		fclose(file);
	}else if(strcmp(argv[1], "2") == 0){
		file = fopen("./integers.bin","w");
		//write to hdd
		timespec_get(&start_ts, TIME_UTC);
		fwrite(int_write, sizeof(int), N, file);
		timespec_get(&finish_ts, TIME_UTC);
		time_diff = finish_ts.tv_sec - start_ts.tv_sec + (finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
		printf("Write to hdd: %.9f\n",time_diff);
		fclose(file);
	
		file = fopen("./integers.bin","r");
		//read from hdd
		timespec_get(&start_ts, TIME_UTC);
		fread(int_read, sizeof(int), N, file);
		timespec_get(&finish_ts, TIME_UTC);
		time_diff = finish_ts.tv_sec - start_ts.tv_sec + (finish_ts.tv_nsec - start_ts.tv_nsec)*1e-9;
		printf("Read from hdd: %.9f\n",time_diff);
		fclose(file);
	}else{
		printf("Invalid argument\n");
		return -2;
	}

	printf("\n");
	free(int_write);
	return 0;
}
