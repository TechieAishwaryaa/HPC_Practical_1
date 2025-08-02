#include<stdio.h>
#include<omp.h>

int main()
{
	int threads;
	printf("Enter number of threads: ");
	scanf("%d",&threads);
	printf("\nSequential hello world: \n");
	for(int i=0;i<threads;i++)
	{
		printf("Hello world from iteration %d\n",i);
	}
	omp_set_num_threads(threads);
	printf("\nParallel Hello world:\n");
	#pragma omp parallel
	{
		int thread_id=omp_get_thread_num();
		printf("Hello world thread-%d\n",thread_id);
	}
	return  0;
}
