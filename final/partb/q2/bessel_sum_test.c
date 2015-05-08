/*FILE: bessel_sum_test.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Date: 29 Jan 2012

Version: Original

Revision-History:

Comments:
29 Jan 2012: This code compares the two ways of summing bessel functions an up series and 
a down series.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_sf.h>
#define N_l 30

/******************** Function Prototype *************************************/

/*****************************************************************************/

int 
main(void)
{
	FILE *out_ptr;							/*file pointer to the file that stores the rel-err in the 
	up and down bessel series as a function of l*/
	
	int i;											/*counter*/
	int l;											/*value of l*/
	int l_min, l_max;						/*min and max value of l*/
	
	double x;										/*value of x where the bessel fn is calculated*/
	double bessel_gsl;					/*resulf from gsl library*/
	double err_up, err_down;		/*relative errors in the up and down series with respect to 
	gsl functions*/
	
	double jl_up[N_l];					/*stores the value of bessel for a given l using up series*/
	double jl_down[N_l];				/*stores the value of bessel for a given l using down 
	series*/
	
	char filename[256];					/*character array that stores the name of the file*/
	
	/*intializations*/
	l_min = 0;
	l_max = 25;
	
	x = 10.0;
	
	/*opening output file*/
	/*Step 1: Assigning name to the file*/
	sprintf(filename, "bessel_sum_test_up_down_compare_x_%.2f.dat", x);
	
	/*Step 2: opening the file with the name stored in filename array*/
	out_ptr = fopen(filename, "w");
	
	/*Putting some comments into file*/
	fprintf(out_ptr, "#contains rel-err of up and down bessel series w.r.t. gsl functions \n");
	fprintf(out_ptr, "#x value where the function is evaluated: %f \n", x);
	fprintf(out_ptr, "#l \t err_up \t err_down \n");
	
	/*up series*/
	printf("calculating up series \n");
	
	/*these are the initial values*/
	jl_up[0] = gsl_sf_bessel_jl(0, x);
		
	jl_up[1] = gsl_sf_bessel_jl(1, x);
		

	/*determing other bessels using recursion relations*/
	for(i = l_min + 1; i < l_max; i ++)
	{
		/*setting l value*/
		l = i;
		
		printf("bessel fn calculated: l=%d using %d and %d values\n", l + 1, l, l-1);
		
		/*using recursion for the other bessels*/
		jl_up[l+1] = ((2. * l + 1.)/x) * jl_up[l] - jl_up[l-1];
		
		bessel_gsl = gsl_sf_bessel_jl(l+1, x);
		
		printf("up series: gsl:%f \t calc:%f \n", bessel_gsl, jl_up[l+1]);
	}
	
	/*down series*/
	printf("calculating down series \n");
	
	/*these are the initial values*/
	jl_down[l_max] = gsl_sf_bessel_jl(l_max, x);
	
	jl_down[l_max - 1] = gsl_sf_bessel_jl(l_max - 1, x);
	
	/*determing bessels using down series*/
	for(i = l_max - 1; i > l_min; i --)
	{
		l = i;
		
		printf("bessel fn calculated: l=%d using %d and %d values\n", l - 1, l, l+1);
		
		jl_down[l - 1] = ((2. * l + 1.)/x) * jl_down[l] - jl_down[l+1];
		
		bessel_gsl = gsl_sf_bessel_jl(l-1, x);
		
		printf("down series: gsl:%f \t calc:%f \n", bessel_gsl, jl_down[l-1]);
	}
	
	/*writing output to file*/
	for(i = l_min; i <= l_max; i ++)
	{
		l = i;
		
		bessel_gsl = gsl_sf_bessel_jl(l, x);
		
		err_up = fabs((bessel_gsl - jl_up[i])/(bessel_gsl + jl_up[i]));
		
		err_down = fabs((bessel_gsl - jl_down[i])/(bessel_gsl + jl_down[i]));
		
		fprintf(out_ptr, "%d \t %e \t %e \n", l, err_up, err_down);
	}
	
	fclose(out_ptr);
	
	return(0);
}
