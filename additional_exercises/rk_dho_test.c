#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double, double);
void rk2_step(double *, double);
void rk4_step(double *, double *, double);

int
main(void)
{
	double h = 0.1;
	int i;

	double tol = 0.01;
	double g = 0.5;
	double err;
	
	double x_prior, y_prior;

	double *array;
	double *array_test;
	array = (double*)malloc(2*sizeof(double));
	array_test = (double*)malloc(2*sizeof(double));

	FILE *in_ptr;
	in_ptr = fopen("rk_dho_test.dat","w");

	array[0] = 1.;
	array[1] = 0.;
	array_test[0] = 1. ;
	array_test[1] = 0.;

//	h = 0.1;

	for (i=0;i<10;i++)
	{
		x_prior = array[0];
		y_prior = array[1];

		rk2_step(array,h);
		rk4_step(array, array_test, h);
		err = fabsf(array_test[0] - array[0]);

		if (err > tol)
		{
			h = h*pow(g*tol/err,1./5);
			array[0] = x_prior;
			array[1] = y_prior;
			printf("redo step! \n");
		}
		printf("%lf, %lf \n", err, h);
//		printf("%lf, %lf, %lf, %lf \n", array[0], array[0]-array_test[0], array[1], array[1]-array_test[1]);
//		fprintf(in_ptr,"%lf, %lf \n", x, y);
	}

	fclose(in_ptr);
	return (0);
}

double func(double x, double y)
{
	return (-(2*x+y)/2.);
}

void rk2_step(double *array, double h)
{
	double k1, k2;
	double K1, K2;
	double x,y;

	x = array[0];
	y = array[1];

	k1 = y;
	K1 = (*func)(x,y);
	k2 = y +K1*h;
	K2 = (*func)(x+h/2.,y+k1*h/2.);

	array[0] = x + h*(k1+k2)/2; // aces!
	array[1] = y + h*(K1+K2)/2;
//	y += dy*h + 1./2*(K1)*pow(h,2); // aces!

	return;
}

void rk4_step(double *array, double *array_test, double h)
{
	double k1, k2, k3, k4;
	double K1, K2, K3, K4;
	double x,y;

	x = array[0];
	y = array[1];

	k1 = y;
	K1 = (*func)(x,y);
	k2 = y +K1*h/2.;
	K2 = (*func)(x+h/2.,y+k1*h/2.);
	k3 = y +K2*h/2.;
	K3 = (*func)(x+h/2.,y+k2*h/2.);
	k4 = y +K3*h;
	K4 = (*func)(x+h,y+k3*h);

	array_test[0] = x +h*(k1 +2*k2 +2*k3 +k4)/6.;
	array_test[1] = y +h*(K1 +2*K2 +2*K3 +K4)/6.;

	return;
}
