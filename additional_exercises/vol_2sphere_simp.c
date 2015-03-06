#include <stdio.h>
#include <math.h>

double my_func(double, double);
double simpson_rule(int, double, double, double, double (* func)(double, double));

int
main(void)
{
	int i, N;
	double x0;
	double hx,hz;
	double x,z,y;
	double ans_simp;

	FILE *in_ptr;
	in_ptr = fopen("vol_sphere.dat","w");
	
	for (N=3;N<200;N=N+2)
	{
		ans_simp = 0;
		hz = 1./(N-1.);
		for (z=0.; z<1.; z+=hz)
		{
			x0 = (*my_func)(0.,z);
	//		printf("x0 = %lf, z0 = %lf\n",x0, z);
			ans_simp += simpson_rule(N,0,x0,z,&my_func);
//			printf("function value = %lf at z = %lf\n", ans_simp, z);
		}
		ans_simp = ans_simp*hz;
		printf("final ans = %lf for number of points = %d\n", ans_simp*6., N);
	}
	fclose(in_ptr);
	return (0);
}

double
my_func(double x, double z)
{
	return (pow(1-pow(x,2)-pow(z,2),1./2));
}
