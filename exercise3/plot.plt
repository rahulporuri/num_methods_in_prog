f(x) = a*x + b
g(x) = c*x + d
h(x) = e*x + f

fit f(x) 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($2)) via a,b
fit [] [.1:] g(x) 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($3)) via c,d
fit [] [.1:] h(x) 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($4)) via e,f

plot f(x), g(x), h(x), 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($2)), 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($3)), 'integ_test_exp_alpha_beta_vs_N_max.dat' u (log($1)):(log($4))
