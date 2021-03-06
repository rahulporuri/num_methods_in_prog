#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
#include <gsl/gsl_linalg.h>

double fn(double x);
double un(double x);

int
main(void)
{
	clock_t start, stop; 
	
	FILE *out_ptr;
	out_ptr = fopen("test_1000.dat","w");
		
	int N=1000;
	double A_data[N][N];
	double B_data[N];
	double U_data[N];

	int i, j;
	int a = 0;
	int bb = 1;

	double xx;
	double h;
	h=(bb-a)/(N+1.);
	xx = 0;
		
	/*set matrix A*/

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (i==j)
			{
				A_data[i][j] = 2;
			}
			else if (i-j==-1)
			{
				A_data[i][j] = -1;
			}
			else if (i-j==1)
			{
				A_data[i][j] = -1;
			}
			else
			{
				A_data[i][j] = 0; 
			}
		}
	}

	/*set matrix B*/

	for (i=0;i<N;i++)
	{
		xx = a+i*h;
		B_data[i] = h*h*fn(xx);
		U_data[i] = un(xx);
	}

/*	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf("%lf",A_data[i][j]);
		}
		printf(" %lf, %lf \n", B_data[i], U_data[i]);
	}

	printf("%lf \n", h); */
	
	start = clock();
	
	gsl_matrix_view m = gsl_matrix_view_array (A_data, N, N);
	gsl_vector_view b = gsl_vector_view_array (B_data, N);
	gsl_vector *x = gsl_vector_alloc (N);

	int s;

	gsl_permutation * p = gsl_permutation_alloc (N);
	gsl_linalg_LU_decomp (&m.matrix, p, &s);
	gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);
/*	printf ("x = \n");
	gsl_vector_fprintf (stdout, x, "%g"); */
	
	stop = clock();
	
	for (i=0;i<N;i++)
	{
//		printf("%d",i);
		fprintf(out_ptr,"%lf %lf %lf %lf\n", a+i*h, U_data[i],gsl_vector_get(x,i), fabs(U_data[i]-gsl_vector_get(x,i)));
//		printf("\n");
	}

	gsl_permutation_free (p);
	gsl_vector_free (x);
	fclose(out_ptr);

	printf("%e \n", (double)(stop-start)/(CLOCKS_PER_SEC));

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
