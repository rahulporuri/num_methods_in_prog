/*FILE: area_calc.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Date: 28 Jan 2012

Version: Modified

Revision-History: 
	14 Feb 2013
	
Comments:
28 Jan 2012: This code calculates the area of a circle and can be called from other codes.

14 Feb 2013: The code calls a function that calculates area of different geometries.
*/

#include <math.h>
#include <stdio.h>

/***************** Function Prototype **********************************/
double
area_calc(int opt, double r, double l, double b, double h, double (*func)(int, double, double, double, double));
/**********************************************************************/

double
area_calc(int opt, double r, double l, double b, double h, double (*func)(int, double, double, double, double))
{
	double area;				/*variable that stores the calculated area*/
	
	/*calling the function that calculates area for different geometries*/
	area = (*func)(opt, r, l, b, h);		
	
	return(area);
}
/********************************************************************/
/********************************************************************/
