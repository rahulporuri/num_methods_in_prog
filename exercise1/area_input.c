/*FILE: area_input.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 29 Jan 2015

Version: Adapted from Original

Revision-History:

Comments:

*/

#include <stdio.h>
#include <math.h>

/************************************************************************************/
int 
main(int argc, char *argv[])
{
	FILE *input_ptr;					/*file that contains the input radius*/
	FILE *output_ptr;						/*file that contains the area output*/
	
	const double pi = 4. * atan(1.);			/*defining pi*/
	double r_min, r_max, r;					/*radius of the circle*/
	double area;						/*stores the value of area*/
	int N;							/*number of data points*/
	N = 100;
	double inc;						/*increment counter*/
	int i;							/*counter variable*/
	char line[256];						/*line buffer to read from input file*/
	
	

	/*opening file*/
	input_ptr = fopen(argv[1], "r");
	output_ptr = fopen("output_area.dat","w");
	
	/*this line has the radius*/
	fgets(line, sizeof(line), input_ptr);
	
	/*assigning the value of r to the variable r*/
	sscanf(line, "%lf", &r_min);

	/*this line has the radius*/
	fgets(line, sizeof(line), input_ptr);
	
	/*assigning the value of r to the variable r*/
	sscanf(line, "%lf", &r_max);
	
	/*calculate area*/
/*	area = pi * r * r;
	printf("%f, %f \n", r_min, r_max); */

	inc = (r_max-r_min)/N;
	
	for(i=0;i<N+1;i++)
	{
		r = r_min + i*inc;
		area = pi * r * r;
		fprintf(output_ptr, "%f, %f \n", r, area);
	}

	/*print output
	printf("area of circle is:%f \n", area);*/

	/*close file*/
	fclose(input_ptr);
	fclose(output_ptr);
	
	return(0);
}
