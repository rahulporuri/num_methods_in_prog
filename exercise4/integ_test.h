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
trapezoidal_rule(int npts, double a, double b, double (* func) (double));

double 
adaptive_rule(int npts, double a, double b, double (* func) (double));

double 
adap_rule(int npts, double a, double b, double (* func) (double));

double
simpson_rule(int npts, double a, double b, double (* func) (double, void *), void *params_ptr);

double
three_eights_rule(int npts, double a, double b, double (* func) (double, void *), void *params_ptr);

double
my_func_xsq(double x);
/***********************************************************************/
