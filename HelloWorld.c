#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv){

	int nthreads, tid;

	//For a team of threads with each thread having its own private tid var
	#pragma omp parallel private(tid)
	{
		//obtain and print thread ids
		tid = omp_get_thread_num();
		printf("Hello World from thread = %d\n", tid);

		//Only master thread does this
		if(tid == 0){
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
		}
	}

	return(0);
}
