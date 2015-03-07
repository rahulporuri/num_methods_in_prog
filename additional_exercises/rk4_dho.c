#include <stdio.h>
#include <math.h>

double func(double, double);

int
main(void)
{
	double x, y;
	double k1, k2, k3, k4;
	double K1, K2, K3, K4;
	double h;
	int i;

	FILE *in_ptr;
	in_ptr = fopen("rk4_dho.dat","w");

	x = 1.;
	y = 0.;
	h = 0.1;
	for (i=0;i<1000;i++)
	{
		k1 = y;
		K1 = (*func)(x,y);
		k2 = y +K1*h/2.;
		K2 = (*func)(x+h/2.,y+k1*h/2.);
		k3 = y +K2*h/2.;
		K3 = (*func)(x+h/2.,y+k2*h/2.);
		k4 = y +K3*h;
		K4 = (*func)(x+h,y+k3*h);
		x += h*(k1 +2*k2 +2*k3 +k4)/6.;
		y += h*(K1 +2*K2 +2*K3 +K4)/6.;
		fprintf(in_ptr,"%lf, %lf \n", x, y);
	}

	fclose(in_ptr);
	return (0);
}

double func(double x, double y)
{
	return (-(2*x+y)/2.);
}
