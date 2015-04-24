/*FILE: linear_eqn_solver_lapack.c

Programer: Sunethra Ramanan suna@physics.iitm.ac.in

Date: 5 April 2012

Version: Original

Revision-History: 

Comments:
5 April 2012: This code sovles a given set of linear Eqns using gsl library routines.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>
#include "dptsv.h"
/********************** Function Prototype *********************************/

int
linear_eqn_solver_lapack(int, double *, double *, double *, double *);
/****************************************************************************/

int
linear_eqn_solver_lapack(int N0, double *D, double *E, double *B, double *X)
{
	int i;				/*counter*/

	int NRHS = 1;				/*no. of columns of B - this determines the number of systems of linear equations that need to be solved*/
/*	const int LDA = N0;*/			/*leading dimension of A*/
	const int LDB = N0;			/*size of array B*/
	
	int INFO;				/*INFO == 0 => success*/
	
/*	int *IPIV = (int *) malloc(N0 *sizeof(int));
	
	*allocating B*
	double *B = (double *) malloc(N0 * sizeof(double));
	
	*allocating D and E*
	double *D = (double *) malloc(N0 * sizeof(double));
	double *E = (double *) malloc((N0-1) * sizeof(double));

	*intializations*
	n = 0;

	for(i = 0; i < N0; i ++)
	{
		for(j = 0; j < N0; j ++)
		{
			if (i==j) {D[n] = gsl_matrix_get(M_ptr, j, i);}
			n++;
		}
	}


	n = 0;
	for(i = 0; i < N0-1; i ++)
	{
		for(j = 0; j < N0-1; j ++)
		{
			if (abs(i-j)==1) {E[n] = gsl_matrix_get(M_ptr, j, i);}
			n++;
		}
	}

	printf("extraction of D and E vector is done!");

	for(i =0; i < N0; i ++)
	{
		B[i] = gsl_vector_get(B_ptr, i);
	}*/
	
	printf("extraction of B vector is done!");
	printf("calling dptsv function");

	/*calling lapack*/
	dptsv_(&N0, &NRHS, D, E, B, &LDB, &INFO);	

	if(INFO == 0)
	{
		/*loading X*/
		for(i = 0; i < N0; i ++)
		{
			X[i] = B[i];
		}
	}
	else
	{
		printf("trouble with lapack \n");
		exit(1);
	}

	return(0);
}
