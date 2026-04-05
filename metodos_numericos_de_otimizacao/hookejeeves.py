import matplotlib.pyplot as plt
import math
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

ER = 1e-10  # CONSTANTE DE PRECISAO DA DERIVADA
LIM = 10    # LIMITE DE ITERAÇÕES DO METODO
H = 1e-12   # CONSTANTE DE SEGURANCA PARA EVITAR DIVISAO POR ZERO

def f(x, y): 
    return (x-3)**2 + (y+1)**2 #ALTERE A FUNÇÃO AQUI

def deriv_P(l, x0, y0, dx, dy):
    h = max(math.sqrt(ER) * abs(l), H)
    return (f(x0 + (l+h)*dx, y0 + (l+h)*dy) - f(x0 + (l-h)*dx, y0 + (l-h)*dy)) / (2*h)

def deriv_S(l, x0, y0, dx, dy):
    h = max(ER**0.25 * abs(l), H)
    num = f(x0 + (l+h)*dx, y0 + (l+h)*dy) - 2*f(x0 + l*dx, y0 + l*dy) + f(x0 + (l-h)*dx, y0 + (l-h)*dy)
    if abs(num) < 1e-20:
        num = 1e-20
    return num / (h**2)

def M_Newton(x0, y0, dx, dy):
    ct = 0
    l = 0.0
    while ct < 100:
        der = deriv_P(l, x0, y0, dx, dy)
        der2 = deriv_S(l, x0, y0, dx, dy)
        if abs(der2) < 1e-12:  
            der2 = 1e-12
        ln = l - der / der2
        if abs(ln - l) < 1e-12:
            l = ln
            break
        l = ln
        ct += 1
    return x0 + l*dx, y0 + l*dy  

def HookeJeeves(x1, y1, e):
    ct = 0
    fs = []
    while ct < 100:
       
        x_old, y_old = x1, y1

        x2, y2 = M_Newton(x1, y1, 1, 0)
        x3, y3 = M_Newton(x2, y2, 0, 1)

        dpx = x3 - x1
        dpy = y3 - y1
        x1, y1 = M_Newton(x3, y3, dpx, dpy)
        
        if(abs(x1-x_old)>abs(y1-y_old)):
            fs.append(abs(x1-x_old))
        else:
            fs.append(abs(y1-y_old))

        if (abs(x1-x_old)**2 + abs(y1-y_old)**2)**(0.5) < e :
            break
        ct += 1

    return x1, y1, fs

x = float(input("Digite o valor de x inicial: "))
y = float(input("Digite o valor de y inicial: "))
e = float(input("Insira a precisao: "))

x_otm, y_otm, erros = HookeJeeves(x, y, e)

iteracoes = list(range(1, len(erros)+1))

print("ponto otimo: ", x_otm, y_otm)
print("f(x, y) otimo: ", f(x_otm, y_otm))

if len(erros) >= 99:
    print("-------------------------------------------------------------------------------------------------------------------")
    print("ATENCAO!!!")
    print("O metodo foi paralisado pois o numero maximo de iteracoes foi atingido, indicando que provavelmente nao houve convergencia. Inicialize com outro ponto e tente novamente")
    print("-------------------------------------------------------------------------------------------------------------------")

plt.plot(iteracoes, erros)
plt.title("Diminuicao do erro ao longo das iteracoes", fontsize=14, fontweight='bold', color='#4878E0')
plt.xlabel("Iteracoes", fontsize=14, fontweight='bold', color='#4878E0')
plt.ylabel("Erro", fontsize=12, fontweight='bold', color='#4878E0')
plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
plt.show()

x = np.linspace(-100, 100, 1000)
y = np.linspace(-100, 100, 1000)
X, Y = np.meshgrid(x, y)
Z = f(X, Y)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.8)
ax.scatter(x_otm, y_otm, f(x_otm, y_otm), color='b', label='Ponto ótimo')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('f(x, y)')
ax.set_title('Função com ponto ótimo')
ax.legend()
plt.show()