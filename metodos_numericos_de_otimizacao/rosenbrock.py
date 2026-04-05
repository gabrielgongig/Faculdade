import matplotlib.pyplot as plt
import math
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

ER = 1e-10  # CONSTANTE DE PRECISAO DA DERIVADA
LIM = 10    # LIMITE DE ITERAÇÕES DO METODO
H = 1e-12   # CONSTANTE DE SEGURANCA PARA EVITAR DIVISAO POR ZERO
H2 = 1e-20  # CONSTANTE DE SEGURANCA PARA EVITAR DIVISAO POR ZERO

def f(x,y):
    return 100*(y - x**2)**2 + (1-x)**2 #ALTERE A FUNÇÃO AQUI

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
    return x + Lda*d[0], y + Lda*d[1], Lda

def Rosenbrock(x1, y1, e):
    d1 = [1,0]
    d2 = [0,1]
    dp = [0,0]
    ct = 0
    Vet_Er = []
    while ct < 100:
        xo, yo = x1, y1
        x2, y2, L2 = Met_Newton(x1, y1, d1)
        x3, y3, L3 = Met_Newton(x2, y2, d2)

        dp[0], dp[1] = x3 - x1, y3 - y1
        dp_norm = (dp[0]**2 + dp[1]**2)**0.5
        dp_norm = max(dp_norm, H)
        dp[0], dp[1] = dp[0]/dp_norm, dp[1]/dp_norm

        x1, y1, Lp = Met_Newton(x3, y3, dp)

        if(abs(x1-xo)>abs(y1-yo)):
            Vet_Er.append(abs(x1-xo))
        else:
            Vet_Er.append(abs(y1-yo))
        
        if (abs(x1-xo)**2 + abs(y1-yo)**2)**(0.5) < e:
            break

        d1[0], d1[1] = (L2*d1[0] + L3*d2[0]), L2*d1[1] + L3*d2[1]
        norm1 = ((d1[0]**2 + d1[1]**2)**0.5)
        norm1 = max(norm1, H)
        d1[0], d1[1] = d1[0]/norm1, d1[1]/norm1

        mat=(d2[0]*d1[0] + d2[1]*d1[1])
        d2[0], d2[1] = L3*d2[0] - mat*d1[0], L3*d2[1] - mat*d1[1]
        norm2 = ((d2[0]**2 + d2[1]**2)**0.5)
        norm2 = max(norm2, H)
        d2[0], d2[1] = d2[0]/norm2, d2[1]/norm2
        ct += 1
    return x1, y1, Vet_Er

x = float(input("Digite o valor de x inicial: "))
y = float(input("Digite o valor de y inicial: "))
e = float(input("Insira a precisao: "))

x_otm, y_otm, Vet_Er = Rosenbrock(x, y, e)

iteracoes = list(range(1, len(Vet_Er)+1))

print("ponto otimo: ", x_otm, y_otm)
print("f(x, y) otimo: ", f(x_otm, y_otm))
print("Numero de iteracoes: ", len(Vet_Er))

if len(Vet_Er) >= 99:
    print("O limite maximo de iteracoes foi atingido!")

plt.plot(iteracoes, Vet_Er)
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