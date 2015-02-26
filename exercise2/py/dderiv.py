'''
FILE: dderiv.py

Programer: Poruri Sai Rahul email ID : rahul.poruri@gmail.com

Version: Original

Date: 14 Feb 2015
Revision-History:
	14 Feb 2015

Comments:
14 Feb 2015: Estimates the second derivative of a function exp(x).
'''

import math
import numpy as np
import matplotlib.pyplot as plt

temp = raw_input("please enter the x value where the function's derivative will be evaluated \n")
x0 = float(temp)
h_max = 0.1
h_min = 1e-17

result = []
error = []
x = []

def fn(x):
	return math.exp(x)

def second_deriv(x,h0):
	return (fn(x+h0) +fn(x-h0) -2*fn(x))/(h0**2)

h = h_max
print 'second derivative - '
print 'result \t\t', 'error \t\t'
while h > h_min:
	temp = second_deriv(x0,h)
	temp1 = temp - fn(x0)
	result.append(temp)
	error.append(temp1)
	x.append(h)
	print result, error
	h = h/10

np.asarray(result)
np.asarray(error)
np.asarray(x)
plt.plot(log(x),log(result))
plt.plot(log(x),log(error))
