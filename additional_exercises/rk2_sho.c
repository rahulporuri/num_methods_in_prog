#include <stdio.h>
#include <math.h>

int
main(void)
{
	double y, dy;
	double k1, k2;
	double K1, K2;
	double h;
	int i;

	FILE *in_ptr;
	in_ptr = fopen("rk2_sho.dat","w");

	y = 1;
	dy = 0;
	h = 0.1;
	for (i=0;i<1000;i++)
	{
		k1 = dy;
		K1 = -y;
		k2 = dy +K1*h;
		K2 = -(y +k1*h);
		y += h*(k1+k2)/2; // aces!
//		y += dy*h + 1./2*(K1)*pow(h,2); // aces!
		dy += h*(K1+K2)/2;
//		y += dy*h; wrongedy wrong wrong!
		fprintf(in_ptr,"%lf, %lf \n", y, dy);
	}

	fclose(in_ptr);
	return (0);
}
