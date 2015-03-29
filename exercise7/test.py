import numpy as np
import scipy.linalg as spalg
import matplotlib.pyplot as plt

a = 0.
b = 1.
N = 1000

A = np.zeros([N,N])
B = np.zeros(N)
U = np.zeros(N)

h = (b-a)/(N-1)
print h

def fn(x):
	return (3*x+x**2)*np.exp(x)

def un(x):
	return x*(1-x)*np.exp(x)

for i in range(len(A)):
	for j in range(len(A[0])):
		# loading A
		if i==j:
			A[i][j] = 2
		if abs(i-j) == 1:
			A[i][j] = -1
	B[i] = h**2*fn(a+i*h)
	U[i] = un(a+i*h)

print a+i*h, b
#print A, '\n', B, '\n'

X = spalg.solve(A,B)

#print X, '\n', U

plt.hold(True)
plt.plot(np.linspace(a,b,N,endpoint=True),U)
plt.plot(np.linspace(a,b,N,endpoint=True),X)
plt.show()
