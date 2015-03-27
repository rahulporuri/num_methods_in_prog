#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>

double fn(double x);
double un(double x);

int
main(void)
{
	clock_t start, stop; 
	
//	FILE *out_ptr;
//	out_ptr = fopen("test_gsl_100000.dat","w");
		
	int N=500000;

	gsl_vector *diag;
	gsl_vector *e;
	gsl_vector *u;
	gsl_vector *b;

//	double B_data[N];
//	double U_data[N];

	int i, j;
	int a = 0;
	int bb = 1;

	double xx;
	double h;
	h=(bb-a)/(N+1.);
	xx = 0;

	/*set matrices diag, e- off diag, b and u*/
	/*using gsl vectors*/
	diag = gsl_vector_alloc(N);
	e = gsl_vector_alloc(N-1);
	u = gsl_vector_alloc(N);
	b = gsl_vector_alloc(N);
	
	for(i = 0; i < N; i ++)
	{
		xx = a+i*h;
		gsl_vector_set(b, i, h*h*fn(xx));
		gsl_vector_set(u, i, un(xx));

		gsl_vector_set(diag, i, 2.);
	}

	for(i = 0; i < N-1; i ++)
	{
		gsl_vector_set(e, i, -1.);
	}

/*	for (i=0; i<N; i++)
	{
		printf("%lf %lf %lf \n", gsl_vector_get(diag, i), gsl_vector_get(e, i), gsl_vector_get(u, i));
	}
*/
	printf("step size = %lf \n", h);
	
	gsl_vector *x = gsl_vector_alloc (N);


	start = clock();
	for (i=0;i<100;i++)
	{
		gsl_linalg_solve_symm_tridiag(diag, e, b, x);
	}
	printf("number of times run = %d \n",i);
//	printf ("x = \n");
//	gsl_vector_fprintf (stdout, x, "%g");
	
	stop = clock();
	
//	for (i=0;i<N;i++)
//	{
//		printf("%d",i);
//		fprintf(out_ptr,"%lf %lf %lf \n", a+i*h, gsl_vector_get(x,i), gsl_vector_get(u,i));
//		printf("\n");
//	}

	printf("for N = %d, time taken is %e \n", N, (double)(stop-start)/(CLOCKS_PER_SEC));

	gsl_vector_free (x);	
	gsl_vector_free (diag);
	gsl_vector_free (e);
	gsl_vector_free (u);

//	fclose(out_ptr);
	return (0);
}

double fn(double x)
{
	return ((3*x+x*x)*exp(x));
}

double un(double x)
{
	return (x*(1-x)*exp(x));
}
