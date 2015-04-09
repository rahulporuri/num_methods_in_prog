import numpy as np
#import numpy.linalg as npalg
import matplotlib.pyplot as plt

a = 0.
b = 1.


N = 10
while (N<100):
	A = np.zeros([N,N])
	eigval = np.zeros([N])
	eigvec = np.zeros([N,N])

	h = (b-a)/(N-1)
#print h
	
	for i in range(len(A)):
		for j in range(len(A[0])):
			# loading A
			if i==j:
				A[i][j] = 2
			if abs(i-j) == 1:
				A[i][j] = -1

#print a+i*h, b
#print A, '\n', B, '\n'

#print np.linalg.eig(A)
	(eigval, eigvec) = np.linalg.eig(A)
#print B

#	print eigval

	idx = eigval.argsort()
	eigval = eigval[idx]
	eigvec = eigvec[:,idx]

#	print eigval

#or np.linalg.inv(A)
#print X, '\n', U

	plt.scatter(np.linspace(0,1,N),eigvec[0]/h**(1./2))
	N = 2*N
plt.show()
