#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void euler_stepper(double, double, double, double *);
void pc_stepper(double ,double, double, double *);
void rk2_stepper(double ,double, double, double *);
void rk4_stepper(double ,double, double, double *);

int
main(void)
{
	FILE *err_ptr;
	FILE *soln_ptr;
	err_ptr = fopen("err_energy.dat","w");	
	soln_ptr = fopen("sho_solve.dat","w");
	
	double t;
	double x_eu, dx_eu, x_pc, dx_pc, x_rk2, dx_rk2, x_rk4, dx_rk4;
	double err_eu, err_pc, err_rk2, err_rk4;
	double h;
	double update[2];

	h = 0.1;
	t = 0;
	x_eu = 1;
	dx_eu = 0;
	x_pc = 1;
	dx_pc = 0;
	x_rk2 = 1;
	dx_rk2 = 0;
	x_rk4 = 1;
	dx_rk4 = 0;
	
	while(t <4*M_PI)
	{
		t += h;
	
		euler_stepper(h, x_eu, dx_eu, update);
		x_eu += update[0];
		dx_eu += update[1];

		pc_stepper(h, x_pc, dx_pc, update);
		x_pc += update[0];
		dx_pc += update[1];

		rk2_stepper(h, x_rk2, dx_rk2, update);
		x_rk2 += update[0];
		dx_rk2 += update[1];

		rk4_stepper(h, x_rk4, dx_rk4, update);
		x_rk4 += update[0];
		dx_rk4 += update[1];

		err_eu = fabs((1./2*(x_eu*x_eu +dx_eu*dx_eu) -1./2)/(1./2*(x_eu*x_eu +dx_eu*dx_eu) +1./2));
		err_eu = fabs((1./2*(x_pc*x_pc +dx_pc*dx_pc) -1./2)/(1./2*(x_pc*x_pc +dx_pc*dx_pc) +1./2));
		err_rk2 = fabs((1./2*(x_rk2*x_rk2 +dx_rk2*dx_rk2) -1./2)/(1./2*(x_rk2*x_rk2 +dx_rk2*dx_rk2) +1./2));
		err_rk4 = fabs((1./2*(x_rk4*x_rk4 +dx_rk4*dx_rk4) -1./2)/(1./2*(x_rk4*x_rk4 +dx_rk4*dx_rk4) +1./2));

		fprintf(soln_ptr, "%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf \n", t, x_eu, dx_eu, x_pc, dx_pc, x_rk2, dx_rk2, x_rk4, dx_rk4);
		fprintf(err_ptr, "%lf, %lf, %lf, %lf, %lf \n", t, err_eu, err_pc, err_rk2, err_rk4);
	}
	return(0);
}

void euler_stepper(double h, double x, double dx, double *update)
{
	update[0] = dx*h;
	update[1] = -x*h;	
	return;
}

void pc_stepper(double h, double x, double dx, double *update)
{
	double k1, k2;
	double K1, K2;

	k1 = dx;
	K1 = -x;
	k2 = dx +K1*h;
	K2 = -(x +k1*h);

	update[0] = (k1+k2)*h/2.;
	update[1] = (K1+K2)*h/2.;	
	return;
}

void rk2_stepper(double h, double x, double dx, double *update)
{
	double k1, k2;
	double K1, K2;

	k1 = dx;
	K1 = -x;
	k2 = dx +K1*h;
	K2 = -(x +k1*h);

	update[0] = (k1+k2)*h/2.;
	update[1] = (K1+K2)*h/2.;	
	return;
}

void rk4_stepper(double h, double x, double dx, double *update)
{
	double k1, k2, k3, k4;
	double K1, K2, K3, K4;

	k1 = dx;
	K1 = -x;
	k2 = dx +K1*h/2.;
	K2 = -(x +k1*h/2.);
	k3 = dx +K2*h/2.;
	K3 = -(x +k2*h/2.);
	k4 = dx +K3*h;
	K4 = -(x +k3*h);

	update[0] = (k1+2*k2+2*k3+k4)*h/6.;
	update[1] = (K1+2*K2+2*K3+K4)*h/6.;	
	return;
}
