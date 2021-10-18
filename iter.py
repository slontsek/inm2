import numpy as np
A = np.array([[1.5, 0.5], [0, 1.5]])
b = np.ones((2,1))
x = np.zeros((2,1))
tau = 1
B = np.eye(2) - tau*A
for i in range (100):
    x = B@x + tau*b
    print(x)


