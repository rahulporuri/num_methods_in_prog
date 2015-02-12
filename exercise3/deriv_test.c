/*FILE: deriv_test.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Date:4 Jan 2013

Version: Original

Revision-History:
	4 Jan 2013
	9 Feb 2015

Comments:
26 Jan 2012: This calls deriv.c and calculates derivatives of function at a point x0.

4 Jan 2013: The second derivative has been taken out for class demonstration purposes.

9 Feb 2015: The code has been modified to take an input file and an output file. 
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846
/******************* Function prototype *************************************/

double
deriv(int opt, double x0, double h, double (*func) (double, void *), void *params_ptr);

double
my_func(double x, void *params_ptr);

struct func_struct
{
	double alpha0;    /*some parameter that the function depends on*/
  	double beta0;     /*some other parameter that the function depends on*/
};
/*****************************************************************************/

int
main(int argc, char *argv[])
{
	FILE *in_ptr;							/*carries input parameters*/
	FILE *err1_ptr;						/*stores the error in first derivative*/
	FILE *der_ptr;						/*stores the calculates and the exact values of the derivative*/
	
	int opt;									/*this chooses between forward or central difference: opt == 1 => forward difference and opt == 2 => central difference*/
	
	double x0;								/*point where the derivative is obtained*/
	double df;								/*variable that stores the derivative of exp(x)*/
	double h;									/*step size*/
	double h_min, h_max;			/*max and min of step size*/
	double exact;							/*exact value of the derivative*/
	double err;								/*this is the relative error*/
	double alpha;							/*value of the function parameter*/
	double beta;							/*value of the function parameter*/
	
	char line[256];

	struct func_struct my_var;	/*variable of type struct func_struct*/	
	void *params_ptr;					/*pointer to variable*/
	
	/*initialization*/	
	x0 = M_PI;
	
	h_min = 1e-17;
	
	h_max = 0.1;
		
	/*opening and reading input file*/
	in_ptr = fopen(argv[1], "r");

	/*skipping this line as it is a comment in the file*/
	fgets(line, sizeof(line), in_ptr);
		
	/*obtaing the value of alpha*/
	fgets(line, sizeof(line), in_ptr);
	sscanf(line, "%lf", &alpha);

	/*obtaing the value of beta*/
	fgets(line, sizeof(line), in_ptr);
	sscanf(line, "%lf", &beta);
	
	fclose(in_ptr);
	
	/*opening output files*/
	err1_ptr = fopen(argv[2], "w");
	der_ptr = fopen(argv[3], "w");	

	fprintf(err1_ptr, "#contains rel err in first der of exp(x) as a function of h \n");
	fprintf(err1_ptr, "#Methods: Forward and central difference \n");
	fprintf(err1_ptr, "#h \t err-forward \t err-central \n");

	/*loading the structure*/
	my_var.alpha0 = alpha;
	my_var.beta0 = beta;
	params_ptr = &my_var;

	/*initial value of h*/	
	h = h_max;

	exact = my_func(x0,params_ptr);
	
	/*looping though h values*/
	while(h > h_min)
	{
		/*calculating derivative using forward difference*/
		opt = 1;
		
		printf("Calculating first derivative for h:%e \n\n", h);
		
		/*calling deriv.c*/
		df = deriv(opt, x0, h, &my_func, params_ptr);
		
		err = fabs((df - exact)/(exact));
		
		printf("forward difference h:%e x0:%f df:%f exact:%f err:%e \n", h, x0, df, exact, err);
		
		fprintf(err1_ptr, "%e \t %e \t", h, err);
		
		fprintf(der_ptr, "%e \t %e \t %e \t", h, exact, df);
		
		/*calculating derivative using central difference*/
		opt = 2;
		
		/*calling deriv.c*/
		df = deriv(opt, x0, h, &my_func, params_ptr);
		
		err = fabs((df - exact)/(exact));
		
		printf("Central difference h:%e x0:%f df:%f exact:%f err:%e \n\n", h, x0, df, exact, err);
		
		fprintf(err1_ptr, "%e \n", err);
		
		fprintf(der_ptr, "%e \n", df);
		
		h = h/2.;
	}
	
	fclose(err1_ptr);
	fclose(der_ptr);
	
	return(0);
}

/****************************************************************************/
double
my_func(double x, void *params_ptr)
{
	double alpha;
	double beta;

	alpha = ((struct func_struct *) params_ptr) -> alpha0;
	beta = ((struct func_struct *) params_ptr) -> beta0;

	
	return(sin(alpha * x) +(beta * x));
}
