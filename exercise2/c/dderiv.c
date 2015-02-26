/*FILE: dderiv.c 

Programer: Poruri Sai Rahul email ID: rahul.poruri@gmail.com

Date: 14 Feb 2015

Version: Original

Revision-History:

Comments:
26 Jan 2012: This code can be called from other codes and calculates the second derivative of the function that is passed in.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**************** Function prototype **********************************/
double
dderiv(double x0, double h, double (*func)(double, void *), void *params_ptr);
/**********************************************************************/

double
dderiv(double x0, double h, double (*func)(double, void *), void *params_ptr)
{
	double ans;			/*variable that stores the answer*/
	
	ans = ((*func)(x0 + h, params_ptr) + (*func)(x0 - h, params_ptr) - 2*(*func)(x0, params_ptr))/(h*h);

	return(ans);
}
