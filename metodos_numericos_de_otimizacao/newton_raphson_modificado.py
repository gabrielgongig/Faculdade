#Feito por Gabriel Gonçalves Figueira e Paulo Emanuel de Araújo Pessanha
import math
import matplotlib.pyplot as plt

Y = []
X = []

h = 1e-5
def f(x, y):
    return (x-2)**4 + (x - 2*y)**2

def Derivada(x0, y0, option):
    if(option == 1):
        return ((f(x0+h, y0)-f(x0,y0))/h)
    elif (option == 2):
        return ((f(x0, y0+h)-f(x0,y0))/h)
    else:
        print("opcao de derivacao invalida")
        
def Derivada2(x0, y0, option):
    if(option == 1):
        return ((Derivada(x0+h, y0, 1)-Derivada(x0,y0,1))/h)
    elif(option == 2):
        return ((Derivada(x0, y0+h, 2)-Derivada(x0,y0,2))/h)
    elif(option == 3):
        return ((Derivada(x0, y0+h, 1)-Derivada(x0,y0,1))/h)
    elif(option == 4):
        return ((Derivada(x0+h, y0, 2)-Derivada(x0,y0,2))/h)
    else:
        print("Opcao de derivacao invalida")

def Gradiente(x, y):
    return [Derivada(x, y, 1), Derivada(x, y, 2)]

def Hessiana(x, y):
    return [Derivada2(x, y, 1), Derivada2(x, y, 3), Derivada2(x, y, 4), Derivada2(x, y, 2)]

def Inversa(M):#formula para inversa 2x2
    det = 1/(M[0]*M[3] - M[1]*M[2])
    return(M[3]*det, -M[1]*det, -M[2]*det, M[0]*det )
    
def NR2(x0, y0, e):
    x = x0+e+1
    y = y0+e+1
    i=0
    while (i<=1000):
        I = Inversa(Hessiana(x0,y0))
        G = Gradiente(x0,y0)

        x = x0 - (I[0]*G[0] + I[1]*G[1]) 
        y = y0 - (I[2]*G[0] + I[3]*G[1]) 

        erro = math.sqrt((x - x0)**2 + (y - y0)**2)

        print("\nIteracao: ", i, ": (",x,",",y,"), erro: ", erro)

        i+=1

        X.append(i)
        Y.append(erro)

        if(erro<e):
            break
        
        x0 = x
        y0 = y

    return x,y

x0 = float(input("Digite o valor de x1\n"))
y0 = float(input("Digite o valor de x2\n"))
er = float(input("Digite o valor para o erro\n"))

res = NR2(x0, y0, er)

print("\n\n-----------------------------------------------------------")
print("O resultado eh:",res)
print("-----------------------------------------------------------")

plt.plot(X, Y)
plt.title("Diminuicao do erro ao longo das iteracoes", fontsize=14, fontweight='bold', color='#4878E0')
plt.xlabel("Iteracoes", fontsize=14, fontweight='bold', color='#4878E0')
plt.ylabel("Erro", fontsize=12, fontweight='bold', color='#4878E0')
plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
plt.show()