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

	while (x<10.)
	{
		pre_step_y = array[0];			/*load the pre_step_y before calling the stepper function*/
		rk_adap_step(x, array,h);
		fn_calls += 4;
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
	double k1, k2, k3, k4;
	double y;

	y = array[0];

	k1 = (*func)(x,y);
	k2 = (*func)(x +h/2., y+k1*h/2.);
	k3 = (*func)(x +3*h/4., y +3*k2*h/4.);
	k4 = (*func)(x +h, y +(2*k1/9. +k2/3. +4*k3/9.)*h);
	/*Bogacki-Shampine 3(2) adaptive RK*/
	
	array[0] = array[0] + (2*k1/9. +k2/3. +4*k3/9.)*h;
	/*array[0] is the third order estimate*/
	array[1] = array[0] + (7*k1/24. +k2/4. +k3/3. +k4/8.)*h;
	/*array[1] is the second order estimate*/
	return;
}
