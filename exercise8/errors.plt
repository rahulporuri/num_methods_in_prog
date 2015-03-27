#plot 'file_0.100000.dat' u (log($4)):(log($1)) t 'x=0.1', 'file_1.000000.dat' u (log($4)):(log($1)) t 'x=1', 'file_10.000000.dat' u (log($4)):(log($1)) t 'x=10', 'file_100.000000.dat' u (log($4)):(log($1)) t 'x=100'

plot 'file_0.100000.dat' u (log($4)):(log($2)) t 'x=0.1', 'file_1.000000.dat' u (log($4)):(log($2)) t 'x=1', 'file_10.000000.dat' u (log($4)):(log($2)) t 'x=10', 'file_100.000000.dat' u (log($4)):(log($2)) t 'x=100'

#set title 'relative errors in stepwise summation method to estimate exp(-x)'
set title 'relative errors in recursion method to estimate exp(-x)'
set xlabel 'log(N)'
set ylabel 'log(e)'
set key bottom right

set term postscript color enhanced
#set output 'stepwise_eval_err.ps'
set output 'recursive_eval_err.ps'
replot
