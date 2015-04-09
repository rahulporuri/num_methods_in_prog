set term postscript color enhanced
set output 'wavefunction.ps'

set title 'plot of amplitude of wave function vs x'
set xlabel 'psi(x)'
set ylabel 'x'

plot 'schro_solve_10.dat' t 'N=10','schro_solve_20.dat' t 'N =20' , 'schro_solve_40.dat' t 'N =40','schro_solve_80.dat' t 'N =80' , 'schro_solve_160.dat' t 'N =160', 'schro_solve_320.dat' t 'N =320', 'schro_solve_640.dat' t 'N =640', 'schro_solve_1280.dat' t 'N =1280', (2**(1./2))*sin(pi*x) t 'analytical soln'
