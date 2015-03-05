/*FILE: integ_test.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Version: Adapted from original provided

Date: 5 Mar 2015

Revision-History:

Comments:
5 Mar 2015 : This code computes the integral using two methods, by assuming that the function is x**(1./3.)
and by performing a variable change from x = u**3.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integ_test.h"

int
main(void)
{
	FILE *int_ptr;					/*file pointer to file that stores the rel error as a function of N_max*/
	
	int i;									/*counter*/
	int N_max;							/*no. of integration points*/
	
	double exact;						/*exact result*/
	
	double ans_simp;				/*calculated result using simpson's rule*/
	double err_simp;				/*rel err in simpson rule*/

	double ans_simp_test;				/*calculated result for the test function using simpson's rule*/
	double err_simp_test;				/*rel err for the result from the test function in simpson rule*/

	double a,b;							/*lower and upper limits of integration*/
	
	void *params_ptr;				/*pointer that will eventually point to the structure*/
	
	/*initializations*/
	a = 0.;
	b = 1.;
	
	N_max = 1000;
		
	exact = 0.75;
	
	int_ptr = fopen("integ_test_fn_vs_N_max.dat", "w");
	
	fprintf(int_ptr, "#file rel error for integrations of simple functions using simpson's rule\n");
	fprintf(int_ptr, "#a:%f b :%f \n", a, b);
	fprintf(int_ptr, "#N_max \t \t err_simp \n");
		
	/*there is nothing to pass, but the params_ptr has to be passed in as it is a generic function prototype, therefore we pass a NULL pointer*/		
	params_ptr = NULL;
	
	/*looping over N_max*/
	for(i = 3; i < N_max; i += 2)
	{
		/*calling different integration routines*/
		ans_simp = simpson_rule(i, a, b, &my_func_xsq, params_ptr);
		err_simp = fabs((ans_simp - exact)/(ans_simp + exact));

		ans_simp_test = simpson_rule(i, a, b, &my_func_xsq_test, params_ptr);
		err_simp_test = fabs((ans_simp_test - exact)/(ans_simp_test + exact));
		
		/*writing result into file*/
		fprintf(int_ptr, "%d \t %e \t %e \n", i, err_simp,err_simp_test);
		
		/*printing stuff to screen*/
		printf("N:%d exact:%e simp:%e simp_test:%e \n", i, exact, ans_simp, ans_simp_test);
	}
	
	fclose(int_ptr);
	
	return(0);
}
/*****************************************************************************/
double
my_func_xsq(double x, void *params_ptr)
{
	params_ptr = NULL;
		
	return(pow(x, 1./3.));
}

double
my_func_xsq_test(double x, void *params_ptr)
{
	params_ptr = NULL;
		
	return(3*pow(x, 3.));
}
/******************************************************************************/
