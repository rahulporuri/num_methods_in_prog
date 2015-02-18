#include <stdio.h>
#include <math.h>
#include <time.h>
#define _USE_MATH_DEFINES
#define M_PI  3.14159265358979323846
int
main()
{
	double area, x, y, RAND_MAX;
	int i;
	
	srand((unsigned)time(NULL));
	area = 0;
	for (i = 0; i < 10; i++)
	{
		x = ((double)rand()/(double)RAND_MAX);
		y = ((double)rand()/(double)RAND_MAX);
		printf("%f,%f\n",x,y);
		if (x*x+y*y < 1)
		{
			area += 1;
		}
	}
	printf ("%f\n", area*4/i);
	printf("%lf\n", M_PI);
	return (0);
}
