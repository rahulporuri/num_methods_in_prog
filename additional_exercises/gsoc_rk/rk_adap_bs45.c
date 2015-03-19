/*
Program : adaptive runge kutta routine using Bogacki-Shampine 3(2) coefficients
Author : Poruri Sai Rahul rahul.poruri@gmail.com

Comments :
        We find a numerical solution to the first order differential equation dy/dx = func(y,x), where func(y,x) is defined below.
        An adaptive Runge-Kutta method using the Bogacki-Shampine 3(2) coefficients is used as the stepper routine, defined as rk_adap_step.
        Step size is changed depending on the ratio of the tolerance to the absolute error between the third and the second order estimates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double, double);
void rk_adap_step(double, double *, double);

int
main(void)
{
	double h = 0.25;					/*initial estimate of step-size*/
	double x = 0.;
	double err;					/*error between the third and second order estimates*/
	double tol = 0.1;				/*set the tolerance that you would like the adaptive routine to achieve/maintain*/
	double g = 1./2;				/*scale factor while changing the step size*/
	double pre_step_y;				/*variable to keep track of the y estimated in the previous step*/

	int fn_calls;
	fn_calls =0;

	double *array;
	array = (double*)malloc(2*sizeof(double));
	/*we are going to save the third and second order estimates as array elements, which will be passed to the stepper*/

	FILE *in_ptr;
	in_ptr = fopen("rk_adap_bs32.dat","w");

	array[0] = 0.5;
	array[1] = 0.5;

	while (x<1.)
	{
		pre_step_y = array[0];			/*load the pre_step_y before calling the stepper function*/
		rk_adap_step(x, array,h);
		fn_calls += 4;
		err = array[1];
		printf("%lf, %lf \n", x, err);

		if (err > tol)
		{
			h = h*pow(g*tol/err, 1./5);	/*adaptive step size to achieve desired tolerance*/
			array[0] = pre_step_y;		/*redo previous step with the corresponding x,y*/
			printf("redo step! \n");
		}

//		printf("%lf, %lf \n", x, err);
//		printf("%lf, %lf, %lf \n", x, array[0], array[1]);

		else
		{
			/*if tolerance level is achieved, save the value and move to the next step*/
//			fprintf(in_ptr, "%lf, %lf, %lf \n", x, array[0], array[1]);
			x += h;
		}
	}

	fprintf(in_ptr, "## the total number of function calls made were %d \n", fn_calls);
	fclose(in_ptr);
	return (0);
}

double func(double x, double y)
{
	return (10*exp(-(x-2)*(x-2)/(2*(0.075*0.075))) - 0.6*y);
}

void rk_adap_step(double x , double *array, double h)
{
	const double A21 = 1/6;
	const double A31 = 2/27;
	const double A32 = 4/27;
	const double A41 = 183/1372;
	const double A42 = -162/343;
	const double A43 = 1053/1372;
	const double A51 = 68/297;
	const double A52 = -4/11;
	const double A53 = 42/143;
	const double A54 = 1960/3861;
	const double A61 = 597/22528;
	const double A62 = 81/352;
	const double A63 = 63099/585728;
	const double A64 = 58653/366080;
	const double A65 = 4617/20480;
	const double A71 = 174197/959244;
	const double A72 = -30942/79937;
	const double A73 = 8152137/19744439;
	const double A74 = 666106/1039181;
	const double A75 = -29421/29068;
	const double A76 = 482048/414219;
	const double A81 = 587/8064;
	const double A82 = 0;
	const double A83 = 4440339/15491840;
	const double A84 = 24353/124800;
	const double A85 = 387/44800;
	const double A86 = 2152/5985;
	const double A87 = 7267/94080;

	const double B1 = 2479/34992;
	const double B2 = 0;
	const double B3 = 123/416;
	const double B4 = 612941/3411720;
	const double B5 = 43/1440;
	const double B6 = 2272/6561;
	const double B7 = 79937/1113912;
	const double B8 = 3293/556956;

	const double C1 = 0;
	const double C2 = 1/6;
	const double C3 = 2/9;
	const double C4 = 3/7;
	const double C5 = 2/3;
	const double C6 = 3/4;
	const double C7 = 1;
	const double C8 = 1;

	const double E1 = -3/1280;
	const double E2 = 0;
	const double E3 = 6561/632320;
	const double E4 = -343/20800;
	const double E5 = 243/12800;
	const double E6 = -1/95;
	const double E7 = 0;

	double k1, k2, k3, k4, k5, k6, k7, k8;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +C2*h, y +A21*k1*h);
	k3 = (*func)(x +C3*h, y +(A31*k3 +A32*k2)*h);
	k4 = (*func)(x +C4*h, y +(A41*k1 +A42*k2 +A43*k3)*h);
	k5 = (*func)(x +C5*h, y +(A51*k1 +A52*k2 +A53*k3 +A54*k4)*h);
	k6 = (*func)(x +C6*h, y +(A61*k1 +A62*k2 +A63*k3 +A64*k4 +A65*k5)*h);
	k7 = (*func)(x +C7*h, y +(A71*k1 +A72*k2 +A73*k3 +A74*k4 +A75*k5 +A76*k6)*h);
	k8 = (*func)(x +C8*h, y +(A81*k1 +A82*k2 +A83*k3 +A84*k4 +A85*k5 +A86*k6 +A87*k7)*h);
	/*Bogacki-Shampine 4(5) adaptive RK*/

	array[1] = array[1] + (E1*k1 +E2*k2 +E3*k3 +E4*k4 +E5*k5 +E6*k6 +E7*k7)*h;
	/*array[1] is the error estimate between the fourth and fifth order*/
	array[0] = array[0] + (B1*k1 +B2*k2 +B3*k3 +B4*k4 +B5*k5 +B6*k6 +B7*k7 +B8*k8)*h;
	/*array[0] is the fourth order estimate*/
	return;
}
