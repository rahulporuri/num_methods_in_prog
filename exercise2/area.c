/*FILE: area.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Date: 22 Dec 2011

Version: Original

Revision-History:
	28 JAN 2012: The subroutine area_calc is now a separate C file and the 
	value of r is hardcoded!
	
	14 Feb 2013: The code calculates area of various geometries declared in the function func and calls the subroutine area_calc.c

Comments:
22 Dec 2011: This code calculates the area of a circle. The input radius is obtained 
as a user input.

NOTES:
Compile using gcc -o area area.c This generates an executable called area. Run this 
executable using ./area at the prompt. You could also use a makefile.

Todo:
1. Hard code radius instead of an interactive input
2. Change the code such that r is now a grid starting from some r_min to r_max for 
example 0. to 5. with a step size of 0.1. Generate the r grid. Using a for loop, loop 
through all values of r and calculate the area. Print the output to screen.
3. Now declare a file pointer, open a file called area.dat and write the output to 
file.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/****************************** Function Prototype *******************************/
double
area_calc(int opt, double r, double l, double b, double h, double (*func)(int, double, double, double, double));

double
my_func(int opt, double r, double l, double b, double h);

/************************************************************************************/
int 
main(int argc, char *argv[])
{
	int opt;												/*flag used to calculate various geometries*/
	
	double r;												/*radius of the circle*/
	double area;										/*stores the value of area*/
	double l, b;										/*variable for length and breadth*/
	double h;												/*height*/
	
	char line[256];									/*line buffer used to store command line input*/
	/*initializations*/
	
	if (argc == 1)
	{
		printf("Please enter an option after the executable, which is 1 for circle, 2 for square, 3 for rectangle and 4 for triangle \n");
	}

	else
	{
		opt = atoi(argv[1]);           /*converts the command line string to an integer*/
	
		/*Using the command line input for opt to obtain interactive data from the user*/
		if(opt == 1) /*circle*/
		{
			printf("Enter the radius of the circle:\n");
		
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%lf", &r);
		}
		else if(opt == 2) /*square*/
		{
			printf("Enter the length of a side of the square:\n");
		
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%lf", &l);
		}
		else if(opt == 3) /*rectangle*/
		{
			printf("Enter the length of the rectangle: \n");
		
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%lf", &l);
		
			printf("Enter the breadth of the rectangle: \n");
		
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%lf", &b);
		}
		else if(opt == 4) /*triangle*/		
		{
			printf("Enter the height of the triangle: \n");
		
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%lf", &h);
		
			printf("Enter the base length of the triangle: \n");
		
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%lf", &b);
		}
		else /*to check for incorrect option*/
		{
			printf("Please enter the correct option, which is 1 for circle, 2 for square, 3 for rectangle and 4 for triangle \n");
		}	
		
		/*calculate area*/
		area = area_calc(opt, r, l, b, h, &my_func);
	
		/*print output*/
		if(opt == 1)
		{
			printf("area of circle: %f \n", area);
		}
		else if(opt == 2)	
		{
			printf("area of square:%f \n", area);
		}
		else if(opt == 3)
		{
			printf("area of rectangle:%f \n", area);
		}
		else if(opt == 4)
		{
			printf("area of triangle: %f \n", area);
		}
	}	
	return(0);
}
/******************************************************************/
double
my_func(int opt, double r, double l, double b, double h)
{
	const double pi = 4. * atan(1.);
	
	double area;
	
	if(opt == 1) /*circle*/
	{
		area = pi * r * r;
	}
	else if(opt == 2) /*square*/
	{
		area = l * l;
	}
	else if(opt == 3) /*rectangle*/
	{
		area = l * b;
	}
	else if(opt == 4) /*triangle*/
	{
		area = 1./2. * b * h;
	}
	
	return(area);
}			
			
/********************************************************************/
/********************************************************************/
