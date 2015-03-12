/*
Program : adaptive runge kutta routine using Fehlberg 4,5 coefficients
Author : Poruri Sai Rahul rahul.poruri@gmail.com

Comments :
	We find a numerical solution to the first order differential equation dy/dx = func(y,x), where func(y,x) is defined below.
	An adaptive Runge-Kutta Fehlberg method using the Cash-Karp coefficients is used as the stepper routine, defined as rk_adap_step.
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
	double h = 0.25;		/*initial estimate of step-size*/
	double x = 0.;
	double err;		/*error between the fourth and fifth order estimates*/
	double tol = 0.1;	/*set the tolerance that you would like the adaptive routine to achieve/maintain*/
	double g = 1./2;	/*scale factor while changing the step size*/
	double pre_step_y;	/*variable to keep track of the y estimated in the previous step*/

	double *array;
	array = (double*)malloc(2*sizeof(double));
	/*we are going to save the fourth and fifth order estimates as array elements, which will be passed to the stepper*/

	int fn_calls;			/*dummy variable for the counter*/
	fn_calls =0;

	FILE *in_ptr;
	in_ptr = fopen("rk_adap_test.dat","w");

	array[0] = 0.5;
	array[1] = 0.5;

	while (x<10.)
	{
		pre_step_y = array[0];			/*load the pre_step_y before calling the stepper function*/
		rk_adap_step(x, array,h);
		fn_calls += 6;
		err = fabs(array[0]-array[1]);
//		printf("%lf, %lf \n", x, err);
		if (err > tol)
		{
			h = h*pow(g*tol/err, 1./5);	/*adaptive step size to achieve desired tolerance*/
			array[0] = pre_step_y;		/*redo previous step with the corresponding x,y*/
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

	fprintf(in_ptr,"## the total number of function calls made were %d \n", fn_calls);
	fclose(in_ptr);
	return (0);
}

double func(double x, double y)
{
	return (10*exp(-(x-2)*(x-2)/(2*(0.075*0.075))) - 0.6*y);
}

void rk_adap_step(double x , double *array, double h)
{
	const double c2= 1./5, a21= 1./5;
	const double c3= 3./10, a31= 3./10, a32= 9./40;
	const double c4= 3./5, a41= 3./10, a42= -9./10, a43=6./5;
	const double c5= 1., a51= -11./54, a52= 5./2, a53= -70/27, a54= 35/27;
	const double c6= 7./8, a61= 1631./ 55296, a62= 175./512, a63= 575./13824, a64= 44275./110592, a65= 253./4096;

	const double b1= 37./378, b3= 250./621, b4= 125./594, b6=512./1771;
	const double B1= 2825./27648, B3= 12575./48384, B4= 13525./55296, B5= 277./14336, B6= 1./4;

	double k1, k2, k3, k4, k5, k6;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +c2*h, y +a21*k1*h);
	k3 = (*func)(x +c3*h, y +(a31*k1 +a32*k2)*h);
	k4 = (*func)(x +c4*h, y +(a41*k1 +a42*k2 +a43*k3)*h);
	k5 = (*func)(x +c5*h, y +(a51*k1 +a52*k2 +a53*k3 +a54*k4)*h);
	k6 = (*func)(x +c6*h, y +(a61*k1 +a62*k2 +a63*k3 +a64*k4 +a65*k5)*h);
	/*Cash-Karp RK*/

	array[0] = array[0] + (b1*k1 +b3*k3 +b4*k4 +b6*k6)*h;
	/*array[0] is the fourth order estimate*/
	array[1] = array[0] + (B1*k1 +B3*k3 +B4*k4 +B5*k5 +B6*k6)*h;
	/*array[1] is the fifth order estimate*/

	return;
}
