#include <stdio.h>
#include <gsl/gsl_sf.h>

int main()
{
	int l;
	FILE *in_ptr;

	for (l=0;l<6;l++)
	{
		in_ptr = fopen("file_%d"+l,"w");
		fprintf(in_ptr,"Hello, World_%d\n",l);
		fclose(in_ptr);
	}

}

/*note that using
in_ptr = fopen("file"+l,"w");
compiled and ran without a hitch
only to produce extremely weird output!
*/
