#include <stdio.h>
#include <math.h>

int
main(void)
{
	double y, dy;
	double k1, k2, k3, k4;
	double K1, K2, K3, K4;
	double h;
	int i;

	FILE *in_ptr;
	in_ptr = fopen("rk4_sho.dat","w");

	y = 0.;
	dy = 1.;
	h = 0.1;
	for (i=0;i<1000;i++)
	{
		k1 = dy;
		K1 = -y;
		k2 = dy +K1*h/2.;
		K2 = -(y +k1*h/2.);
		k3 = dy +K2*h/2.;
		K3 = -(y +k2*h/2.);
		k4 = dy +K3*h;
		K4 = -(y +k3*h);
		y += h*(k1 +2*k2 +2*k3 +k4)/6.;
		dy += h*(K1 +2*K2 +2*K3 +K4)/6.;
		fprintf(in_ptr,"%lf, %lf \n", y, dy);
	}

	fclose(in_ptr);
	return (0);
}
