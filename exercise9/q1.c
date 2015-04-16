#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euler_stepper(double, double);
double pc_stepper(double ,double);
double rk2_stepper(double ,double);
double rk4_stepper(double ,double);

double dn(double);

int
main(void)
{
	FILE *err_ptr;
	FILE *soln_ptr;
	err_ptr = fopen("err_exp.dat","w");
	soln_ptr = fopen("exp_solve.dat","w");
	
	double h, t, N, n_eu, n_pc, n_rk2, n_rk4;
	double err_eu, err_pc, err_rk2, err_rk4;

	for (N=10; N<1000; N = 2*N)
	{
		t = 0;
		n_eu = 2;
		n_pc = 2;
		n_rk2 = 2;
		n_rk4 = 2;

		err_eu = 0;
		err_pc = 0;
		err_rk2 = 0;
		err_rk4 = 0;

		h = 1./N;

		while(t <1)
		{
			t += h;
	
			n_eu += euler_stepper(h, n_eu);
			n_pc += pc_stepper(h, n_pc);
			n_rk2 += rk2_stepper(h, n_rk2);
			n_rk4 += rk4_stepper(h, n_rk4);
	
			err_eu += fabs((n_eu -2*exp(-t))/(n_eu +2*exp(-t)));
			err_pc += fabs((n_pc -2*exp(-t))/(n_pc +2*exp(-t)));
			err_rk2 += fabs((n_rk2 -2*exp(-t))/(n_rk2 +2*exp(-t)));
			err_rk4 += fabs((n_rk4 -2*exp(-t))/(n_rk4 +2*exp(-t)));
	
			fprintf(soln_ptr, "%lf, %lf, %lf, %lf, %lf \n", t, n_eu, n_pc, n_rk2, n_rk4);
		}

		fprintf(err_ptr, "%lf, %lf, %lf, %lf %lf \n", t, err_eu, err_pc, err_rk2, err_rk4);	
	}
	
	fclose(soln_ptr);
	fclose(err_ptr);
	return(0);
}

double dn(double n)
{
	return -n;
}

double euler_stepper(double h, double n)
{
	return dn(n)*h;
}

double pc_stepper(double h, double n)
{
	double k1, k2;

	k1 = dn(n);
	k2 = dn(n +k1*h);

	return (k1+k2)*h/2.;
}

double rk2_stepper(double h, double n)
{
	double k1, k2;

	k1 = dn(n);
	k2 = dn(n +k1*h);

	return (k1+k2)*h/2.;
}

double rk4_stepper(double h, double n)
{
	double k1, k2, k3, k4;

	k1 = dn(n);
	k2 = dn(n +k1*h/2.);
	k3 = dn(n +k2*h/2.);
	k4 = dn(n +k3*h);

	return (k1+2*k2+2*k3+k4)*h/6.;
}
