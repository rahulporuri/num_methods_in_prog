#plot file for 3d plot
set terminal postscript color enhanced
set output 'test.eps'
set pm3d at s #sets the contour on surface
set hidden3d #enhances 3d Features
set xlabel "t"
set ylabel "x"
set zlabel "T(x,t)"

#plot 3d
splot "./pde_solvers_test_diffusion_test.dat" using 1:2:3 w pm3d title ''

set output '3dplot.eps'
splot "pde_solvers_test_diffusion_test.dat" using 1:2:3 w pm3d title 'implicit scheme'
