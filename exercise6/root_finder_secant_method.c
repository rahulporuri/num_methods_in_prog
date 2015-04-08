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
	float a,b,c;
	float temp;

	printf("the two initial estimates are \n");
	scanf("%f, %f", &a, &b);
	printf("starting with the estimate : %f %f \n",a,b);

	temp = f(a)*f(b);
	if (abs(temp) + temp != 0)		/*meaning that the product is positive i.e a,b are on the same side of the zero*/
	{
		printf("please input other values of a & b \n");
		scanf("%f, %f", &a, &b);
		printf("the new values of a and b are : %f, %f \n",a, b);
	}

	else
	{
		c = (a*f(b) -b*f(a))/(f(b) -f(a));

		if (f(c) != 0)
		{
			temp = f(a)*f(c);
			if (abs(temp) + temp !=0)	/*meaning that the zero is in the interval b,c*/
			{
				a = c;
				c = (a*f(b) -b*f(a))/(f(b) -f(a));
			}
			else
			{
				b = c;
				c = (a*f(b) -b*f(a))/(f(b) -f(a));
			}
		}
	}

	printf("the function has a zero at %f \n",c);
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
