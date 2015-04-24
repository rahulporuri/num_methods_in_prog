/*FILE: cn_diffusion_test.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: Apr 2015

Version:  Original

Revision-History:

Comments:

The following file implements the crank-nicholson scheme to solve the diffusion equation.
There are multiple ways to solve this problem, the popular approach being to solve
the equation AX=BY using the gsl linalg tridiagonal solver where
X is the vector containing temperature at a future time,
Y is the vector containing the temperature values at present.
Personally, I chose to calculate the inverse of the matrix A and multiply the matrix
with BY to get X. the gsl function invert was used to invert the matrix A.

************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <gsl/gsl_blas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>

int
main(void)
{
	FILE *out_ptr;

	int i,j,t;
	int N;
	int s;

	double alpha;
	double x,y,temp;

	gsl_matrix *A;
	gsl_matrix *Ainv;
	gsl_matrix *B;

	gsl_vector *T0;
	gsl_vector *Ti;

	gsl_permutation *p;

	out_ptr = fopen("pde_solvers_test_diffusion_test_cn.dat","w");

	alpha = 1./2;
	N = 50;

	A = gsl_matrix_alloc(N,N);
	Ainv = gsl_matrix_alloc(N,N);
	B = gsl_matrix_alloc(N,N);

	T0 = gsl_vector_alloc(N+2);
	Ti = gsl_vector_alloc(N+2);

	p = gsl_permutation_alloc(N);

	for (i=0;i<N+2;i++)
	{
//	initialize the matrices T0 and Ti - initial time and future time
		if (i==0)
		{
			gsl_vector_set(T0,i,0.);
			gsl_vector_set(Ti,i,0.);
		}
		else if (i==N+1)
		{
			gsl_vector_set(T0,i,0.);
			gsl_vector_set(Ti,i,0.);
		}
		else
		{
			gsl_vector_set(T0,i,100.);
			gsl_vector_set(Ti,i,100.);
		}
	}

	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (i==j)
			{
				gsl_matrix_set(A,i,j,2.+2*alpha);
				gsl_matrix_set(B,i,j,2.-2*alpha);
			}
			else if (abs(i-j)==1)
			{
				gsl_matrix_set(A,i,j,-alpha);
				gsl_matrix_set(B,i,j,alpha);
			}
			else
			{
				gsl_matrix_set(A,i,j,0.);
				gsl_matrix_set(B,i,j,0.);
			}
		}
	}

//	calculate inverse of B - implicit operator
	gsl_linalg_LU_decomp (A, p, &s);
	gsl_linalg_LU_invert (A, p, Ainv);
//	printf ("x = \n");
//	gsl_matrix_fprintf (stdout, Binv, "%g");

//	matrix product of the operator with T0 to give Ti
//	gsl_blas_dsymv(CBLAS_TRANSPOSE_t CblasNoTrans, 1.0, Binv,T0,0.0,Ti);

//	gsl_vector_fprintf (stdout, T0, "%g");

	for (t=0;t<1000;t++)
	{
//		save the array T0 at this time instant
		for (j=0;j<N+2;j++)
		{
			fprintf(out_ptr,"%d %d %e \n", t, j, gsl_vector_get(T0,j));
		}
		
		fprintf(out_ptr,"\n");		
		
		for (i=0;i<N;i++)
		{
			temp = 0;
			for (j=0;j<N;j++)
			{
				x = gsl_matrix_get(B,i,j);
				y = gsl_vector_get(T0,j+1);
				temp+= x*y ;
			}
			gsl_vector_set(Ti,i+1,temp);
		}

		for (i=0;i<N;i++)
		{
			temp = 0;
			for (j=0;j<N;j++)
			{
				x = gsl_matrix_get(Ainv,i,j);
				y = gsl_vector_get(Ti,j+1);
				temp+= x*y ;
			}
			gsl_vector_set(T0,i+1,temp);
		}                                            	
	}
	return (0);
}
