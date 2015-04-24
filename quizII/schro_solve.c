/*FILE: schro_solve.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: Apr 2015

Version: Original

Revision-History:

Comments:

The following code uses gsl matrices to solve an eigen value and eigen vector
problem. Specifically, we solve the schrodinger equation for a particle in a
box potential. We calculate the relative error in the least eigenvalue and we
plot the corresponding eigenvector.

We also estimate the time it takes for the function to run, which is dependent
on the size of the matrices we are working with.

In due process, we also write files iteratively, naming them as file_i where i
is a loop variable.

************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
	clock_t start, stop;				/*to keep track of time it takes for the code to run*/ 

	int i, j;
	int N;
	double h;

	char filename[100];				/*used to name the files iteratively*/

	FILE *eigen_values;
	FILE *eigen_vecs;

	gsl_matrix *gsl_mat;
	gsl_vector *eval;
	gsl_matrix *evec;
	gsl_eigen_symmv_workspace *w;

	eigen_values =fopen("eigen_values.dat","w");

	for(N=10;N<2000;N=2*N)
	{
		sprintf(filename,"schro_solve_%d.dat",N);
		eigen_vecs = fopen(filename,"w");

		h = 1./(N+1.);
		gsl_mat = gsl_matrix_alloc(N, N);
		eval = gsl_vector_alloc(N);
		evec = gsl_matrix_alloc (N, N);
		w = gsl_eigen_symmv_alloc (N)

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
			}
		}

		/*for(i = 0; i < N; i ++)
		{
			for(j = 0; j < N; j ++)
			{
				printf("i:%d j:%d M_ij:%f \n", i, j, gsl_matrix_get(gsl_mat, i, j));
			}
			printf("\n");
		}*/

		start = clock();

		if (N<100)
		{
			for (j=0;j<100;j++)
			{
				gsl_eigen_symmv (gsl_mat, eval, evec, w);			/*computes the eigen values and eigen vectors for the matric gsl_mat*/
				gsl_eigen_symmv_sort (eval, evec, GSL_EIGEN_SORT_ABS_ASC);	/*sorts them in ascending order of eigen values*/
			}
		}

		else
		{
			gsl_eigen_symmv (gsl_mat, eval, evec, w);
			gsl_eigen_symmv_sort (eval, evec, GSL_EIGEN_SORT_ABS_ASC);
		}

		stop = clock();

		for (i = 0; i < 1; i++)
		{
			double eval_i = gsl_vector_get (eval, i);
/*			gsl_vector_view evec_i = gsl_matrix_column (evec, i);*/
			printf ("relative error = %g %d\n", (eval_i/(h*h)-M_PI*M_PI)/(eval_i/(h*h)+M_PI*M_PI), N);
			fprintf (eigen_values, "%g %d \n", (eval_i/(h*h)-M_PI*M_PI)/(eval_i/(h*h)+M_PI*M_PI), N);	/*relative error of lowest eigen value*/
/*			printf ("eigenvector = \n");*/
/*			gsl_vector_fprintf (eigen_vecs, x, &evec_i.vector, "%g %g \n");*/
			for (i=1;i<N;i++)
			{
				fprintf(eigen_vecs,"%g %g \n", i*h, gsl_matrix_get(evec,0,i)/sqrt(h));			/*saving the corresponding eigen vector*/
			}
		}

		printf("%d, %e \n", N, (double)(stop-start)/(CLOCKS_PER_SEC));

		gsl_eigen_symmv_free (w);
		gsl_vector_free (eval);
		gsl_matrix_free (evec);
		gsl_matrix_free(gsl_mat);
	}
	return (0);
}
