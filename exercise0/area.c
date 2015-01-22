/*FILE: area.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 22 Jan 2015

Version: Adapted from original

Revision-History:

Comments:
22 Jan 2015 : adapted from the original code, solutions to the various to-do problems
mentioned in the code have been mentioned beneath the original code.

NOTES:
Compile using gcc -o area area.c This generates an executable called area. Run this 
executable using ./area at the prompt. You could also use a makefile.

Todo:
done - 1. Hard code radius instead of an interactive input
done - 2. Change the code such that r is now a grid starting from some r_min to r_max for 
example 0. to 5. with a step size of 0.1. Generate the r grid. Using a for loop, loop 
through all values of r and calculate the area. Print the output to screen.
done - 3. Now declare a file pointer, open a file called area.dat and write the output to 
file.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**Original code**/
int 
main(void)
{
	const double pi = 4. * atan(1.);				/*defining pi*/
	double r;							/*radius of the circle*/
	double area;							/*stores the value of area*/

	/*getting input*/
	printf("Enter radius of the circle:");
	scanf("%lf", &r);

	/*calculate area*/
	area = pi * r * r;
	
	/*print output*/
	printf("area of circle is:%f \n", area);

	return(0);
}

/**value_of_r_is_hard_coded_to_1**/
int 
main(void)
{
	const double pi = 4. * atan(1.);				/*defining pi*/
	double r;							/*radius of the circle*/
	double area;							/*stores the value of area*/

	r = 1;

	/*calculate area*/
	area = pi * r * r;
	
	/*print output*/
	printf("area of circle is:%f \n", area);

	return(0);
}

/**values_of_area_for_various_values_of_radius_are_measured_ver_1_done_iteratively**/
int 
main(void)
{
	const double pi = 4. * atan(1.);				/*defining pi*/
	double r;							/*radius of the circle*/
	double area;							/*stores the value of area*/
	int i;

	for (i=0;i<51;i++)
	{
		r = 0.1*i;
		area = pi * r * r;
		printf("for radius %f, the value of area is %f \n", r, area);
	}
	
	return(0);
}

/**values_of_area_for_various_values_of_radius_are_measured_ver_1_done_using_arrays**/
int 
main(void)
{
	const double pi = 4. * atan(1.);				/*defining pi*/
	double r[51];							/*radius of the circle*/
	double area[51];						/*stores the value of area*/
	int i;

	for (i=0; i<51; i++)
	{
		r[i] = 0.1*i;
	}

	for (i=0; i<51; i++)
	{
		area[i] = pi * r[i] * r[i];
	}

	for (i=0; i<51; i++)
	{
		printf("when the radius of the circle is %f, the area of the circle is %f", r[i], area[i]);
	}

	return(0);
}

/**values_of_area_for_various_values_of_radius_are_measured_saved_in_a_file**/
int 
main(void)
{
	const double pi = 4. * atan(1.);				/*defining pi*/
	double r;							/*radius of the circle*/
	double area;							/*stores the value of area*/
	int i;
	FILE *fp;

	/*getting input*/
	printf("Enter radius of the circle:");
	scanf("%lf", &r);

	fp = fopen("area_output","w");

	for (i=0;i<51;i++)
	{
		r = 0.1*i;
		area = pi * r * r;
		fprintf(fp,"for radius %f, area is %f", r, area);
	}
	
	fclose(fp);
	return(0);
}
