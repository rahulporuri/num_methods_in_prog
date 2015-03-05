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
simpson_rule(int npts, double a, double b, double z, double (* func) (double, double));

/************************************************************************/

double
simpson_rule(int npts, double a, double b, double z, double (* func) (double, double))
{
	int i;															/*counter*/
	
	double sum;													/*stores the result of integration*/
	double h;														/*step size*/
	double x;														/*value of x*/
	double fa, fb;											/*value of the function at the end points*/
	double z0;
	double y;
	
	/*initialization*/
	sum = 0.;
	z0 = z;
	
	h = (b - a)/(double)(npts-1);
	
	/*evaluating the function between a and b*/
	for(i = 1; i < npts - 1; i ++)
	{
		/*value of x*/
		x = a + i * h;
		y = (*func)(x,z);

		/*picking out odd and even terms*/
		if(i%2 != 0) /*odd terms*/
		{
			if (y != y){sum += 0;}
			else {sum += 4.*y;}
		}
		else /*even terms*/
		{
			if (y != y){sum += 0;}
			else {sum += 2.*y;}
		}
	}
	
	/*evaluating the function at the end points*/
	fa = (*func)(a,z);
	fb = (*func)(b,z);
	
	sum = (sum + fa + fb) * (h/3.);
	
	return(sum);
}

/**********************************************************************************/
/**********************************************************************************/
