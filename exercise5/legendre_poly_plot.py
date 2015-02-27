import matplotlib.pyplot as plt
from scipy.special import lpmv
import numpy as np

y1 = lpmv(0,0,np.linspace(-1,1,101))
y2 = lpmv(0,1,np.linspace(-1,1,101))
y3 = lpmv(0,2,np.linspace(-1,1,101))
y4 = lpmv(0,3,np.linspace(-1,1,101))
y5 = lpmv(0,4,np.linspace(-1,1,101))
y6 = lpmv(0,5,np.linspace(-1,1,101))
x = np.linspace(-1,1,101)

plt.hold(True)
plt.plot(x,y1,label = '0th order')
plt.plot(x,y2,label = '1st order')
plt.plot(x,y3,label = '2nd order')
plt.plot(x,y4,label = '3rd order')
plt.plot(x,y5,label = '4th order')
plt.plot(x,y6,label = '5th order')
plt.ylim([-1.1,1.1])
plt.title('legendre polynomials of degrees 0,1,2,3,4,5')
plt.legend(loc=4)

plt.show()
