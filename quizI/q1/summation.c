#include <stdio.h>
#include <math.h>

int
main(void)
{
	int i;
	int N;
	float s1;
	float s2;
	float s3;
	float s2o;
	float s2e;

	FILE *in_ptr_1;
	FILE *in_ptr_2;
	
	in_ptr_1 = fopen("summation_error_1.dat","w");
	in_ptr_2 = fopen("summation_error_2.dat","w");
	
	for (N=1;N<200000;N=2*N)
	{
		s1 = 0.;
		s2 = 0.;
		s3 = 0.;
		s2e = 0.;
		s2o = 0.;
		
		for (i=0;i<2*N+1;i++)
		{
			s1 += pow(-1,i)*i/(i+1.);
		}

		for (i=1;i<N+1;i++)
		{
			s2e += 2*i/(2*i+1.);
			s2o += (2*i-1.)/(2*i);
		}
		s2 = s2e-s2o;
	
		for (i=1;i<N+1;i++)
		{
			s3 += 1./(2*i*(2*i+1.));
		}
		
		fprintf(in_ptr_1, "%d \t %f \n", N, 2.*fabsf((s1-s3)/(s1+s3)));
		fprintf(in_ptr_2, "%d \t %f \n", N, 2.*fabsf((s2-s3)/(s2+s3)));
/*		printf("%d,%f \n", N, 2.*abs((s1-s3)/(s1+s3)));
		printf("%d,%f \n", N, 2.*abs((s2-s3)/(s2+s3)));
		printf("N = %d, s1=%f,s2=%f,s3=%f \n",N,s1,s2,s3);
		printf("N = %d, e13=%f,e23=%f \n",N,2.*fabsf((s1-s3)/(s1+s3)),2.*fabsf((s2-s3)/(s2+s3)));
		printf("N = %d, e13=%f,e23=%f \n",N,2.*(s1-s3)/(s1+s3),2.*(s2-s3)/(s2+s3));*/
	}

	fclose(in_ptr_1);
	fclose(in_ptr_2);
	
	return (0);
}
