#include <stdio.h>
#include <math.h>

int
main(void)
{
	int i, N;
	double x0;
	double hx,hz;
	double x,z,y;
	double sum;

	FILE *in_ptr;
	in_ptr = fopen("vol_sphere.dat","w");
	
	for (N=3;N<1000;N=2*N)
	{
		hz = 1./(N-1.);
		for (z=0.; z<1.; z+=hz)
		{
			x0 = pow(1.-pow(z,2),1./2);
	//		printf("x0 = %lf, z0 = %lf\n",x0, z);
			hx= 2.*x0/(N-1);
			for (x=0; x< x0; x+=hx)
			{
				y = pow(1-pow(x,2)-pow(z,2),1./2);
				if (y != y)
				{
					sum += 0;
				}
				else
				{
					sum += y*hx;
				}
//				fprintf(in_ptr,"%lf \t %lf \t %lf \n", x ,y, sum);
			}
//			printf("%lf, %lf, %lf\n", sum, x0, z);
		}
		sum = sum*hz;
		printf("%lf %d\n", sum*6., N);
	}
	fclose(in_ptr);
	return (0);
}
