#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exact(double alpha, double t);
double rk2_step(double alpha, double y0, double h);

int
main(void)
{
	FILE *in_ptr;
	
	int N;
	int i;
	double t, t_min, t_max;
	double h;
	
	double alpha;
	double y0, y1, yexact;
	double rel_err;
	
	in_ptr = fopen("stability_rk2.dat","w");
	
	N = 1000;
	t_min = 0.0;
	t_max = 1.0;
	
	y0 = 1.0;
	t = 0;
	
	h = (t_max-t_min)/(N-1.);

	/*for alpha randing from 1 to <2/h */

	for(i=1;i<2*(N-1);i +=50)
	{
		alpha = i/((N-1.)*h);
		/*rk2 estimate*/
		y1 = y0 + rk2_step(alpha, y0, h);
		/*exact value of function*/
		yexact = exact(alpha,t+h);
		rel_err = fabs((y1-yexact)/(y1+yexact));
		printf("alpha : %lf, rel_err : %lf \n", alpha, rel_err);
		fprintf(in_ptr,"%lf %lf \n", i/(N-1.), rel_err);
	}
	
	return (0);
}

/*returns exact value for y1 or y(h)*/
double exact(double alpha, double t)
{
	return (exp(-alpha*t));
}

/* calculates the step size using rk2*/
double rk2_step(double alpha, double y0, double h)
{
	double k1, k2;

	k1 = -alpha*y0;
	k2 = -alpha*(y0+k1*h);
	return (k1+k2)*h/2.;
}
