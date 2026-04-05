import matplotlib.pyplot as plt
import math
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

ER = 1e-10  # CONSTANTE DE PRECISAO DA DERIVADA
LIM = 30    # LIMITE DE ITERAÇÕES DO METODO
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
    return x + Lda*d[0], y + Lda*d[1]

def DerParc_x(x, y):
    h = 1e-8
    return (f(x + h, y) - f(x - h, y)) / (2 * h)

def DerParc_y(x, y):
    h = 1e-8
    return (f(x, y + h) - f(x, y - h)) / (2 * h)

def GradDesc(x, y, e):
    pto = [x, y]
    d = [1, 1]
    d_norm = e + 1
    ct = 0
    Vet_Er = []
    while d_norm > e and ct < LIM:
        d = [DerParc_x(pto[0], pto[1]), DerParc_y(pto[0], pto[1])]
        d_norm = math.sqrt(d[0]**2 + d[1]**2)
        if d_norm < 1e-14:
            d_norm = 1e-14

        d[0], d[1] = d[0]/d_norm ,  d[1]/d_norm

        pto_n = Met_Newton(pto[0], pto[1], d)

        if(abs(pto_n[0]-pto[0])>abs(pto_n[1]-pto[1])):
            Vet_Er.append(abs(pto_n[0]-pto[0]))
        else:
            Vet_Er.append(abs(pto_n[1]-pto[1]))

        pto = [pto_n[0], pto_n[1]]
        ct += 1

    return pto, Vet_Er

x = float(input("Digite o valor de x inicial: "))
y = float(input("Digite o valor de y inicial: "))
e = float(input("Digite o valor da precisao desejada: "))

pto, Vet_Er = GradDesc(x, y, e)
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
ax.scatter(pto[0], pto[1], f(pto[0], pto[1]), color='b', label='Ponto ótimo')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('f(x, y)')
ax.set_title('Função com ponto ótimo')
ax.legend()
plt.show()