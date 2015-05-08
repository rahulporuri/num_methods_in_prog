#include<stdio.h>
#include<stdlib.h>

int
main(void)
{
	FILE *in_ptr;
	char line[256];
	double a,b;
	int i;

	in_ptr = fopen("sample_test.dat","r");
	
	for (i=0;i<10;i++)
	{
		fgets(line, sizeof(line), in_ptr);
		sscanf(line, "%lf	%lf", &a, &b);
		printf("a:%lf b:%lf\n",a,b);
	}

	return(0);
}
