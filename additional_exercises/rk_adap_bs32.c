#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double, double);
void rk_adap_step(double, double *, double);

int
main(void)
{
	double h = 0.1;
	double x = 0.;
	double err;
	double tol = 0.1;
	double g = 1./2;

	double *array;
	array = (double*)malloc(2*sizeof(double));

	int i;

	FILE *in_ptr;
	in_ptr = fopen("rk_adap_bs32.dat","w");

	array[0] = 0.5;
	array[1] = 0.5;

	for (i=0;i<200;i++)
	{
		rk_adap_step(x, array,h);
		err = fabs(array[0]-array[1]);
//		printf("%lf, %lf \n", x, err);
		if (err > tol)
		{
			h = h*pow(g*tol/err, 1./5);
//			printf("redo step! \n");
		}
//		printf("%lf, %lf \n", x, err);
//		printf("%lf, %lf, %lf \n", x, array[0], array[1]);
		else
		{
			fprintf(in_ptr, "%lf, %lf, %lf \n", x, array[0], array[1]);
			x += h;
		}
	}

	fclose(in_ptr);
	return (0);
}

double func(double x, double y)
{
	return (10*exp(-pow(x-2,2)/(2*pow(0.075,2))) - 0.6*y);
}

void rk_adap_step(double x , double *array, double h)
{
	double k1, k2, k3, k4;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +h/2., y+k1*h/2.);
	k3 = (*func)(x +3*h/4., y +3*k2*h/4.);
	k4 = (*func)(x +h, y +(2*k1/9. +k2/3. +4*k3/9.)*h);

	array[0] = array[0] + (2*k1/9. +k2/3. +4*k3/9.)*h;
	array[1] = array[0] + (7*k1/24. +k2/4. +k3/3. +k4/8.)*h;

	return;
}
