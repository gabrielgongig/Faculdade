#8.4
import math
import matplotlib.pyplot as plt

from rk4 import Rk4

mi = 0.012150 #massa relativa
passe1 = 0.01
passe2 = 0.001 
passe3 = 0.0001 #passo do metodo determinado pelo usuario

i = 4
while i not in [1, 2, 3]:
    i = int(input("Digite o numero de periodos: ")) #numero de periodos determinado pelo usuario

t = 5.432*math.pi

rk1 = Rk4(passe1, 0.994, 0.0, 0.0, -2.011752, mi, i*t)
rk2 = Rk4(passe2, 0.994, 0.0, 0.0, -2.011752, mi, i*t)
rk3 = Rk4(passe3, 0.994, 0.0, 0.0, -2.011752, mi, i*t)

C1 = rk1[3] #integral de jacobi em cada iteracao
C2 = rk2[3] #integral de jacobi em cada iteracao
C3 = rk3[3] #integral de jacobi em cada iteracao

ci = C1[0] #valor inicial da integral de jacobi

error1 = abs((C1[-1] - ci)/ci) #erro relativo final da integral de jacobi
error2 = abs((C2[-1] - ci)/ci) #erro relativo final da integral de jacobi
error3 = abs((C3[-1] - ci)/ci) #erro relativo final da integral de jacobi

print("-----------------------------------------------")
print("O erro para ", i, "periodo(s) associado ao passo ",passe1," eh ", error1) # erro final
print("O erro para ", i, "periodo(s) associado ao passo ",passe2," eh ", error2) # erro final
print("O erro para ", i, "periodo(s) associado ao passo ",passe3," eh ", error3) # erro final
print("-----------------------------------------------")

E1 = []
E2 = []
E3 = []

T1 = []
T2 = []
T3 = []

for i in range(len(C1)):
    E1.append(abs((C1[i] - ci)/ci))  #erro relativo em cada iteracao
    T1.append(i*passe1)  #tempo em cada iteracao

for i in range(len(C2)):
    E2.append(abs((C2[i] - ci)/ci))  #erro relativo em cada iteracao
    T2.append(i*passe2)  #tempo em cada iteracao

for i in range(len(C3)):
    E3.append(abs((C3[i] - ci)/ci))  #erro relativo em cada iteracao
    T3.append(i*passe3)  #tempo em cada iteracao

fig, ax = plt.subplots() #geracao do grafico do erro relativo
ax.semilogy([t / math.pi for t in T1], E1, label="Erro associado ao passo " + str(passe1)) #a escala sublogaritmica eh utilizada para melhor visualizacao do grafico,
ax.semilogy([t / math.pi for t in T2], E2, label="Erro associado ao passo " + str(passe2)) #visto que os valores sao muito pequenos. Alem disso, o tempo eh normalizado
ax.semilogy([t / math.pi for t in T3], E3, label="Erro associado ao passo " + str(passe3)) #por pi para melhor visualizacao do grafico
ax.legend()                                                                               
ax.set_title("Erro relativo da integral de Jacobi")                                      
ax.set_xlabel("Tempo ($t/\\pi$)")                                                        
ax.set_ylabel("Erro Relativo")
ax.grid()
plt.show()