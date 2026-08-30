#8.8
import math
import matplotlib.pyplot as plt

from rk4 import Rk4

mi = 0.0385       # Parametro de massa (variar em 0.01, 0.0385, 0.04)

p1 = [-mi, 0] #posicao do corpo primario (Terra)
p2 = [1 - mi, 0] #posicao do corpo secundario (Lua)

h = 0.001      # Tamanho do passo
delta = 0.01    # Perturbacao aplicada nas condicoes iniciais

x0 = (1/2) - mi + delta
y0 = math.sqrt(3)/2

rk = Rk4(h, x0, y0, 0.0, 0.0, mi, 70*math.pi)
X = rk[1]
Y = rk[2]


fig, ax = plt.subplots()
ax.plot(X, Y, label="Trajetoria") 
ax.scatter(p1[0], p1[1], label = "P1")
ax.scatter(p2[0], p2[1], label = "P2")
ax.legend()
ax.set_title("Simulacao da Trajetoria")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid()
ax.set_aspect('equal')
plt.show()