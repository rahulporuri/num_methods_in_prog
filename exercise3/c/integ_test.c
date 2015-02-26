/*FILE: integ_test.c

Programer: Poruri Sai Rahul email ID : rahul.poruri@gmail.com

Version: Adapted from an original from Sunethra Ramaman's codes

Date: 14 Feb 2015

Revision-History:
	14 Feb 2015

Comments:
14 Feb 2015: Using structures and pointers for the parameters of the function.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integ_test.h"

int
main(void)
{
	FILE *int_ptr;					/*file pointer to file that stores the rel error as a function of N_max*/
	
	int i;						/*counter*/
	int N_max;					/*no. of integration points*/
	
	double exact;					/*exact result*/
	double alpha, beta;				/*parameters that the function depends on*/
	
	double ans_trap;				/*calculated result using trapezoidal rule*/
	double err_trap;				/*rel err in trapezoidal rule*/

	double ans_simp;				/*calculated result using simpsons rule*/	
	double err_simp;				/*rel err in simpsons rule*/

	double ans_38ths;				/*calculated result using simpsons rule*/	
	double err_38ths;				/*rel err in simpsons rule*/
	
	double a,b;					/*lower and upper limits of integration*/
	
	struct func_struct my_var;			/*variable of type struct func_struct*/
	void *params_ptr;				/*pointer that will eventually point to the structure*/
	
	/*initializations*/
	a = 0.;
	b = 1.;
	
	N_max = 5000;
	
	alpha = 1.;
	beta = -1.;
	
	exact = alpha/beta * (exp(beta/alpha) - 1.);
	
	int_ptr = fopen("integ_test_exp_alpha_beta_vs_N_max.dat", "w");
	
	fprintf(int_ptr, "#file rel error for integrations of simple functions using trap, simp and three-eights rule\n");
	fprintf(int_ptr, "#a:%f b :%f alpha:%f beta:%f \n", a, b, alpha, beta);
	fprintf(int_ptr, "#N_max \t \t err_trap \t err_simp \t err_gauss \n");
	
	/*loading the structure*/
	my_var.alpha0 = alpha;
	my_var.beta0 = beta;
	
	params_ptr = &my_var;
	
	/*looping over N_max*/
	for(i = 3; i < N_max; i ++)
	{
		/*calling different integration routines*/
		ans_trap = trapezoidal_rule(i, a, b, &my_func_xsq, params_ptr);
		err_trap = fabs((ans_trap - exact)/(ans_trap + exact));

		ans_simp = simpsons_rule(i, a, b, &my_func_xsq, params_ptr);
		err_simp = fabs((ans_simp - exact)/(ans_simp + exact));

		ans_38ths = three_eights_rule(i, a, b, &my_func_xsq, params_ptr);
		err_38ths = fabs((ans_38ths - exact)/(ans_38ths + exact));
		
		/*writing result into file*/
		fprintf(int_ptr, "%d \t %e \t %e \t %e \n", i, err_trap, err_simp, err_38ths);
		
		/*printing stuff to screen*/
		printf("N:%d exact:%e trap:%e simp:%e 3/8ths:%e \n", i, exact, ans_trap, ans_simp, ans_38ths);
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
	
	return(exp((beta * x)/alpha));
}

/******************************************************************************/
/******************************************************************************/
