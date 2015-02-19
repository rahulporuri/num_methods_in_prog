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
	
	double ans_trap;				/*calculated result using trapezoidal rule*/
	double err_trap;				/*rel err in trapezoidal rule*/

	double ans_adap;				/*calculated result using adaptive rule*/
	double err_adap;				/*rel err in adaptive rule*/
	
	double ans_adaptive;				/*calculated result using adaptive rule*/
	double err_adaptive;				/*rel err in adaptive rule*/

	double a,b;							/*lower and upper limits of integration*/
		
	/*initializations*/
	a = 0.;
	b = 3.;
	
	N_max = 10;
		
	exact = (1/sqrt(2.))*atan(3/sqrt(2.));
	
	int_ptr = fopen("integ_test_exp_alpha_beta_vs_N_max.dat", "w");
	
	fprintf(int_ptr, "#file rel error for integrations of simple functions using trap, simp and gaussian quad\n");
	fprintf(int_ptr, "#a:%f b :%f \n", a, b);
	fprintf(int_ptr, "#N_max \t \t err_trap \t err_simp \t err_gauss \n");
	
	/*looping over N_max*/
	for(i = 3; i < N_max; i ++)
	{
		/*calling different integration routines*/
		ans_trap = trapezoidal_rule(i, a, b, &my_func_xsq);
		
		err_trap = fabs((ans_trap - exact)/(ans_trap + exact));
		
		ans_adap = adaptive_rule(i, a, b, &my_func_xsq);
		
		err_adap = fabs((ans_adap - exact)/(ans_adap + exact));

		ans_adaptive = adap_rule(i, a, b, &my_func_xsq);
		
		err_adaptive = fabs((ans_adaptive - exact)/(ans_adaptive + exact));
		
		/*writing result into file*/
		fprintf(int_ptr, "%d \t %e \t %e \t %e \n", i, err_trap, err_adap, err_adaptive);
		
		/*printing stuff to screen*/
		printf("N:%d exact:%e trap:%e adap:%e adap:%e \n", i, exact, ans_trap, ans_adap, ans_adaptive);
	}
	
	fclose(int_ptr);
	
	return(0);
}
/*****************************************************************************/
double
my_func_xsq(double x)
{

	return(1/(2+x*x));
}

/******************************************************************************/
/******************************************************************************/
