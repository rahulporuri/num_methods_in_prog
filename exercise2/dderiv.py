import math

temp = raw_input("please enter the x value where the function's derivative will be evaluated \n")
x0 = float(temp)
h_max = 0.1
h_min = 1e-17

def fn(x):
	return math.exp(x)

def second_deriv(x,h0):
	return (fn(x+h0) +fn(x-h0) -2*fn(x))/(h0**2)

h = h_max
print 'second derivative - '
print 'result \t\t', 'error \t\t'
while h > h_min:
	result = second_deriv(x0,h)
	error = result - fn(x0)
	print result, error
	h = h/10
