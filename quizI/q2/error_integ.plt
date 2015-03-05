f(x) = a*x + b
fit f(x) 'integ_test_fn_vs_N_max.dat' u (log10($1)):(log10($2)) via a,b
set xlabel 'log10(N)'
set ylabel 'log10(error)'
set title 'plot of error in integral estimation vs N'
plot f(x), 'integ_test_fn_vs_N_max.dat' u (log10($1)):(log10($2)) t 'y=x**(1./3.)', 'integ_test_fn_vs_N_max.dat' u (log10($1)):(log10($3)) t 'assuming x = u**3'
set term postscript color enhanced
set output 'error_integ.ps'
replot
