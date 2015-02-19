cimport numpy
import numpy

def fn(double x):
	return numpy.exp(x)

def integ_trap(double a, double b, double h):
	cdef double output
	output = fn(a)/2.
	while a<b:
		output += fn(a+h)
		a += h
	return (output + fn(b)/2.)*h

#print integ_trap(0,1,0.01)
#timeit integ_trap(0,1,1e-05)

for i in range(1,10):
	h = 1e-1**i
	print integ_trap(0,1,h)  - numpy.exp(1) + numpy.exp(0)
#print "exponential of 1 is", fn(0.)
