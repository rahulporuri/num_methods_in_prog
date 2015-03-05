/*FILE: simpson_rule.c

Programer: Sunethra Ramanan  suna@physics.iitm.ac.in

Date: 23 Jan 2012

Version: Original

Revision-History:

Comments:
23 Jan 2012: This calculates integrals using the simpson rule and can be called from other codes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**************** Begin Function Prototype ******************************/
double
simpson_rule(int npts, double a, double b, double (* func) (double, void *), void *params_ptr);

struct func_struct
{
	double alpha0;    /*some parameter that the function depends on*/
  double beta0;     /*some other parameter that the function depends on*/
};

/************************************************************************/

double
simpson_rule(int npts, double a, double b, double (* func) (double, void *), void *params_ptr)
{
	int i;															/*counter*/
	
	double sum;													/*stores the result of integration*/
	double h;														/*step size*/
	double x;														/*value of x*/
	double fa, fb;											/*value of the function at the end points*/
	
	/*initialization*/
	sum = 0.;
	
	h = (b - a)/(double)(npts-1);
	
	/*evaluating the function between a and b*/
	for(i = 1; i < npts - 1; i ++)
	{
		/*value of x*/
		x = a + i * h;
		
		/*picking out odd and even terms*/
		if(i%2 != 0) /*odd terms*/
		{
			sum += 4. * (*func)(x, params_ptr);
		}
		else /*even terms*/
		{
			sum += 2. * (*func)(x, params_ptr);
		}
	}
	
	/*evaluating the function at the end points*/
	fa = (*func)(a, params_ptr);
	fb = (*func)(b, params_ptr);
	
	sum = (sum + fa + fb) * (h/3.);
	
	return(sum);
}

/**********************************************************************************/
/**********************************************************************************/