set term postscript color enhanced
set output 'error.ps'

set title 'plot of relative error vs size of array'
set xlabel 'log(error)'
set ylabel 'log(N)'

plot 'eigen_values.dat' u (log($1)):(log($2)) t ''
