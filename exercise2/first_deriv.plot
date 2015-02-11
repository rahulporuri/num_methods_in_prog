# http://people.duke.edu/~hpgavin/gnuplot.html
set term postscript color  enhanced
set output 'plot_of_log_e_vs_log_h_first_deriv.ps'

f(x) = a*x + b
g(x) = c*x + d
fit [:-18] f(x) 'deriv_test_first_err.dat' u (log($1)):(log($2)) via a,b
fit [-16:] g(x) 'deriv_test_first_err.dat' u (log($1)):(log($2)) via c,d

set title 'plot of log error vs log h - forward method, first derivative'
set xlabel 'log(h)'
set ylabel 'log(e)'
plot f(x), g(x), 'deriv_test_first_err.dat' u (log($1)):(log($2))

