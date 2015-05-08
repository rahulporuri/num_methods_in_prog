#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exact(double alpha, double t);

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
	
	in_ptr = fopen("stability_euler.dat","w");
	
	N = 1000;
	t_min = 0.0;
	t_max = 1.0;
	
	y0 = 1.0;
	t = 0;
	
	h = (t_max-t_min)/(N-1.);

	/*for alpha randing from 1 to <2/h */

	for(i=1;i<2*(N-1);i +=50)
	{
		alpha = i/((N-1)*h);
		/*euler estimate*/
		y1 = y0 + h*(-alpha*y0);
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
