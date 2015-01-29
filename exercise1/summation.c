/*
/*FILE: summation.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 22 Jan 2015

Version: Original

Revision-History:

Comments:
29 Jan 2015 : calculates the forward and reverse sum and saves them to a file

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double pow(double x, double y);
int
main(void)
{
	float i,j;
	float N;
	float forward_sum;
	float backward_sum;
	float temp;

	double e_rel;

	FILE *output_ptr;						/*file that contains the area output*/
	output_ptr = fopen("results_summation.dat","w");

	for(i=0;i<8;i++)
	{
		N = pow(10,i);
		printf("%f %f \n",i, N);

		forward_sum = 0;
		backward_sum = 0;

		for(j=1;j<N+1;j++)
		{
			forward_sum += 1/j;
		}

		for(j=0;j<N;j++)
		{
			backward_sum += 1/(N-j);
		}

/*		temp = forward_sum-backward_sum ;
		//printf("the difference between forward and backward difference is %f \n", forward_sum-backward_sum);
		printf("the difference between forward and backward difference is %f \n", temp); */
		
		e_rel = 2*(forward_sum-backward_sum)/(forward_sum+backward_sum);
		fprintf(output_ptr, "%lf, %lf \n", N, e_rel);
	}

	return (0);
}
