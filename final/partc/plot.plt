plot './stability_euler.dat' u 1:(log($2)) t 'euler', './stability_rk2.dat' u 1:(log($2)) t 'rk2'
set key top left
set title 'plot of relative local error for various alpha*h'
set xlabel 'alpha*h'
set ylabel 'log(rel_err)'

set term postscript color enhanced
set output 'rel_local_err.ps'

replot
