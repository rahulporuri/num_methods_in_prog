/*FILE: trapezoidal_rule.c

Programer: Sunethra Ramanan  suna@physics.iitm.ac.in

Date: 23 Jan 2012

Version: Original

Revision-History:

Comments:
23 Jan 2012: This calculates integrals using the trapezoidal rule and can be called from other codes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**************** Begin Function Prototype ******************************/
double
trapezoidal_rule(int npts, double a, double b, double (* func) (double));

/************************************************************************/

double
trapezoidal_rule(int npts, double a, double b, double (* func) (double))
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
		
		sum += (*func)(x);
	}
	
	/*evaluating the function at the end points*/
	fa = (*func)(a);
	fb = (*func)(b);
	
	sum = (sum + (1./2.) * (fa + fb)) * h;
	
	return(sum);
}

/**********************************************************************************/
/**********************************************************************************/
