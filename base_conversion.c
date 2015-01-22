/*FILE: base_conversion.c

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 22 Jan 2015

Version: Original

Revision-History:

Comments:
22 Jan 2015 : code is used to convert a number from base 10 to base 2

NOTES:

*/

#include<stdio.h>
#include<stdlib.h>

int
main(void)
{
	int input;		/*number to be converted from base 10 to base 2*/
	int output[10];		/*to store the output in binary*/
	int i;
	i = 0;
	int j;

	printf("input the number which you want to convert to base 2 :\n");
	scanf("%d",&input);

	while (input > 8200)
	{
		printf ("please input a number smaller than 1024 to continue \n");
		scanf("%d",&input);
	}
	printf("you want %d to be converted to base 2 \n", input);

	while (input != 0)
	{
		printf("%d \t",input - 2*(input/2));
		output[i] = input - 2*(input/2);
		input = input/2;
		printf("%d\n",i);
		i++;
	}

	printf("%d \n",i);
	printf("let's try something new \n");

	for(j=0;j<i;j++)
	{
		printf("%d\t",output[i-j-1]);
		printf("%d\n",i-j-1);
	}
	return(0);
}
