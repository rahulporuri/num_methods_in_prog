import numpy as np
import matplotlib.pyplot as plt

def factorial(n):
	fact = 1
	while n != 0:
		fact = fact*n
		n = n-1
	return fact

def eval_sum(x,N):
	summ = 1.
	for i in range(1,N):
		summ += ((-1.)**i)*(x**i)/factorial(i)
	return summ

def eval_step(x,N):
	summ = 0.
	y = 1.
	for i in range(0,N):
		summ += y
		y = -y*x/(i+1.)
	return summ

#for i in range(10):
#	print i, factorial(i)
result_sum = 0.
result_step = 0.
rel_err_sum = 0.
rel_err_step = 0.
actual = 0.

for x in [0.1,1.,10.]:
	print x
	for N in range(1,50):	
		result_sum = eval_sum(x,N)
		result_step = eval_step(x,N)
		actual = np.exp(-x)
		rel_err_sum = abs((actual -result_sum)/(actual +result_sum))
		rel_err_step = abs((actual -result_step)/(actual +result_step))
		print 'errors are', rel_err_sum, rel_err_step, 'for N =', N
#		print 'evaluations are ', result_sum, result_step, actual
