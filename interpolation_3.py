import numpy as np
import matplotlib.pyplot as plt

data = [line.split() for line in open('sample_data.dat')][2:]
data = np.asarray(data, dtype=float)
print data

step1 = np.zeros(3,dtype=float)
for i in range(2):
	step1[i] = (data[i+1][1] -data[i][1])/(data[i+1][0] -data[i][0])

print step1

step2 = np.zeros(2,dtype=float)
for i in range(1):
	step2[i] = (step1[i+1]-step1[i])/(data[i+2][0] -data[i][0])

print step2

step3 = np.zeros(1,dtype=float)
for i in range(0):
	step3[i] = (step2[i+1]-step2[i])/(data[i+3][0] -data[i][0])

print step3

old_x = np.zeros(len(data))
old_y = np.zeros(len(data))

for i in range(len(data)):
	old_x[i] = data[i][0]
	old_y[i] = data[i][1]

print old_x, old_y

coeffs = np.zeros(4)
coeffs[0] = data[0][1]
coeffs[1] = step1[0]
coeffs[2] = step2[0]
coeffs[3] = step3[0]

print coeffs

#new_x = 0
new_x = np.linspace(0,50,11)

for k in range(len(new_x)):
	result = coeffs[0]
	for i in range(1,3):
		prod = 1
		for j in range(i-1):
			prod = prod*(new_x[k]-old_x[j])
		result += prod*coeffs[i]
	print new_x[k], result
