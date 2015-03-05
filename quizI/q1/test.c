#include<stdio.h>
#include <math.h>
int main(void)
{
	int i;
	int N;
	float s1;
	float s21,s22,s2;

	for (N=2;N<10;N=2*N)
	{
		s1 = 0;
		s21=0;
		s22=0;
		s2=0;
		
		for (i=1;i<N;i++)
		{
			s1 += pow(-1,i)*i/(i+1);
		}
		printf("s1 = %f \n",s1);

		for (i=1;i<N;i++)
		{
			if (i/2!=0)
			{
				s21 += 2*i/(2*i+1);
				printf ("i = %d,i/2 = %d \n",i,i/2);
			}
			if (i/2==1)
			{
				s22 += (2*i-1)/(2*i);
				printf ("i = %d, i/2 = %d \n",i,i/2);
			}
		}
		s2 = s21-s22;
		printf("s2 = %f \n",s2);
	}
	return (0);
}
/*	printf("%d, %lf \n",abs(i-10),pow(-1,i));*/
