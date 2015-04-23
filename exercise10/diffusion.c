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
	int i,j,t;
	int N;
	double a;
	double x,y,temp;

	gsl_matrix *B;
	gsl_matrix *I;
	gsl_vector *T0;
	gsl_vector *Ti;

	a = 1./2;
	N = 10;
	B = gsl_matrix_alloc(N,N);
	I = gsl_matrix_alloc(N,N);
	T0 = gsl_vector_alloc(N);
	Ti = gsl_vector_alloc(N);

	for (i=0;i<N;i++)
	{
//		initialize the matrix T0 - initial time
		if (i==0){gsl_vector_set(T0,i,0.);}
		else if (i==N-1) {gsl_vector_set(T0,i,0.);}
		else {gsl_vector_set(T0,i,100.);}
//		initialize the matrix Ti - next time step
		if (i==0){gsl_vector_set(T0,i,0.);}
		else if (i==N-1) {gsl_vector_set(T0,i,0.);}
		else {gsl_vector_set(T0,i,100.);}
//		initialize the matrices B - implicit operator and I
		for (j=0;j<N;j++)
		{
			if (i==j)
			{
				gsl_matrix_set(B,i,j,1.+2*a);
				gsl_matrix_set(I,i,j,1.);
			}
			else if (abs(i-j)==1) {gsl_matrix_set(B,i,j,-a);}
			else
			{
				gsl_matrix_set(B,i,j,0.);
				gsl_matrix_set(I,i,j,0.);
			}
		}
	}

//	calculate inverse of B - implicit operator
	gsl_matrix *Binv = gsl_matrix_alloc (N,N);

	int s;

	gsl_permutation * p = gsl_permutation_alloc (N);
	gsl_linalg_LU_decomp (B, p, &s);
	gsl_linalg_LU_invert (B, p, Binv);
	printf ("x = \n");
//	gsl_matrix_fprintf (stdout, Binv, "%g");


//	matrix product of the operator with T0 to give Ti
//	gsl_blas_dsymv(CBLAS_TRANSPOSE_t CblasNoTrans, 1.0, Binv,T0,0.0,Ti);

	gsl_vector_fprintf (stdout, Ti, "%g");

	for (t=0;t<3;t++)
	{
		for (i=0;i<N;i++)
		{
			temp = 0;
			for (j=0;j<N;j++)
			{
				x = gsl_matrix_get(Binv,i,j);
				y = gsl_vector_get(T0,j);
				temp+= x*y ;
			}
			gsl_vector_set(Ti,i,temp);
		}
	
		gsl_vector_fprintf (stdout, Ti, "%g");
		printf("\n");
		for (i=0;i<N;i++)
		{
			gsl_vector_set(T0,i,gsl_vector_get(Ti,i));
		}
	}
	return (0);
}
