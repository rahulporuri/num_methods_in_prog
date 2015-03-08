#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double, double);
void rk4_step(double *, double);

int
main(void)
{
	double h = 0.1;

	double *array;
	array = (double*)malloc(2*sizeof(double));
	double *array_test;
	array_test = (double*)malloc(2*sizeof(double));

	int i;

	FILE *in_ptr;
	in_ptr = fopen("rk_adap_test.dat","w");

	array[0] = 0;
	array[1] = 0.5;

	for (i=0;i<100;i++)
	{
		rk4_step(array,h);
//		printf("%lf, %lf \n", x,y);
		fprintf(in_ptr, "%lf, %lf \n", array[0],array[1]);
	}

	fclose(in_ptr);
	return (0);
}

double func(double x, double y)
{
	return (10*exp(-pow(x-2,2)/(2*pow(0.075,2))) - 0.6*y);
}

void rk4_step(double *array, double h)
{
	double k1, k2, k3, k4;
	double x,y;

	x = array[0];
	y = array[1];

	k1 = (*func)(x,y);
	k2 = (*func)(x+h/2., y+k1*h/2.);
	k3 = (*func)(x+h/2., y+k2*h/2.);
	k4 = (*func)(x+h,y+k3*h);

	array[0] += h;
	array[1] += (k1 +2*k2 +2*k3 +k4)*h/6.;

	return;
}
