/*FILE: plot.plt

Programer: Poruri Sai Rahul email ID : rahul.poruri@gmail.com

Version: Original

Date: 14 Feb 2015

Revision-History:
	14 Feb 2015

Comments:
*/

f(x) = a*x + b
g(x) = c*x + d
h(x) = e*x + f

fit f(x) 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($2)) via a,b
fit [:7] g(x) 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($3)) via c,d
fit [:7] h(x) 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($4)) via e,f

plot f(x) t '', g(x) t '', h(x) t '', 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($2)) t 'trapezoid rule - slope : -2.00926', 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($3)) t 'simpsons rule - slope : -4.06551', 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($4)) t '3/8ths rule - slope : -4.05259'
set xtitle 'log(h)'
set ytitle 'log(e)'
set title 'plot of log(error) vs log(step size) for various integration methods'

set term postscript color enhanced
set output 'integ_test_plot.ps'
replot
