/*FILE: deriv_test.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Date:4 Jan 2013

Version: Original

Revision-History:
	4 Jan 2013

Comments:
26 Jan 2012: This calls deriv.c and calculates derivatives of function at a point x0.

4 Jan 2013: The second derivative has been taken out for class demonstration purposes.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/******************* Function prototype *************************************/

double
dderiv(double x0, double h, double (*func) (double, void *), void *params_ptr);

double
my_func(double x, void *params);
/*****************************************************************************/

int
main(int argc, char *argv[])
{
	FILE *err1_ptr;						/*stores the error in first derivative*/
/*	FILE *der_ptr;	*/					/*stores the calculates and the exact values of the derivative*/
	
	double x0;								/*point where the derivative is obtained*/
	double df;							/*variable that stores the forward derivative of exp(x)*/
	double h;								/*step size*/
	double h_min, h_max;			/*max and min of step size*/
	double exact;							/*exact value of the derivative*/
	double err;								/*this is the relative error in forward method*/

	
	void *params_ptr;

	/*initialization*/
	if(argc != 2)
	{
		printf("incorrect number of command line variables \n");
		exit(1);
	}
	else if(argc == 2)
	{
		x0 = atof(argv[1]);
	}

	h_min = 1e-17;
	
	h_max = 0.1;
		
	/*derivative of exp(x0)*/
	exact = exp(x0);
	
	/*opening output files*/
	err1_ptr = fopen("deriv_test_second_err.dat", "w");
	
	fprintf(err1_ptr, "#contains rel err in second der of exp(x) as a function of h \n");
	fprintf(err1_ptr, "#Methods: central difference \n");
	fprintf(err1_ptr, "#h \t err-central \n");
	
	h = h_max;
	
	params_ptr = NULL;

	/*looping though h values*/
	while(h > h_min)
	{
		/*calculating derivative using forward difference*/
		
		printf("Calculating second derivative for h:%e \n\n", h);
		
		/*calling deriv.c*/
		df = dderiv(x0, h, &my_func, params_ptr);
		
		err = fabs((df - exact)/(exact));

		/*calculating derivative using central difference*/
				
		printf("central difference h:%e x0:%f df:%f exact:%f err:%e \n", h, x0, df, exact, err);

		fprintf(err1_ptr, "%e \t %e \n", h, err);
		
		h = h/2.;
	}
	
	fclose(err1_ptr);
/*	fclose(der_ptr);*/
	
	return(0);
}

/****************************************************************************/
double
my_func(double x, void *params)
{
	params = NULL;

	return(exp(x));
}
