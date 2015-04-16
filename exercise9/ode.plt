f(x) = a*x +b
g(x) = c*x +d
h(x) = e*x +j
i(x) = k*x +l

fit f(x) 'err_energy.dat' u (log10($1)):(log10($2)) via a,b
fit g(x) 'err_energy.dat' u (log10($1)):(log10($3)) via c,d
fit h(x) 'err_energy.dat' u (log10($1)):(log10($4)) via e,j
fit i(x) 'err_energy.dat' u (log10($1)):(log10($5)) via k,l

plot f(x) t 'slope:1.18896', g(x) t 'slope:1.00104', h(x) t 'slope:1.00104', i(x) t 'slope:-5.38045e-13', 'err_energy.dat' u (log10($1)):(log10($2)) t 'euler', 'err_energy.dat' u (log10($1)):(log10($3)) t 'pc', 'err_energy.dat' u (log10($1)):(log10($4)) t 'rk2', 'err_energy.dat' u (log10($1)):(log10($5)) t 'rk4'

set key top left
set title 'plot of error in energy vs iteration'
set xlabel 'log(i)'
set ylabel 'log(e)'

set term postscript color enhanced
set output 'err_energy.ps'
replot
