plot 'file_0.dat' t 'zeroth order', 'file_1.dat' t 'first order', 'file_2.dat' t 'second order', 'file_3.dat' t 'third order', 'file_4.dat' t 'fourth order', 'file_5.dat' t 'fifth order'
set yrange [-1:1.1]
set term postscript color enhanced
set output 'legendre_functions_plot.ps'
replot
