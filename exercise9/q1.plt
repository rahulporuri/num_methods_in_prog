f(x) = a*x +b
g(x) = c*x +d
h(x) = e*x +j
i(x) = k*x +l

fit f(x) 'err_exp.dat' u (log10($1)):(log10($2)) via a,b
fit g(x) 'err_exp.dat' u (log10($1)):(log10($3)) via c,d
fit h(x) 'err_exp.dat' u (log10($1)):(log10($4)) via e,j
fit i(x) 'err_exp.dat' u (log10($1)):(log10($5)) via k,l

plot f(x) t 'slope:-0.00622348', g(x) t 'slope:0.00222134', h(x) t 'slope:0.00222134', i(x) t 'slope:0.000369902', 'err_exp.dat' u (log10($1)):(log10($2)) t 'euler','err_exp.dat' u (log10($1)):(log10($3)) t 'pc','err_exp.dat' u (log10($1)):(log10($4)) t 'rk2','err_exp.dat' u (log10($1)):(log10($5)) t 'rk4'

set key center left
set title 'plot of global error with respect to N'
set xlabel 'log(N)'
set ylabel 'log(e)'

set term postscript color enhanced
set output 'global_err.ps'
replot
