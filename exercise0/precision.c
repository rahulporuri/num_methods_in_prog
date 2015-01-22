/*FILE: precision.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 22 Jan 2015

Version: Original

Revision-History:

Comments:
22 Jan 2015 : code is used to compute machine precision

NOTES:

*/

#include<stdio.h>
#include<stdlib.h>

int
main(void)
{
	float eps;		/*variable to compute machine precision*/
	float i;
	eps = 1;
	i = 1;
	while( i+eps != i)
	{
		eps = eps/2;
		printf("eps %lf\n", eps);
	}
	printf("the machine precision of this system is %e \n",eps);
	return(0);
}
