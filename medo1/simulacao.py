#8.3
import math
import matplotlib.pyplot as plt

from rk4 import Rk4

mi = 0.012150 #massa relativa
passe = float(input("Digite o passo de integração: ")) #passo do metodo determinado pelo usuario

rk = Rk4(passe, 0.994, 0.0, 0.0, -2.011752, mi, 5.432*math.pi) #valores iniciais para obtencao da orbita de Arenstorf
result = rk[0]
X = rk[1]
Y = rk[2]

p1 = [-mi, 0] #posicao do corpo primario (Terra)
p2 = [1 - mi, 0] #posicao do corpo secundario (Lua)

print("---------------------------------\n")
print("Resultado final:\n")
print("x = ", result[0], "\n")
print("y = ", result[1], "\n") #valores finais de x, y, u e v apos a simulacao
print("u = ", result[2], "\n")
print("v = ", result[3], "\n")
print("---------------------------------\n")


fig, ax = plt.subplots()
ax.plot(X,Y, label="Trajetoria") 
ax.scatter(p1[0], p1[1], label = "P1")
ax.scatter(p2[0], p2[1], label = "P2")
ax.legend()
ax.set_title("Simulacao da Trajetoria") #geracao do grafico da trajetoria
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid()
ax.set_aspect('equal')
plt.show()

