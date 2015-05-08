/*FILE: integ_test.h

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Version: Original

Date: 23 Jan 2012

Revision-History:

Comments:
23 Jan 2012: This is the header file for integ_test.c and contains programs specific declarations.
*/

/**************** Begin Function Prototype ******************************/
double
simpson_rule(int npts, double a, double b, double (* func) (double, void *), void *params_ptr);

double
my_func_xsq(double x, void *params_ptr);

double
my_func_xsq_2(double x, void *params_ptr);

struct func_struct
{
	double alpha0;    /*some parameter that the function depends on*/
  double beta0;     /*some other parameter that the function depends on*/
};
/***********************************************************************/
