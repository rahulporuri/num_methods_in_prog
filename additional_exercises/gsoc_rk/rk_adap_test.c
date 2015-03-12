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
	double k1, k2, k3, k4, k5, k6;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +h/5., y+k1*h/5.);
	k3 = (*func)(x +3*h/10., y +(3*k1/40. +9*k2/40.)*h);
	k4 = (*func)(x +3*h/5., y +(3*k1/10 -9*k2/10. + 6*k3/5)*h);
	k5 = (*func)(x +h, y +(-11*k1/54 +5*k2/2. -70*k3/27 +35*k4/27)*h);
	k6 = (*func)(x +7*h/8., y +(1631*k1/55296 +175*k2/512 + 575*k3/13824 +44275*k4/110592 +253*k5/4096)*h);
	/*Cash-Karp RK*/

	array[0] = array[0] + (37*k1/378. +250*k3/621. +125*k4/594. +512*k6/1771.)*h;
	/*array[0] is the fourth order estimate*/
	array[1] = array[0] + (2825*k1/27648. +12575*k3/48384. +13525*k4/55296. +277*k5/14336. +k6/4.)*h;
	/*array[1] is the fifth order estimate*/

	return;
}
