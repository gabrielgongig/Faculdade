import matplotlib.pyplot as plt
import math
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

ER = 1e-10  # CONSTANTE DE PRECISAO DA DERIVADA
LIM = 30    # LIMITE DE ITERACOES DO METODO
H = 1e-12   # CONSTANTE DE SEGURANCA PARA EVITAR DIVISAO POR ZERO
H2 = 1e-20  # CONSTANTE DE SEGURANCA PARA EVITAR DIVISAO POR ZERO

def f(x, y):   #INSIRA AQUI A FUNCAO
    return (x - 2)**4 + (x - 2*y)**2

def Der_P(x, y, d, Lda):
    h = max(math.pow(ER,0.5) * abs(Lda), H)
    return (f(x + (Lda+h)*d[0], y + (Lda+h)*d[1]) - f(x + (Lda-h)*d[0], y + (Lda-h)*d[1]))/(2*h)

def Der_S(x, y, d, Lda):
    h = max(math.pow(ER,0.25) * abs(Lda), H)
    num = (f(x + (Lda+h)*d[0], y + (Lda+h)*d[1]) - 2*f(x + Lda*d[0], y + Lda*d[1])+ f(x + (Lda-h)*d[0], y + (Lda-h)*d[1]))
    if abs(num) < H2: 
        num = H2
    return num / (h**2)

def Met_Newton(x, y, d):
    Lda = 0.0
    ct = 0
    while ct < 100:
        der = Der_P(x + Lda*d[0], y + Lda*d[1], d, Lda)
        der2 = Der_S(x + Lda*d[0], y + Lda*d[1], d, Lda)
        if abs(der2) < H:  
            der2 = H   
        Lda_n = Lda - der/der2
        if abs(Lda_n-Lda) < 1e-12:
            Lda = Lda_n
            break
        Lda = Lda_n
        ct+=1
    x, y = x + Lda*d[0], y + Lda*d[1]
    return np.array([x, y])

def Gradiente(x, y):
    h = 1e-8
    vx = (f(x + h, y) - f(x - h, y)) / (2 * h)
    vy = (f(x, y + h) - f(x, y - h)) / (2 * h)
    return np.array([vx, vy])

def DFP(x0, y0, e):
    pto = np.array([x0, y0])
    D = np.eye(2)
    norm = e + 1
    it = 0
    Vet_Er = []
    while norm > e and it < 1000:
        d = Gradiente(pto[0], pto[1])
        norm = math.sqrt(d[0]**2 + d[1]**2)

        d0 = -D @ d

        pto_n = Met_Newton(pto[0], pto[1], d0)
        d_n = Gradiente(pto_n[0], pto_n[1])

        p = (pto_n - pto).reshape(-1, 1)
        q = (d_n - d).reshape(-1, 1)

        i1 = (p.T @ q)
        if i1 < H:
            i1 = H
        i2 = (q.T @ D @ q)
        if i2 < H:
            i2 = H
        D = D + (p @ p.T)/i1 - (D @ q @ q.T @ D)/i2

        d1 = -D @ d_n

        pto = Met_Newton(pto_n[0], pto_n[1], d1)
        norm = math.sqrt((pto[0]-pto_n[0])**2 + (pto[1]-pto_n[1])**2)
        it += 1
        Vet_Er.append(norm)
    return pto, Vet_Er

x = float(input("Digite o valor de x inicial: "))
y = float(input("Digite o valor de y inicial: "))
e = float(input("Digite o valor da precisao desejada: "))

pto, Vet_Er = DFP(x, y, e)
it = list(range(1, len(Vet_Er)+1))

print("Ponto de minimo encontrado: ", pto)
print("f(x, y) otimo: ", f(pto[0], pto[1]))
print("Numero de iteracoes: ", len(Vet_Er))

plt.plot(it, Vet_Er)
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
ax.scatter(pto[0], pto[1], f(pto[0], pto[1]), color='b', label='Ponto otimo')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('f(x, y)')
ax.set_title('Funcao com ponto otimo')
ax.legend()
plt.show()