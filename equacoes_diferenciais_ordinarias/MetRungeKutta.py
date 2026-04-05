# MetRungeKutta.py
import math
import numpy as np
import matplotlib.pyplot as plt

def RK(dN, h, y0, ti, tf):
    t = ti
    y = y0
    VY = [y]

    for i in range(int((tf - ti) / h)):
        k1 = dN(y)
        k2 = dN(y + (h / 2) * k1)
        k3 = dN(y + (h / 2) * k2)
        k4 = dN(y + h * k3)

        y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4)
        t += h
        VY.append(y)

    return np.array(VY)