#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rk2_step(double *, double);
void rk4_step(double *, double *, double);

int
main(void)
{
	FILE *in_ptr;
	double h;
	int i;

	double *array;
	array = (double*)malloc(2*sizeof(double));
	double *array_test;
	array_test = (double*)malloc(2*sizeof(double));

	array[0] =1.;
	array[1] =0.;
	array_test[0] = 1.;
	array_test[1] = 0.;

	h = 0.01;

	in_ptr = fopen("rk45_test.dat","w");
	for (i=0;i<100;i++)
	{
		rk2_step(array,h);
		rk4_step(array, array_test, h);
//		fprintf(in_ptr, "%lf, %lf \n",array[0]-array_test[0], array[1]-array_test[1]);
		if (i/10==0){
		printf("%lf, %lf, %lf, %lf \n",array[0], array[0]-array_test[0], array[1], array[1]-array_test[1]);}
	}
	fclose(in_ptr);
	return(0);
}

void rk2_step(double *array , double h)
{
	double k1, k2;
	double K1, K2;
	double dy = array[1];
	double y = array[0];
	
	k1 = dy;
	K1 = -y;
	k2 = dy +K1*h;
	K2 = -(y +k1*h);
	array[0] = y + h*(k1+k2)/2; // aces!
//	y += dy*h + 1./2*(K1)*pow(h,2); // aces!
	array[1] = dy + h*(K1+K2)/2;

	return;
}

void rk4_step(double *array, double *array_test, double h)
{
	double k1, k2, k3, k4;
	double K1, K2, K3, K4;
	double y = array[0];
	double  dy = array[1];

	k1 = dy;
	K1 = -y;
	k2 = dy +K1*h/2.;
	K2 = -(y +k1*h/2.);
	k3 = dy +K2*h/2.;
	K3 = -(y +k2*h/2.);
	k4 = dy +K3*h;
	K4 = -(y +k3*h);
	array_test[0] = y + h*(k1 +2*k2 +2*k3 +k4)/6.;
	array_test[1] = dy + h*(K1 +2*K2 +2*K3 +K4)/6.;

	return;
}
