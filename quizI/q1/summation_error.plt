set term postscript color enhanced
set output 'summation_errors.ps'
set xlabel 'log10(N)'
set ylabel 'log10(Serr)'
set title 'plot of Serr vs N'
plot  'summation_error_1.dat' u (log10($1)):(log10($2)) t 'S1err', 'summation_error_2.dat' u (log10($1)):(log10($2)) t 'S2err'
