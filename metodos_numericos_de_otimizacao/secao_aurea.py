import math, matplotlib.pyplot as plt

R = (math.sqrt(5) - 1) / 2 #numero de ouro
e = 0.1 #erro

def f(x, coefs): #funcao polinomial
    result = 0
    for i in range(len(coefs)):
        result += coefs[i] * math.pow(x, i)
    return result

def f2(x):
    return (math.sin(x))**2 +1 # ALTERAR AQUI PARA A FUNCAO QUE QUISER

def Golden_Section(xh,xl, option, coefs=None):
    x1 = xh - R*(xh-xl)
    x2 = xl + R*(xh-xl)
    x1_x2 = []

    if option == 0:
        while abs(x1 - x2)>e and len(x1_x2)<=100:

            if f(x1, coefs) > f(x2, coefs):
                xl = x1
            else: 
                xh = x2

            x1_x2.append(abs(x1 - x2))
            x1 = xh - R*(xh-xl)
            x2 = xl + R*(xh-xl) 
        x1_x2.append(abs(x1 - x2))
        return (x1 + x2)/2, x1_x2

    elif option ==1:
        while abs(x1 - x2)>e and len(x1_x2)<=100:

            if f2(x1) > f2(x2):
                xl = x1
            else: 
                xh = x2

            x1_x2.append(abs(x1 - x2))
            x1 = xh - R*(xh-xl)
            x2 = xl + R*(xh-xl) 
        x1_x2.append(abs(x1 - x2))
        return (x1 + x2)/2, x1_x2

    

option = 2
while(option!=0 and option !=1):
    option = int(input("Digite 0 para calcular o ponto minimo de uma funcao polinomial ou 1 para uma funcao especifica"))

a = float(input("Digite o valor para xh "))
b = float(input("Digite o valor para xl ")) 
if option == 0:

    grau = int(input("Este programa soh funciona para funcoes polinomiais. Qual o grau da sua funcao? "))
    coefs = []
    for i in range(grau + 1):
        coefs.append(float(input(f"Digite o valor do coeficiente do termo de expoente {i}: "))) 
    resp, x1_x2 =  Golden_Section(a, b, option, coefs)

elif option == 1:
    resp, x1_x2 =  Golden_Section(a, b, option)

#teste
#print("x1-x2: \n", x1_x2)
#print("iteracoes: \n", iteracoes)
#print("coefs: \n", coefs)

iteracoes = []
for i in range(len(x1_x2)):
    iteracoes.append(i+1)
print("O resultado eh \n", resp)
print("a imagem do resultado eh \n",f(resp, coefs) if option == 0 else f2(resp))

plt.plot(iteracoes, x1_x2)           
plt.title("Diminuicao do erro ao longo das iteracoes",fontsize=14, fontweight='bold', color='#4878E0')   
plt.xlabel("Iteracoes",fontsize=14, fontweight='bold', color='#4878E0')     
plt.ylabel("Erro",fontsize=12, fontweight='bold', color='#4878E0')     
plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
plt.show() 