set term postscript color enhanced
set output 'time.ps'

set title 'plot of time taken vs size of array'
set xlabel 'log(N)'
set ylabel 'log(t)'

f(x) = a*x + b
fit f(x) 'time.dat' u  (log($1)):(log($2)) via a,b
plot f(x) t 'slope a : 3.07491 ', 'time.dat' u (log($1)):(log($2)) t ''
