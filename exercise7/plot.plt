
plot 'test_10.dat' u 1:2 title 'analytical result', 'test_10.dat' u 1:3 title 'N=10', 'test_100.dat' u 1:3 title 'N=100', 'test_1000.dat' u 1:3 title 'N=1000'
set key top left
set title 'comparison of analytic results to that obtained using simultaneous linear equations'
set xlabel 'x'
set ylabel 'y'

set term postscript color enhanced
set output 'lu_decomp.ps'
replot
