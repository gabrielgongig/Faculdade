#8.7
import math
import matplotlib.pyplot as plt

from rk4 import Rk4

mi = 0.012150 #massa relativa

epsilon = 1e-6    # Perturbação aplicada nas condições iniciais
epsilon2 = 1e-5 
epsilon3 = 1e-4 
epsilon4 = 1e-3 

#v0 = -2.011752
#x0 = 0.994

x01 = 0.994 + epsilon
x02 = 0.994 + epsilon2
x03 = 0.994 + epsilon3  #deixa comentado o que nao sera utilizado
x04 = 0.994 + epsilon4

v01 = -2.011752 + epsilon
v02 = -2.011752 + epsilon2  
v03 = -2.011752 + epsilon3
v04 = -2.011752 + epsilon4

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


rk1 = Rk4(0.0001, x01, 0.0, 0.0, v01, mi, 44*math.pi)
rk2 = Rk4(0.0001, x02, 0.0, 0.0, v02, mi, 44*math.pi) #pode trocar para 44*math.pi para ver sobre um dominio maior
rk3 = Rk4(0.0001, x03, 0.0, 0.0, v03, mi, 44*math.pi)
rk4 = Rk4(0.0001, x04, 0.0, 0.0, v04, mi, 44*math.pi)

# Calculando as seções de Poincare para cada um
X_intersec1, U_intersec1 = secao_de_poincare(rk1)
X_intersec2, U_intersec2 = secao_de_poincare(rk2)
X_intersec3, U_intersec3 = secao_de_poincare(rk3)
X_intersec4, U_intersec4 = secao_de_poincare(rk4)


fig, ax = plt.subplots(1, 2, figsize=(12, 6))

#epsilon (10^-6)

ax[0].plot(X_intersec1, U_intersec1, '.', markersize=4, color='blue')
ax[0].set_title("Poincare (eps = 10^-6)")
ax[0].set_xlabel("x")
ax[0].set_ylabel("u")
ax[0].grid()

ax[1].plot(rk1[1], rk1[2], color='red', linewidth=0.5)
ax[1].set_title("Trajetoria (eps = 10^-6)")
ax[1].set_xlabel("x")
ax[1].set_ylabel("y")
ax[1].set_aspect('equal')
ax[1].grid()

plt.tight_layout()
plt.show()

fig, ax2 = plt.subplots(1, 2, figsize=(12, 6))
#epsilon2 (10^-5)

ax2[0].plot(X_intersec2, U_intersec2, '.', markersize=4, color='blue')
ax2[0].set_title("Poincare (eps = 10^-5)")
ax2[0].set_xlabel("x")
ax2[0].set_ylabel("u")
ax2[0].grid()

ax2[1].plot(rk2[1], rk2[2], color='red', linewidth=0.5)
ax2[1].set_title("Trajetoria (eps = 10^-5)")
ax2[1].set_xlabel("x")
ax2[1].set_ylabel("y")
ax2[1].set_aspect('equal')
ax2[1].grid()

plt.tight_layout()
plt.show()

fig, ax3 = plt.subplots(1, 2, figsize=(12, 6))
# epsilon3 (10^-4)
ax3[0].plot(X_intersec3, U_intersec3, '.', markersize=4, color='blue')
ax3[0].set_title("Poincare (eps = 10^-4)")
ax3[0].set_xlabel("x")
ax3[0].set_ylabel("u")
ax3[0].grid()

ax3[1].plot(rk3[1], rk3[2], color='red', linewidth=0.5)
ax3[1].set_title("Trajetoria (eps = 10^-4)")
ax3[1].set_xlabel("x")
ax3[1].set_ylabel("y")
ax3[1].set_aspect('equal')
ax3[1].grid()

plt.tight_layout()
plt.show()
fig, ax4 = plt.subplots(1, 2, figsize=(12, 6))
#epsilon4 (10^-3)

ax4[0].plot(X_intersec4, U_intersec4, '.', markersize=4, color='blue')
ax4[0].set_title("Poincare (eps = 10^-3)")
ax4[0].set_xlabel("x")
ax4[0].set_ylabel("u")
ax4[0].grid()

ax4[1].plot(rk4[1], rk4[2], color='red', linewidth=0.5)
ax4[1].set_title("Trajetoria (eps = 10^-3)")
ax4[1].set_xlabel("x")
ax4[1].set_ylabel("y")
ax4[1].set_aspect('equal')
ax4[1].grid()

plt.tight_layout()
plt.show()
