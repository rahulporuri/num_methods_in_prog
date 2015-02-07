/*FILE: deriv.c 

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Date: 26 Jan 2012

Version: Original

Revision-History:

Comments:
26 Jan 2012: This code can be called from other codes and calculates the derivative of the function that is passed in.
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
	double ans;											/*variable that stores the answer*/
	
	ans = ((*func)(x0 + h, params_ptr) + (*func)(x0 - h, params_ptr) - 2*(*func)(x0, params_ptr))/(h*h);

	return(ans);
}
