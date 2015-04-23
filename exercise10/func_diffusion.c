#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <gsl/gsl_blas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>

void implicit_update(int, double, gsl_vector *, gsl_vector *);
//void crank_nicholson_update(int, double, double, double *, double *);

int
main(void)
{
	int i,j,t;
	double alpha,theta;
	int N;

	alpha = 1./2;
	N = 10;

	gsl_vector *T0;
	gsl_vector *Ti;
	T0 = gsl_vector_alloc(N);
	Ti = gsl_vector_alloc(N);

	printf ("\n");
//	gsl_matrix_fprintf (stdout, Binv, "%g");


//	matrix product of the operator with T0 to give Ti
//	gsl_blas_dsymv(CBLAS_TRANSPOSE_t CblasNoTrans, 1.0, Binv,T0,0.0,Ti);

	gsl_vector_fprintf (stdout, Ti, "%g");

	for (t=0;t<3;t++)
	{
		implicit_update(N, alpha,T0,Ti);
		gsl_vector_fprintf (stdout, Ti, "%g");
		printf("\n");
		for (i=0;i<N;i++)
		{
			gsl_vector_set(T0,i,gsl_vector_get(Ti,i));
		}
	}
	return (0);
}

void implicit_update(int N, double alpha, gsl_vector *T0, gsl_vector *Ti)
{
	int i,j;
	int s;
	double x,y,temp;

	gsl_permutation *p;	
	gsl_matrix *B;
	gsl_matrix *Binv;

	B = gsl_matrix_alloc(N,N);
	Binv = gsl_matric_alloc(N,N);
	p = gsl_permutation_alloc(N);

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
			if (i==j){gsl_matrix_set(B,i,j,1.+2*alpha);}
			else if (abs(i-j)==1) {gsl_matrix_set(B,i,j,-alpha);}
			else{gsl_matrix_set(B,i,j,0.);}
		}
	}

//	calculate inverse of B - implicit operator
	gsl_linalg_LU_decomp (B, p, &s);
	gsl_linalg_LU_invert (B, p, Binv);

//	updating the temperature in Ti using T0
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
	return;
}

//void crank_nicholson_update()
//{
//	return;
//}
