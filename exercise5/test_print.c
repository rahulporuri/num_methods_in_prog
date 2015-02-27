#include <stdio.h>
#include <gsl/gsl_sf.h>

int main()
{
	int l;
	double temp;
	double x;
	FILE *in_ptr;
	char filename[100];
	double gsl_sf_legendre_Pl (int l, double x);

	for (l=0;l<6;l++)
	{
		x = -1;
		sprintf(filename,"file_%d.dat",l);
		in_ptr = fopen(filename,"w");
		while (x < +1)
		{
			temp = gsl_sf_legendre_Pl(l,x);
			fprintf(in_ptr,"%lf %lf\n",x, temp);
			x += 0.01;
		}
		fclose(in_ptr);
	}

}

/*note that using
in_ptr = fopen("file"+l,"w");
compiled and ran without a hitch
only to produce extremely weird output!
*/
