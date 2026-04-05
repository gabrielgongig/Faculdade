import matplotlib.pyplot as plt
import numpy as np
import math

ER = 1e-10  #CONSTANTE DE PRECISAO DA DERIVADA
LIM = 10    #LIMITE DE ITERAÇÕES DO METODO
H1 = 1e-12   #CONSTANTE DE SEGURANCA PARA EVITAR DIVISAO POR ZERO
H2 = 1e-20   #CONSTANTE DE SEGURANCA PARA EVITAR DIVISAO POR ZERO

def f(x):   #INSIRA AQUI A FUNCAO
    return x**2

def deriv_P(x, er):
    h = max(math.pow(er,0.5) * x, H1)
    return (f(x+h) - f(x-h))/(2*h)

def deriv_S(x, er):
    h = max(math.pow(er,0.25) * x, H1)
    num = f(x+h) - 2*f(x) + f(x-h)
    print(num)
    if abs(num) < H2: 
        num = H2
    return num / (h**2)

def M_Newton(x, e):
    V_x = []
    xn = x - deriv_P(x, ER)/deriv_S(x, ER)
    V_x.append(abs(xn-x))
    while (abs(xn - x) > e) and (len(V_x) < LIM):
        x = xn
        xn = x - deriv_P(x, ER)/deriv_S(x, ER)
        V_x.append(abs(xn-x))
    return xn, len(V_x), V_x

x = float(input("Insira o x: "))
e = float(input("Insira a precisao: "))

otm, it, V_x = M_Newton(x, e)

print("x otimo: ", otm)
print("f(x otimo): ", f(otm))
print("Iteracoes: ", it)

Qit = [i for i in range(1, it+1)]

plt.plot(Qit,V_x)
plt.title("Variacao do erro ao longo das iteracoes",fontsize=14, fontweight='bold', color='#4878E0')   
plt.xlabel("Iteracoes",fontsize=14, fontweight='bold', color='#4878E0')     
plt.ylabel("Erro",fontsize=12, fontweight='bold', color='#4878E0')     
plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
plt.show()