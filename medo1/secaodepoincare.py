#8.6
import math
import matplotlib.pyplot as plt

from rk4 import Rk4

mi = 0.012150 #massa relativa

p1 = [-mi, 0] #posicao do corpo primario (Terra)
p2 = [1 - mi, 0] #posicao do corpo secundario (Lua)

h = 0.0001      # Tamanho do passo

rk = Rk4(h, 0.994, 0.0, 0.0, -2.011752, mi, 44*math.pi)

def secao_de_poincare(rk):
    X = rk[1]
    Y = rk[2]
    U = rk[4]
    V = rk[5]

    X_intersec = []
    U_intersec = []
    
    for i in range(len(rk[1])-1):
        if (Y[i] < 0 and Y[i+1] >= 0) and V[i] > 0:
            X_intersec.append(X[i])
            U_intersec.append(U[i])

    return X_intersec, U_intersec

X_intersec, U_intersec = secao_de_poincare(rk)

qtd_pts = len(X_intersec)
print("Quantidade de pontos de intersecao na secao de Poincare:", qtd_pts)

fig, ax = plt.subplots(1, 2, figsize=(12, 6))

ax[0].plot(X_intersec, U_intersec, 'o', label="Pontos de Intersecao", markersize=4, color='blue')
ax[0].legend()
ax[0].set_title("Secao de Poincare")
ax[0].set_xlabel("x")
ax[0].set_ylabel("u")
ax[0].set_aspect('equal')
ax[0].grid()

ax[1].plot(rk[1], rk[2], label="Trajetoria", color='red', linewidth=0.5)
ax[1].legend()
ax[1].set_title("Simulacao da Trajetoria")
ax[1].set_xlabel("x")
ax[1].set_ylabel("y")
ax[1].grid()
ax[1].set_aspect("equal")

plt.tight_layout()
plt.show()