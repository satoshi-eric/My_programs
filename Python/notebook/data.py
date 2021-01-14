from matplotlib import pyplot as plt
import numpy as np

f = lambda x: x**2

x_list = [i for i in np.arange(0, 10)]
x = np.array(x_list)

y_list = [f(i) for i in np.arange(0, 10)]
y = np.array(y_list)

plt.plot(x, y)
plt.show()