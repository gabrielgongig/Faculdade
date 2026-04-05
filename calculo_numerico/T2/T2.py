import math, sys, time, numpy

X = []
Y = []

with open("entradas.txt", "r") as archive:
    text = archive.readlines()
    ct = 0
    while text[ct] != "\n":
        try:
            X.append(float(text[ct]))
            ct += 1
        except ValueError:
            print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO NO ARQUIVO E O PROGRAMA NAO PODE CONTINUAR")
            time.sleep(5)
            sys.exit(1)

    ct += 1
    while text[ct] != "FIM":
        try:
            Y.append(float(text[ct]))
            ct += 1
        except ValueError:
            print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO NO ARQUIVO E O PROGRAMA NAO PODE CONTINUAR")
            time.sleep(5)
            sys.exit(1)

    if len(X) != len(Y):
        print("FORAM INSERIDOS VALORES DE MANEIRA INCORRETA E O PROGRAMA NÃO PODE CONTINUAR")
        time.sleep(5)
        sys.exit(1)

N = len(X)
choice = 7

def f_integracao(a, coefs):
    return sum(coefs[i] * a**i for i in range(len(coefs)))

def Simpson_1_3(coefs, a, b):
    m = (a + b) / 2.0
    h = (b - a) / 2.0
    return (h / 3.0) * (f_integracao(a, coefs) + 4 * f_integracao(m, coefs) + f_integracao(b, coefs))

def Prepare_LSM(lines):
    a, b = [], []
    for i in range(lines):
        row = []
        for k in range(lines):
            row.append(sum(w**(k+i) for w in X))
        a.append(row)
        b.append(sum((X[j]**i) * Y[j] for j in range(N)))
    return a, b

def Gaussian_Elimination(a, b, lines):
    for k in range(lines - 1):
        for i in range(k + 1, lines):
            factor = a[i][k] / a[k][k]
            for j in range(k, lines):
                a[i][j] -= factor * a[k][j]
            b[i] -= factor * b[k]
    return a, b

def Gauss_Retrosubstitution(a, b, lines):
    x = numpy.zeros(lines)
    x[lines - 1] = b[lines - 1] / a[lines - 1][lines - 1]
    for i in range(lines - 2, -1, -1):
        soma = b[i] - sum(a[i][j] * x[j] for j in range(i + 1, lines))
        x[i] = soma / a[i][i]
    return x

def Polynomial_Error(coefficients, n):
    return sum(abs(Y[i] - sum(coefficients[j] * X[i]**j for j in range(len(coefficients)))) for i in range(n))

def f(a, coefs, grau):
    return sum(coefs[i] * a**i for i in range(grau + 1))

def Simple_Trapezoidal(coefs, a, b, grau):
    return ((b - a) / 2) * (f(a, coefs, grau) + f(b, coefs, grau))

def Lagrange_Interpol(x):
    resp = 0
    for i in range(N):
        L = 1
        for j in range(N):
            if i != j:
                L *= (x - X[j]) / (X[i] - X[j])
        resp += Y[i] * L
    return resp

while choice != 0:
    choice = input("O que você quer fazer?\n0 - Sair\n1 - método dos mínimos quadrados\n2 - regra do trapézio\n3 - lagrange\n4 - 1/3 de simpson\n\n")

    while choice not in ["0", "1", "2", "3", "4"]:
        print("ENTRADA INVALIDA")
        choice = input("O que você quer fazer?\n0 - Sair\n1 - método dos mínimos quadrados\n2 - regra do trapézio\n3 - lagrange\n4 - 1/3 de simpson\n\n")
    choice = int(choice)

    match choice:
        case 0:
            break

        case 1:
            while True:
                degree = input("\nQual grau você quer o ajuste? ")
                x = input("\nPara qual valor de x você quer resolver? ")
                try:
                    degree = int(degree)
                    x = float(x)
                    break
                except:
                    print("Você escolheu algum valor inválido.")
            lines = degree + 1
            a, b = Prepare_LSM(lines)
            a, b = Gaussian_Elimination(a, b, lines)
            coefs = Gauss_Retrosubstitution(a, b, lines)
            result = sum(coefs[i] * x**i for i in range(len(coefs)))
            print("--------------------------------------------")
            for i in range(len(coefs)):
                print(f"a{i} = {coefs[i]}")
            print("\nResultado:", result)
            print("Erro:", Polynomial_Error(coefs, N))
            print("--------------------------------------------\n")
            

        case 2:
            while True:
                grau = input("\nDigite o grau do polinômio: ")
                a = input("\nDigite o limite de integração inferior: ")
                b = input("\nDigite o limite de integração superior: ")
                try:
                    grau = int(grau)
                    a = float(a)
                    b = float(b)
                    break
                except:
                    print("Você escolheu algum valor inválido.")
            coefs = []
            for i in range(grau + 1):
                s = float(input(f"Digite o coeficiente {i}: "))
                coefs.append(s)
            print("\nResultado:", Simple_Trapezoidal(coefs, a, b, grau))
            

        case 3:
            while True:
                x = input("\nPara qual valor de x você quer resolver? ")
                try:
                    x = float(x)
                    break
                except:
                    print("Você escolheu um valor inválido.")
            result = Lagrange_Interpol(x)
            print("O resultado é:", result)
            

        case 4:
            while True:
                grau = input("\nDigite o grau do polinômio: ")
                a = input("\nDigite o limite de integração inferior: ")
                b = input("\nDigite o limite de integração superior: ")
                try:
                    grau = int(grau)
                    a = float(a)
                    b = float(b)
                    break
                except:
                    print("Você escolheu algum valor inválido.")
            coefs = []
            for i in range(grau + 1):
                s = float(input(f"Digite o coeficiente {i}: "))
                coefs.append(s)
            print("\nResultado:", Simpson_1_3(coefs, a, b))
            
