#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define M_PI  3.14159265358979323846
int
main()
{
	double area, x, y, error;
	int i, N, j;
	FILE *out_ptr;
	
	out_ptr = fopen("error_pi_est.dat", "w");
	
	srand((unsigned)time(NULL));
	//	srand((unsigned)time(NULL));
	N = 10;
	while (N<100000)
	{
		error = 0;
		for (j=1; j<10; j++)
		{
			area = 0.;
			for (i = 0; i < N; i++)
			{
				x = ((double)rand())/(double)RAND_MAX;
				y = ((double)rand())/(double)RAND_MAX;
				//x = drand48();
				//y = drand48();
	//			printf("%f,%f\n",x,y);
				if (x*x+y*y < 1)
				{
					area += 1.;
				}
			}
			error += ((area*4./N)-M_PI)*((area*4./N)-M_PI);
		}
		printf ("%d \t %f \n", N, sqrt(error));
		fprintf (out_ptr, "%d \t %f \n", N, sqrt(error));
		N = N*2;
//	printf("%lf\n", M_PI);
	}
	fclose(out_ptr);
	return (0);
}
