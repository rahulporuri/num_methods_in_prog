/*FILE: integ_test.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Version: Original

Date: 23 Jan 2012

Revision-History:
	10 Feb 2012

Comments:
23 Jan 2012: This is the main code that calls various subroutines to integrate simple functions.

10 Feb 2012: Using structures and pointers for the parameters of the function.
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
	double alpha, beta;			/*parameters that the function depends on*/
	
	double ans_simp;				/*calculated result using simpson's rule*/
	double ans_simp_1;				/*calculated result using simpson's rule*/
	double ans_simp_2;				/*calculated result using simpson's rule*/
		
	double err_simp;				/*rel err in simpson rule*/
	
	double a,b;							/*lower and upper limits of integration*/
	double c,d;							/*lower and upper limits of integration*/
	
	struct func_struct my_var;	/*variable of type struct func_struct*/
	void *params_ptr;				/*pointer that will eventually point to the structure*/
	
	/*initializations*/
	a = -0.5;
	b = 0.5;
	c = 0.5;
	d = 1.;

	
	N_max = 1000;
	
	alpha = 1.;
	beta = 1.;
	
	exact = -0.4185487713402663;
	
	int_ptr = fopen("integ_test_quadratic_vs_N_max_new.dat", "w");
	
	fprintf(int_ptr, "#file rel error for integrations of simple functions using simpson's rule\n");
	fprintf(int_ptr, "#a:%f b :%f alpha:%f beta:%f \n", a, b, alpha, beta);
	fprintf(int_ptr, "#N_max \t \t err_simp \n");
		
	/*loading the structure*/
	my_var.alpha0 = alpha;
	my_var.beta0 = beta;
	
	params_ptr = &my_var;
	
	/*looping over N_max*/
	for(i = 3; i < N_max; i += 2)
	{
		/*calling different integration routines*/
		ans_simp_1 = simpson_rule(i, a, b, &my_func_xsq, params_ptr);
		ans_simp_2 = simpson_rule(i, c, d, &my_func_xsq_2, params_ptr);
		
		ans_simp = -(ans_simp_1 +ans_simp_2);
		err_simp = fabs((ans_simp - exact)/(ans_simp + exact));
		
		/*writing result into file*/
		fprintf(int_ptr, "%d \t %e \n", i, err_simp);
		
		/*printing stuff to screen*/
		printf("N:%d exact:%e simp:%e \n", i, exact, ans_simp);
	}
	
	fclose(int_ptr);
	
	return(0);
}
/*****************************************************************************/
double
my_func_xsq(double x, void *params_ptr)
{
	double alpha;
	double beta;
	
	alpha = ((struct func_struct *) params_ptr) -> alpha0;
	beta = ((struct func_struct *) params_ptr) -> beta0;
	
	return(x*sin(alpha/beta * x));
}

double
my_func_xsq_2(double x, void *params_ptr)
{
	double alpha;
	double beta;
	
	alpha = ((struct func_struct *) params_ptr) -> alpha0;
	beta = ((struct func_struct *) params_ptr) -> beta0;
	
	return(sin(alpha/beta * x));
}

/******************************************************************************/
/******************************************************************************/
