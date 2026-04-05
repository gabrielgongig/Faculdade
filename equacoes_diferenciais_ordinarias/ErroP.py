# ErroP.py
import math
import numpy as np

def DesvioPercentual(V_an, V_num, h, t):
    for i in range(t + 1):
        n = int(i / h)
        m = int(i / 0.1)
        e = abs((V_an[m] - V_num[n]) / V_an[m]) * 100
        print(f"t = {i:.1f} | Desvio Percentual: {e:.7f}%")
    return 0