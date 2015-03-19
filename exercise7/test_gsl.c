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
	
	FILE *out_ptr;
	out_ptr = fopen("test_gsl_4000.dat","w");
		
	int N=4000;
	gsl_matrix *gsl_mat;

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
		/*using gsl matrices*/
	gsl_mat = gsl_matrix_alloc(N, N);
	
	for(i = 0; i < N; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			if(i == j)
			{
				gsl_matrix_set(gsl_mat, i, j, 2.);
			}
			else if(i-j==-1)
			{
				gsl_matrix_set(gsl_mat, i, j, -1.);
			}
			else if(i-j==1)
			{
				gsl_matrix_set(gsl_mat, i, j, -1.);
			}
			else
			{
				gsl_matrix_set(gsl_mat, i, j, 0.);
			}
			
//			printf("i:%d j:%d M_ij:%f \n", i, j, gsl_matrix_get(gsl_mat, i, j));
		}
	}
	
	/*set matrix B*/

	for (i=0;i<N;i++)
	{
		xx = a+i*h;
		B_data[i] = h*h*fn(xx);
		U_data[i] = un(xx);
	}
/*
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf("%lf",gsl_matrix_get(gsl_mat, i, j));
		}
		printf(" %lf, %lf \n", B_data[i], U_data[i]);
	}

	printf("%lf \n", h);
	*/
	start = clock();
	
//	gsl_matrix_view m = gsl_matrix_view_array(gsl_mat, N, N);
	gsl_vector_view b = gsl_vector_view_array(B_data, N);
	gsl_vector *x = gsl_vector_alloc (N);

	int s;

	gsl_permutation * p = gsl_permutation_alloc (N);
	gsl_linalg_LU_decomp (gsl_mat, p, &s);
	gsl_linalg_LU_solve (gsl_mat, p, &b.vector, x);
/*	printf ("x = \n");
	gsl_vector_fprintf (stdout, x, "%g"); */
	
	stop = clock();
	
	for (i=0;i<N;i++)
	{
//		printf("%d",i);
		fprintf(out_ptr,"%lf %lf %lf \n", a+i*h, U_data[i],gsl_vector_get(x,i));
//		printf("\n");
	}

	gsl_permutation_free (p);
	gsl_vector_free (x);
	
	gsl_matrix_free(gsl_mat);
	
	fclose(out_ptr);

	printf("%d, %e \n", N, (double)(stop-start)/(CLOCKS_PER_SEC));

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
