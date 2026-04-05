# main.py
import MetEuler as me
import MetRungeKutta as mrk
import ErroP as dv
import math
import numpy as np
import matplotlib.pyplot as plt

# Parametros do problema
y0 = 1000  # Valor inicial N(0)
L = 2.7     # Taxa de decaimento
P = 20      # Constante de producao
t = 0       # Tempo inicial
tf = 5      # Tempo final
h = 1       # Passo de tempo

def f(N):  # Solucao analitica N(t)
    N = np.array(N)
    return (20 + 2680 * np.exp(-L * N)) / L

def dN(N):  # Taxa de variacao de nucleos radioativos dN/dt
    return -L * N + P

# Geracao dos eixos para os graficos comparativos
Va = np.linspace(0, 5, 51)
Vx = np.linspace(0, 5, int(tf / h) + 1)
Vy = f(Va)

Vy_RK = mrk.RK(dN, h, y0, t, tf)
Vy_Euler = me.Euler(dN, h, y0, t, tf)

Vy_Euler_interp = np.interp(Va, Vx, Vy_Euler)
Vy_RK_interp = np.interp(Va, Vx, Vy_RK)

print(f"Tabela de desvios percentuais de Runge-Kutta com passo h = {h}")
dv.DesvioPercentual(Vy, Vy_RK, h, tf)

print(f"Tabela de desvios percentuais de Euler com passo h = {h}")
dv.DesvioPercentual(Vy, Vy_Euler, h, tf)

# Plotagem dos graficos comparativos
plt.plot(Va, Vy, label='Solucao Analitica', color="#FFF700")
plt.plot(Va, Vy_RK_interp, label=f'Metodo de Runge-Kutta com h = {h}',
         color="#0D00FF", linestyle='--')
plt.plot(Va, Vy_Euler_interp, label=f'Metodo de Euler com h = {h}',
         color="#3A9A70", linestyle='--')

plt.title("Comparacao entre as solucoes", fontsize=14, fontweight='bold',
          color="#4878E0")
plt.xlabel("t", fontsize=14, fontweight='bold', color="#000000")
plt.ylabel("N(t)", fontsize=12, fontweight='bold', color="#000000")

plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
plt.legend(fontsize=10, loc='upper right')

plt.show()