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
	double h = 0.1;						/*initial estimate of step-size*/
	double x = 0.;
	double err;						/*error between the fourth and fifth order estimates*/
	double tol = 0.1;					/*set the tolerance that you would like the adaptive routine to achieve/maintain*/
	double g = 1./2;					/*scale factor while changing the step size*/
	double pre_step_y;					/*variable to keep track of the y estimated in the previous step*/

	double *array;
	array = (double*)malloc(2*sizeof(double));
        /*we are going to save the fourth and fifth order estimates as array elements, which will be passed to the stepper*/

	int i;							/*dummy variable for the counter*/

	FILE *in_ptr;
	in_ptr = fopen("rk_adap_dg45.dat","w");

	array[0] = 0.5;
	array[1] = 0.5;

	for (i=0;i<200;i++)
	{
		pre_step_y = array[0];				/*load the pre_step_y before calling the stepper function*/
		rk_adap_step(x, array,h);
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

	fclose(in_ptr);
	return (0);
}

double func(double x, double y)
{
	return (10*exp(-pow(x-2,2)/(2*pow(0.075,2))) - 0.6*y);
}

void rk_adap_step(double x , double *array, double h)
{
	double k1, k2, k3, k4, k5, k6, k7;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +2*h/9., y+2*k1*h/9.);
	k3 = (*func)(x +h/3., y +(k1/12. +k2/4.)*h);
	k4 = (*func)(x +h/2., y +(k1/8 + 3*k3/8)*h);
	k5 = (*func)(x +3*h/5., y +(91*k1/500 -27*k2/100. +78*k3/125 +8*k4/125)*h);
	k6 = (*func)(x +h, y +(-11*k1/20 +27*k2/20 + 12*k3/5 -36*k4/5 +5*k5)*h);
	k7 = (*func)(x +h, y +(1*k1/12 +27*k3/32 -4*k4/3 +125*k5/96 +5*k6/48)*h);
	/*Hogham, D.J & Hall, G. RK*/

	array[0] = array[0] + (k1/12. +27*k3/32. -4*k4/3. +125*k5/96. +5*k6/48.)*h;
	/*array[0] is the fourth order estimate*/
	array[1] = array[0] + (2*k1/15. +27*k3/80. -2*k4/15. +25*k5/48. +k6/24.+k7/10.)*h;
	/*array[1] is the fifth order estimate*/

	return;
}
