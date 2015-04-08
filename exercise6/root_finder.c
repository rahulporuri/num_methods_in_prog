/*
why is the code making me choose a,b values that are equidistant from the zero of the function?
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(double x);

int
main(void)
{
	float a,b,c;
	float temp;

	printf("please input the values of a and b \n");
	scanf("%f, %f", &a, &b);
	printf("the values of a and b are : %f, %f \n",a, b);

	temp = f(a)*f(b);
	if (abs(temp) + temp != 0)		/*meaning that the product is positive i.e a,b are on the same side of the zero*/
	{
		printf("please input other values of a & b \n");
		scanf("%f, %f", &a, &b);
		printf("the new values of a and b are : %f, %f \n",a, b);
	}

	else
	{
		c = (a+b)/2;
		if (f(c) != 0)
		{
			temp = f(a)*f(c);
			if (abs(temp) + temp !=0)	/*meaning that the zero is in the interval b,c*/
			{
				a = c;
				c = (a+b)/2;
			}
			else
			{
				b = c;
				c = (a+b)/2;
			}
		}
		else
		{
			printf("the function has a zero at %f \n",c);
		}
	}
	return(0);
}

float f(double x)
{
	return x +4;
}
