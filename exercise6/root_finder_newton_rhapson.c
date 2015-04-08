/*
why is the code making me choose a,b values that are equidistant from the zero of the function?
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x);
float df(float x);

int
main(void)
{
	float x0,x;
	float temp;

	printf("please input an initial estimate of the zero of the function \n");
	scanf("%f", &x0);
	printf("starting with the estimate : %f \n",x0);

	if (f(x0) == 0)
	{
		printf("the function has a zero at %lf \n",x0);
	}

	else
	{
		x = x0-f(x0)/df(x0);
		if (f(x) == 0)
		{
			printf("the zero of the function is at %f \n",x);
		}
		else
		{
			x0 = x;
		}
	}

	printf("the function has a zero at %f \n",x);
	return(0);
}

float f(float x)
{
//	return sin(x);
	return x*x -4;
}

float df(float x)
{
/*	float h;
	h = 0.001;
	return (f(x+h) - f(x-h))/2*h; dont use numerical derivaties, tis useless!*/
//	return cos(x);
	return 2*x;
}
