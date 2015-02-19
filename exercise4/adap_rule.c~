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
adap_rule(int npts, double a, double b, double (* func) (double));

/************************************************************************/

double
adap_rule(int npts, double a, double b, double (* func) (double))
{

	double eps;
	double ans_trap;
	double ans_trap_test_1, ans_trap_test_2;
	double sum;
	double c;

	double start, end;

	eps = 1e-08;

	start = a;
	end = b;

	sum = 0;
	ans_trap = 0;
		end = b;
		
		if (eps > 1e-14)
		{
			c = (end-start)/2.;
			ans_trap = trapezoidal_rule(2, start, end, &my_func_xsq);
			ans_trap_test_1 = trapezoidal_rule(2, start, c, &my_func_xsq);
			ans_trap_test_2 = trapezoidal_rule(2, c, end, &my_func_xsq);
			eps = ans_trap_test_1 + ans_trap_test_2 - ans_trap;
			end = c;
		}

		else if (eps < 1e-14)
		{
			sum += ans_trap;
			start = 2*end+start;
		}
		
	return(sum);
}

/**********************************************************************************/
/**********************************************************************************/
