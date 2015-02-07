import math

temp = raw_input("please enter the x value where the function's derivative will be evaluated \n")
x0 = float(temp)
h_max = 0.1
h_min = 1e-17

def fn(x):
	return math.exp(x)

def first_deriv(x,h0,option):
	if option == 1:
		return (fn(x+h0)-fn(x))/h0
	elif option == 2:
		return (fn(x+h0)-fn(x-h0))/(2*h0)

h = h_max
print 'forward method - ', 'central method -'
print 'result \t\t', 'error \t\t', 'result \t\t', 'error \t\t'
while h > h_min:
	opt = 1
	result_forward = first_deriv(x0,h,opt)
	error_forward = result_forward - fn(x0)
	opt = 2
	result_central = first_deriv(x0,h,opt)
	error_central = result_central - fn(x0)
	print result_forward, error_forward, result_central, error_central
	h = h/10
