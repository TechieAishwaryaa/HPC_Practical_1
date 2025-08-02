#include<stdio.h>
#include<omp.h>

int main()
{
	int cores;
	double clock_speed=1.29;
	int flops_per_cycle=8;
	#pragma omp parallel
	{
		#pragma omp master
		cores=omp_get_num_threads();
	}

	double flops=cores*clock_speed*1e9*flops_per_cycle;
	printf("Cores: %d\n",cores);
	printf("Clock speed: %.2f\n",clock_speed);
	printf("Flops per cycle: %d\n",flops_per_cycle);
	printf("FLops= %.2f\n",flops/1e9);

	return 0;
}
