import math, sys, time, numpy, matplotlib.pyplot as plt

V=[]
A=[]

with open("entradas.txt", "r") as archive: #pega as entradas do arquivo
    text = archive.readlines()
    ct=0
    while text[ct]!="\n":
        try:
            float(text[ct])
            V.append(float(text[ct]))
            ct+=1
        except ValueError:
            print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO NO ARQUIVO E O PROGRAMA NAO PODE CONTINUAR")
            time.sleep(5)
            sys.exit(1)

    ct+=1
    while text[ct]!="FIM":
        try:
            float(text[ct])
            A.append(float(text[ct]))
            ct+=1
        except ValueError:
            print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO NO ARQUIVO E O PROGRAMA NAO PODE CONTINUAR")
            time.sleep(5)
            sys.exit(1)
            
    if(len(V)!=len(A)):
        print("FORAM INSERIDOS VALORES DE MANEIRA INCORRETA E O PROGRAMA NÃO PODE CONTINUAR")
        time.sleep(5)
        sys.exit(1)
    
N=len(V)
choice=7
R = (math.sqrt(5) - 1) / 2 #numero de ouro

def Prepare_LSM(lines):
    a=[]
    b=[]
    sum=0
    for i in range(0,lines,1): #define os vetores do mmq
        a.append([])
        if(i==0):
            a[i].append(N)
            for k in range(1,lines,1):
                for w in V:
                    sum+=w**k
                a[i].append(sum)
                sum=0
        else:
            for k in range(0,lines,1):
                for w in V:
                    sum+=w**(k+i)
                a[i].append(sum)
                sum=0
        sum_xy=0
        for j in range(N):
            sum_xy += (V[j])**i*A[j]
        b.append(sum_xy)
    return a,b
    
    
def Gaussian_Elimination(a, b, lines):
    for k in range(lines - 1):  
        for i in range(k + 1, lines):
            factor = a[i][k] / a[k][k]  
            for j in range(k,lines):
                a[i][j] -= factor * a[k][j]
            b[i] -= factor * b[k]
    return a, b

def Gauss_Retrosubstitution(a, b, lines):
    x = numpy.zeros(lines)  
    x[lines - 1] = b[lines - 1] / a[lines - 1][lines - 1]  
    for i in range(lines - 2, -1, -1):  
        soma = b[i]
        for j in range(i + 1, lines):
            soma -= a[i][j] * x[j]
        x[i] = soma / a[i][i]
    return x

def f(x, coefficients): # usado pra plotar os graficos
    return numpy.polyval(coefficients[::-1], x)

def Adjusted_Polynomial(x):
    return (27196.9897  -149.148578*x  + 0.345301019*x**2  -0.000359482547*x**3  + 0.000000146004111*x**4)

def Model(x):
    return ((0.01*0.6)*x**2 + (0.95/0.6)*(16000/x)**2)

def Polynomial_Error(coefficients, n):
    Sr = 0
    for i in range(0,n,1):
        inst_error=A[i]
        for j in range (0, len(coefficients),1):
            inst_error-=coefficients[j]*V[i]**j
        Sr+=inst_error**2
    return Sr

def Model_Error(n):
    Sr=0
    for i in range(0,n,1):
        Sr+=(A[i] - (Model(V[i])))**2
    return Sr

def BetweenFunctions_Error(n,function1, function2):
    sr = 0
    for i in range(0, n, 1):
        sr+=(function1(V[i]) - function2(V[i]))**2
    return sr

def Golden_Section(f,a,b,e):

    x1 = b - R * (b - a)
    x2 = a + R * (b - a)

    f1 = f(x1)
    f2 = f(x2)

    while abs(b-a) > e:
        if f1 > f2:
            a = x1
            x1 = x2
            f1 = f2
            x2 = a + R * (b - a)
            f2 = f(x2)
        else:
            b = x2
            x2 = x1
            f2 = f1
            x1 = b - R * (b - a)
            f1 = f(x1)

    x_min = (a + b) / 2
    f_min = f(x_min)
    return x_min, f_min




while(choice!=0):
    choice = (input("O que você quer fazer?\n0 - Sair\n1 - Calcular o método dos mínimos quadrados para os pontos presentes\n2 - Verificar o arrasto mínimo associado à função ajustada de quarto grau e à função dada\n3 - Ver o gráfico da função ajustada de quarto grau e da função dada\n4 - Calcular o erro quadrado da função ajustada de quarto grau e da função dada\n5 - Calcular o desvio quadratico da função ajustada de grau 4 em relação a função modelo\n\n"))
   
    while(choice!="0" and choice!="1" and choice!="2" and choice!="3" and choice!="4" and choice!="5" ):
        print("ENTRADA INVALIDA")
        choice = input("O que você quer fazer?\n0 - Sair\n1 - Calcular o método dos mínimos quadrados para os pontos presentes\n2 - Verificar o arrasto mínimo associado à função ajustada de quarto grau e à função dada\n3 - Ver o gráfico da função ajustada de quarto grau e da função dada\n4 - Calcular o erro quadrado da função ajustada de quarto grau e da função dada\n5 - Calcular o desvio quadratico da função ajustada de grau 4 em relação a função modelo\n\n")
    choice = int(choice)

    match(choice):
        
        case 0:
            break

        case 1:
            while True:
                degree = input("\nQual grau você quer o ajuste? ")
                beginning = input("Qual o ponto de inicio do grafico? ")
                ending = input("Qual o ponto final do grafico? ")
                try:  #verifica se os valores escolhidos são coerentes
                    float(beginning)
                    float(ending)
                    int(degree)
                    if float(ending)>float(beginning):
                        break
                    else:
                        print("Voce escolheu algum valor invalido. Por favor tente de novo")
                except:
                    print("Voce escolheu algum valor invalido. Por favor tente de novo")
                    
            lines = int(degree)+1
            
            a,b = Prepare_LSM(lines)
            [a,b] = Gaussian_Elimination(a,b,lines)
            coefs = Gauss_Retrosubstitution(a,b,lines)

            print("--------------------------------------------")
            for i in range(0,len(coefs),1):
                print("a",i," =",coefs[i])
            print("\nErro Quadrado: ",Polynomial_Error(coefs, N))
            print("--------------------------------------------\n")


            plt.figure(figsize=(10, 5))

            plt.title("Gráfico arrasto total x velocidade",fontsize=14, fontweight='bold', color='#4878E0')
            plt.xlabel("Velocidade",fontsize=14, fontweight='bold', color='#4878E0')
            plt.ylabel("Arrasto total do aerofólio",fontsize=12, fontweight='bold', color='#4878E0')
            
            Xgraf = numpy.linspace(float(beginning),float(ending))
            Ygraf = f(Xgraf, coefs)

            plt.plot(Xgraf,Ygraf, label="Polinomio de grau {}".format(degree))
            plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
            plt.legend(loc='upper right', fontsize=9)
            
            plt.show()

        case 2:
            print("--------------------------------------------")
            print("Polinomio de grau 4:\n")
            x_min, f_min = Golden_Section(Adjusted_Polynomial, 0, 1000, 1e-5)
            print(f"Ponto de mínimo: v = {x_min} m/s")
            print(f"Valor mínimo: D(v) = {f_min} N\n\n")

            x_min, f_min = Golden_Section(Model, 0, 1000, 1e-5)
            print("Função modelo:\n")
            print(f"Ponto de mínimo: v = {x_min} m/s")
            print(f"Valor mínimo: A(v) = {f_min} N")
            print("--------------------------------------------")
        case 3:
            while True:
                beginning = input("Qual o ponto de inicio do grafico? ")
                ending = input("Qual o ponto final do grafico? ")
                try:  #verifica se os valores escolhidos são coerentes
                    float(beginning)
                    float(ending)
                    if float(ending)>float(beginning):
                        break
                    else:
                        print("Voce escolheu algum valor invalido. Por favor tente de novo")
                except:
                    print("Voce escolheu algum valor invalido. Por favor tente de novo")

            plt.figure(figsize=(10, 5))

            plt.title("Gráfico arrasto total x velocidade",fontsize=14, fontweight='bold', color='#4878E0')
            plt.xlabel("Velocidade",fontsize=14, fontweight='bold', color='#4878E0')
            plt.ylabel("Arrasto total do aerofólio",fontsize=12, fontweight='bold', color='#4878E0')

            Xgraf = numpy.linspace(float(beginning),float(ending))
            Ygraf1 = Adjusted_Polynomial(Xgraf)
            Ygraf2 = Model(Xgraf)

            plt.plot(Xgraf,Ygraf1, label='Polinomio de grau 4')
            plt.plot(Xgraf,Ygraf2, label='Funcao modelo')

            if(float(ending)>=509.4698449365602 and float(beginning)<=509.4698449365602):
                plt.axvline(x=509.4698449365602, color="yellow",linestyle='--', label="Velocidade otima da funcao de grau 4")
            if(float(ending)>=509.818116929815 and float(beginning)<=509.818116929815):
                plt.axvline(x=509.818116929815, color="red",linestyle='--', label="Velocidade otima da funcao modelo")
            
            plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
            plt.legend(loc='upper right', fontsize=9)

            plt.show()
        case 4:
            print("--------------------------------------------")
            print("Erro do polinômio de grau 4: ",Polynomial_Error( [27196.9897, -149.148578, 0.345301019, -0.000359482547, 0.000000146004111], N))
            print("Erro da função dada: ", Model_Error(N))
            print("--------------------------------------------\n")
        case 5:
            print("--------------------------------------------")
            print("Desvio: ", BetweenFunctions_Error(N, Adjusted_Polynomial, Model))
            print("--------------------------------------------\n")