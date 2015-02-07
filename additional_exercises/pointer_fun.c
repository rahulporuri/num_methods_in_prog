#include <stdio.h>

int
main(void)
{
	int integer;
	float floating_point;
	double double_precision;

	int *int_ptr;
	float *float_ptr;
	double *double_ptr;
	void *void_ptr;

	integer = 1;
	floating_point = 1.0;
	double_precision = 1.0;

//	int_ptr = &integer;
//	float_ptr = &floating_point;
//	double_ptr = &double_precision;

	int_ptr = &floating_point;
	float_ptr = &double_precision;
	double_ptr = &integer;

	printf("%d,%lf,%lf \n",integer, floating_point, double_precision);
	printf("%d,%lf,%lf \n", *double_ptr, *int_ptr, *float_ptr);
//	printf("%d,%lf,%lf \n", *int_ptr, *float_ptr, *double_ptr);
	return(0);
}
