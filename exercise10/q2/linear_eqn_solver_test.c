/*FILE: matrix_diagonalizer_test.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Version: Original

Date: 28 Feb 2012

Comments: 
28 Feb 2012: This code tests the matrix diagonalizer codes.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

/********************** Function Prototype *********************************/
int
linear_eqn_solver_lapack(int, double *, double *, double *, double *);

double fn(double);
double un(double);
/****************************************************************************/

int
main(void)
{
	clock_t start, stop;

	FILE *out_ptr;

	int i;										/*counters*/
	int N0;										/*max dimension*/

	int a,b;
	double h, x;

	double *X;
	double *D;
	double *E;
	double *U;
	double *B;
	
/*	gsl_vector *X_ptr;									*stores the unknown - solution of the linear eqn*
	gsl_vector *B_ptr;									*RHS of the system of linear Eqns*
	gsl_matrix *M_ptr;									*matrix*
	gsl_vector *U_ptr;*/
	
	/*initialization*/
	x = 0;
/*	N0 = 100;*/
	a = 0;
	b = 1;

	out_ptr = fopen("lapack.dat","w");

	for (N0=5000;N0<10000;N0=2*N0)
	{
		h = (b-a)/(N0+1.);
	
		X = (double *) malloc(N0 * sizeof(double));
		D = (double *) malloc(N0 * sizeof(double));
		E = (double *) malloc((N0-1) * sizeof(double));
		U = (double *) malloc(N0 * sizeof(double));
		B = (double *) malloc(N0 * sizeof(double));
	
	/*allocating various matrices and vectors*/
	/*	X_ptr = gsl_vector_calloc(N_max);
	B_ptr = gsl_vector_calloc(N_max);
	M_ptr = gsl_matrix_calloc(N_max, N_max);
	U_ptr = gsl_vector_calloc(N_max); */
	
		/*loading the matrix*/
		for (i=0;i<N0;i++)
		{
			D[i] = 2;
			if (i<N0-1) {E[i] = -1;}
			U[i] = un(x);
			B[i] = h*h*fn(x);
			x += h;
		}
	
		printf("done loading vectors and matrices!");
	
		start = clock();	
		/*calling linear algebra solver code*/
		linear_eqn_solver_lapack(N0, D, E, B, X);
		stop = clock();
		
		printf("\nResults from lapack\n");
		
		/*print result to screen*/
		for(i = 0; i < N0; i ++)
		{
			fprintf(out_ptr, "%d, %f \n", i, X[i]);
		}
			
		printf("for N = %d, time taken is %e \n", N0, (double)(stop-start)/(CLOCKS_PER_SEC));
	
		/*free various matrices
		gsl_vector_free(X_ptr);
		gsl_vector_free(B_ptr);
		gsl_matrix_free(M_ptr);*/
	}		
	return(0);
}
	
double fn(double x)
{
	return (3*x+x*x)*exp(x);
}
double un(double x)
{
	return x*(1-x)*exp(x);
}
