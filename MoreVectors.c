#include <omp.h>

#define N 1000
#define CHUNKSIZE 100

//parallel for directive example

int main(int argc, char **argv){
	int i, chunk;
	float a[N], b[N], c[N];

	//initialzie
	for(i = 0; i < N; i++)
		a[i] = b[i] = i * 1.0;

	chunk = CHUNKSIZE;

	#pragma omp parallel for \
	shared(a,b,c,chunk) private(i) \
	schedule(static, chunk)
	for(i = 0; i < N; i++)
		c[i] = a[i] + b[i];


	return 0;
}
