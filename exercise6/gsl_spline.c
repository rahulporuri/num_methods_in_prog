#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

int
main (void)
{
	FILE *in_ptr;
	char line[256];
	int i;
	double xi, yi, x[9], y[9];

	in_ptr = fopen("sample_test.dat","r");
	for (i=0;i<9;i++)
	{
		fgets(line, sizeof(line), in_ptr);
		sscanf(line, "%lf	%lf", &x[i], &y[i]);
//		printf("a:%lf b:%lf\n",x[i],y[i]);
	}

	for (i=0;i<9;i++)
	{
//		printf("x[i] = %lf y[i] %lf \n",x[i],y[i]);
	}

//	printf ("#m=0,S=2\n");

	{
		gsl_interp_accel *acc = gsl_interp_accel_alloc ();
		gsl_spline *spline = gsl_spline_alloc (gsl_interp_cspline, 9);

		gsl_spline_init (spline, x, y, 9);

		for (xi = x[0]; xi < x[8]; xi += 5)
		{
			yi = gsl_spline_eval (spline, xi, acc);
			printf ("%g %g\n", xi, yi);
		}
		gsl_spline_free (spline);
		gsl_interp_accel_free (acc);
	}

	return 0;
}
