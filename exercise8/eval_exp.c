#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial(int);
double sum_series(double, int);
double sum_stepwise(double, int);

int
main (void)
{
	double x;
	double N;

	double sum, y;

	double fact;
	double est_series;
	double est_stepwise;
	double actual;

//	x = .1;
	for (x=0.1;x<101;x=x*10)
	{
		printf("when x =%lf \n",x);
		actual = exp(-x);
		for (N=10;N<1000;N=2*N)
		{
			est_series = sum_series(x,N);
			est_stepwise = sum_stepwise(x,N);
			printf("error =%lf for N= %lf \n", est_series -actual, N);
			printf("error =%lf for N= %lf \n", est_stepwise -actual, N);
	//		printf("%lf \n", exp(-x));
		}
		printf("actual value= %lf \n",actual);
	}
	return(0);
}

double factorial(int N)
{
	double prod;
	prod = 1;

	while (N>0)
	{
		prod = prod*N;
		N = N-1;
	}

	return prod;
}

double sum_series(double x, int N)
{
	double i;
	double sum;
	sum = 1;

	for (i=1;i<N;i++)
	{
		sum += pow(x,i)*pow(-1,i)/factorial(i);
	}

	return sum;
}

double sum_stepwise(double x, int N)
{
	double i;
	double y;
	double sum;

	sum = 1;
	y = -x;

	for (i=1;i<N;i++)
	{
		sum += y;
		y = -y*x/(i+1);
	}
	return sum;
}

/*	for (i=0;i<10;i++)
	{
		fact = factorial(i);
		printf("%lf \n",pow(x,i)*pow(-1,i)/fact);
	}

	for (N=10;N<1000;N=2*N)
	{
		sum = 1;
		for (i=1;i<N;i++)
		{
			fact = factorial(i);
			sum += pow(x,i)*pow(-1,i)/fact;
		}
		printf("%lf %lf\n",sum, N);
		printf("%lf %lf \n", sum_series(x,N),N);
	}

	for (N=10;N<1000;N=2*N)
	{
		sum = 1;
		y = x;
		for (i=1;i<N;i++)
		{
			sum = sum + y;
			y = - y*x/(i+1);
		}
		printf("%lf %lf \n", sum, N);
		printf("%lf %lf \n", sum_stepwise(x,N),N);
	}

	printf("%lf \n", exp(-x));
	return (0);

	for (i=1;i<10;i++)
	{
		temp = factorial(i);
		printf("%lf \n",temp);
	}

	sum = 1;
	y = -x;                                         
	for (N=1;N<10;N++)
	{
		sum += y;
		y = -y*x/(N+1);
		printf("sum = %lf xi = %lf \n", sum, y);
	}
*/
