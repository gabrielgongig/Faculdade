# MetEuler.py
import math
import numpy as np
import matplotlib.pyplot as plt

def Euler(dN, h, y0, ti, tf):
    t = ti
    y = y0
    VY = [y]

    for i in range(int((tf - ti) / h)):
        y = y + h * dN(y)
        t += h
        VY.append(y)

    return np.array(VY)