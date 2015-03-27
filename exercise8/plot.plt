#plot 'file_1.000000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_1.000000.dat' u (log($4)):(log($2)) title 'recursion method'
#plot 'file_1.000000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_1.000000.dat' u (log($4)):(log($2)) title 'recursion method'
#plot 'file_1.000000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_1.000000.dat' u (log($4)):(log($2)) title 'recursion method'
#plot 'file_1.000000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_1.000000.dat' u (log($4)):(log($2)) title 'recursion method'

plot 'file_0.100000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_0.100000.dat' u (log($4)):(log($2)) title 'recursion method', 'file_1.000000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_1.000000.dat' u (log($4)):(log($2)) title 'recursion method', 'file_10.000000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_10.000000.dat' u (log($4)):(log($2)) title 'recursion method', plot 'file_100.000000.dat' u (log($4)):(log($1)) title 'series summation method', 'file_100.000000.dat' u (log($4)):(log($2)) title 'recursion method'

set key top left
set title 'error in estimation of exponential of -x using various methods'
set xlabel 'log(N)'
set ylabel 'log(e)'

set term postscript color enhanced
set output 'eval_exp.ps'
replot
