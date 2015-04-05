import numpy as np
import matplotlib.pyplot as plt

data = [line.split() for line in open('sample_data.dat')][2:]
data = np.asarray(data, dtype=float)
print data

step1 = np.zeros(len(data)-1,dtype=float)
for i in range(len(data)-1):
	step1[i] = (data[i+1][1] -data[i][1])/(data[i+1][0] -data[i][0])

print step1

step2 = np.zeros(len(data)-2,dtype=float)
for i in range(len(step1)-1):
	step2[i] = (step1[i+1]-step1[i])/(data[i+2][0] -data[i][0])

print step2

step3 = np.zeros(len(data)-3,dtype=float)
for i in range(len(step2)-1):
	step3[i] = (step2[i+1]-step2[i])/(data[i+3][0] -data[i][0])

print step3

step4 = np.zeros(len(data)-4,dtype=float)
for i in range(len(step3)-1):
	step4[i] = (step3[i+1]-step3[i])/(data[i+4][0] -data[i][0])

print step4

step5 = np.zeros(len(data)-5,dtype=float)
for i in range(len(step4)-1):
	step5[i] = (step4[i+1]-step4[i])/(data[i+5][0] -data[i][0])

print step5

step6 = np.zeros(len(data)-6,dtype=float)
for i in range(len(step5)-1):
	step6[i] = (step5[i+1]-step5[i])/(data[i+6][0] -data[i][0])

print step6

step7 = np.zeros(len(data)-7,dtype=float)
for i in range(len(step6)-1):
	step7[i] = (step6[i+1]-step6[i])/(data[i+7][0] -data[i][0])

print step7

step8 = np.zeros(len(data)-8,dtype=float)
for i in range(len(step7)-1):
	step8[i] = (step7[i+1]-step7[i])/(data[i+8][0] -data[i][0])

print step8

old_x = np.zeros(len(data))
old_y = np.zeros(len(data))

for i in range(len(data)):
	old_x[i] = data[i][0]
	old_y[i] = data[i][1]

print old_x, old_y

coeffs = np.zeros(9)
coeffs[0] = data[0][1]
coeffs[1] = step1[0]
coeffs[2] = step2[0]
coeffs[3] = step3[0]
coeffs[4] = step4[0]
coeffs[5] = step5[0]
coeffs[6] = step6[0]
coeffs[7] = step7[0]
coeffs[8] = step8[0]

print coeffs

#new_x = 0
new_x = np.linspace(0,200,41)

for k in range(len(new_x)):
	result = coeffs[0]
	for i in range(1,9):
		prod = 1
		for j in range(i-1):
			prod = prod*(new_x[k]-old_x[j])
		result += prod*coeffs[i]
	print new_x[k], result
