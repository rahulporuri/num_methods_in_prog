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
	in_ptr = fopen("rk_adap_test.dat","w");

	array[0] = 0.5;
	array[1] = 0.5;

	for (i=0;i<100;i++)
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
	double k1, k2, k3, k4, k5, k6;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +h/5., y+k1*h/5.);
	k3 = (*func)(x +3*h/10., y +(3*k1/40. +9*k2/40.)*h);
	k4 = (*func)(x +3*h/5., y +(3*k1/10 -9*k2/10. + 6*k3/5)*h);
	k5 = (*func)(x +h, y +(-11*k1/54 +5*k2/2. -70*k3/27 +35*k4/27)*h);
	k6 = (*func)(x +7*h/8., y +(1631*k1/55296 +175*k2/512 + 575*k3/13824 +44275*k4/110592 +253*k5/4096)*h);

	array[0] = array[0] + (37*k1/378. +250*k3/621. +125*k4/594. +512*k6/1771.)*h;
	array[1] = array[0] + (2825*k1/27648. +12575*k3/48384. +13525*k4/55296. +277*k5/14336. +k6/4.)*h;

	return;
}
