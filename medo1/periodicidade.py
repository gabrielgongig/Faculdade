#8.5
import math
import matplotlib.pyplot as plt

from rk4 import Rk4

mi = 0.012150 #massa relativa

p1 = [-mi, 0] #posicao do corpo primario (Terra)
p2 = [1 - mi, 0] #posicao do corpo secundario (Lua)
passe = float(input("Digite o passo de integracao: ")) #passo do metodo determinado pelo usuario

Tf = 5.432*math.pi #um periodo da órbita de Arenstorf

rk0= Rk4(passe, 0.994, 0.0, 0.0, -2.011752, mi, Tf) #simulacao para um periodo
x,y,u,v = rk0[0]
rk1= Rk4(passe, 0.994, 0.0, 0.0, -2.011752, mi, Tf*2) #simulacao para dois periodos
x2,y2,u2,v2 = rk1[0]
rk2= Rk4(passe, 0.994, 0.0, 0.0, -2.011752, mi, Tf*3)
x3,y3,u3,v3 = rk2[0]

print("---------------------------------\n")
print("Resultado final para um periodo:\n")
print("x = ", x, "\n")
print("y = ", y, "\n")
print("u = ", u, "\n")
print("v = ", v, "\n")
print("---------------------------------\n\n")
print("---------------------------------\n")
print("Resultado final para dois periodos:\n")
print("x = ", x2, "\n")
print("y = ", y2, "\n")
print("u = ", u2, "\n")
print("v = ", v2, "\n")
print("---------------------------------\n\n")
print("---------------------------------\n")
print("Resultado final para três periodos:\n")
print("x = ", x3, "\n")
print("y = ", y3, "\n")
print("u = ", u3, "\n")
print("v = ", v3, "\n")
print("---------------------------------\n\n")

X = rk0[1]
Y = rk0[2]
X1 = rk1[1]
Y1 = rk1[2]
X2 = rk2[1]
Y2 = rk2[2] #geracao do grafico da trajetoria para um, dois e três periodos

fig, ax = plt.subplots()
ax.plot(X2,Y2, label="três periodos")
ax.plot(X1,Y1, label="dois periodos")
ax.plot(X,Y, label="um periodo")
ax.scatter(p1[0], p1[1], label = "P1")
ax.scatter(p2[0], p2[1], label = "P2")
ax.legend()
ax.set_title("Simulacao da Trajetoria")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid()
ax.set_aspect('equal')
plt.show()