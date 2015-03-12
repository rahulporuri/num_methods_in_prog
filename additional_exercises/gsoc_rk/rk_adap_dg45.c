/*
Program : adaptive runge kutta routine using Higham, D.J. & Hall, G. 4,5 coefficients
Author : Poruri Sai Rahul rahul.poruri@gmail.com

Comments :
        We find a numerical solution to the first order differential equation dy/dx = func(y,x), where func(y,x) is defined below.
        An adaptive Runge-Kutta Fehlberg method using the Higham, D.J. & Hall, G. 4,5 coefficients is used as the stepper routine, defined as rk_adap_step.
        Step size is changed depending on the ratio of the tolerance to the absolute error between the fifth and the fourth order estimates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double, double);
void rk_adap_step(double, double *, double);

int
main(void)
{
	double h = 0.25;						/*initial estimate of step-size*/
	double x = 0.;
	double err;						/*error between the fourth and fifth order estimates*/
	double tol = 0.1;					/*set the tolerance that you would like the adaptive routine to achieve/maintain*/
	double g = 1./2;					/*scale factor while changing the step size*/
	double pre_step_y;					/*variable to keep track of the y estimated in the previous step*/

	double *array;
	array = (double*)malloc(2*sizeof(double));
        /*we are going to save the fourth and fifth order estimates as array elements, which will be passed to the stepper*/

	int fn_calls;
	fn_calls =0;

	FILE *in_ptr;
	in_ptr = fopen("rk_adap_dg45.dat","w");

	array[0] = 0.5;
	array[1] = 0.5;

	while (x<10.)
	{
		pre_step_y = array[0];				/*load the pre_step_y before calling the stepper function*/
		rk_adap_step(x, array,h);
		fn_calls += 7;
		err = fabs(array[0]-array[1]);
//		printf("%lf, %lf \n", x, err);
		if (err > tol)
		{
			h = h*pow(g*tol/err, 1./5);		/*adaptive step size to achieve desired tolerance*/
			array[0] = pre_step_y;			/*redo previous step with the corresponding x,y*/
//			printf("redo step! \n");
		}
//		printf("%lf, %lf \n", x, err);
//		printf("%lf, %lf, %lf \n", x, array[0], array[1]);
		else
		{
			/*if tolerance level is achieved, save the value and move to the next step*/
			fprintf(in_ptr, "%lf, %lf, %lf \n", x, array[0], array[1]);
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
	const double c2= 2./9, a21= 2./9;
	const double c3= 1./3, a31= 1./12, a32=1./4;
	const double c4= 1./2, a41= 1./8,  a43=3./8;
	const double c5= 3./5, a51= 91./500, a52= -27./100, a53= 78./125, a54=8./125;
	const double c6= 1,    a61= -11./20, a62= 27./20,   a63= 12./5,   a64= -36./5, a65= 5;
	const double c7= 1,    a71= 1./12,   a73= 27./32,   a74= -4./3,   a75= 125./96, a76= 5./48;

	const double b1= 1./12, b3= 27./32, b4= -4./3, b5= 125./96, b6= 5./48;
	const double B1= 2./15, B3= 27./80, B4= -2./15, B5= 25./48,  B6= 1./24, B7= 1./10;

	double k1, k2, k3, k4, k5, k6, k7;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +c2*h, y+a21*k1*h);
	k3 = (*func)(x +c3*h, y +(a31*k1 +a32*k2)*h);
	k4 = (*func)(x +c4*h, y +(a41*k1 +a43*k3)*h);
	k5 = (*func)(x +c5*h, y +(a51*k1 +a52*k2 +a53*k3 +a54*k4)*h);
	k6 = (*func)(x +c6*h, y +(a61*k1 +a62*k2 +a63*k3 +a64*k4 +a65*k5)*h);
	k7 = (*func)(x +c7*h, y +(a71*k1 +a73*k3 +a74*k4 +a75*k5 +a76*k6)*h);
	/*Hogham, D.J & Hall, G. RK*/

	array[0] = array[0] + (b1*k1 +b3*k3 +b4*k4 +b5*k5 +b6*k6)*h;
	/*array[0] is the fourth order estimate*/
	array[1] = array[0] + (B1*k1 +B3*k3 +B4*k4 +B5*k5 +B6*k6 +B7*k7)*h;
	/*array[1] is the fifth order estimate*/

	return;
}
