/*FILE: adaptive_rule.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 19 Feb 2015

Version: Adapted

Revision-History:

Comments:
19 Feb 2015: This calculates integrals using the adaptive rule and can be called from other codes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integ_test.h"

/**************** Begin Function Prototype ******************************/
double
adaptive_rule(int npts, double a, double b, double (* func) (double));

/************************************************************************/

double
adaptive_rule(int npts, double a, double b, double (* func) (double))
{

	int i;
	double eps;
	double ans_trap;
	double ans_trap_test;
	double sum;

	eps = 1e-08;

	while (eps > 1e-15)
	{
		ans_trap = trapezoidal_rule(i, a, b, &my_func_xsq);
		ans_trap_test = trapezoidal_rule(2*i, a, b, &my_func_xsq);
		eps = ans_trap_test - ans_trap;
		i = 2*i;
	}
	
	sum = trapezoidal_rule(i/2, a, b, &my_func_xsq);
	
	return(sum);
}

/**********************************************************************************/
/**********************************************************************************/
