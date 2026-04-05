import math
import sys
import time

repetir = 1
while (repetir==1):
    supsigma=0
    som_xy=0
    X=[]
    Y=[]
    IY=[]
    x=2
    teste=""
    perguntaARQ=""
    while (teste!="S" and teste!="N"):
        teste = input("a sua função tem tendencia linear?. Digite S para sim ou N para não")
        teste = teste.upper()
        if (teste!="S" and teste!="N"):
            print("INVALIDO")

    if(teste=="N"):
        testeyEXP = input("Qual o expoente de y?")
        try:
            float(testeyEXP)
        except ValueError:
            print("O VALOR QUE VOCÊ INSERIU É INVALIDO E O PROGRAMA NAO PODE CONTINUAR")
            time.sleep(5)
            sys.exit(1)

        testeyCOEF = input("Qual o coeficiente angular de Y?")
        try:
            float(testeyCOEF)
        except ValueError:
            print("O VALOR QUE VOCÊ INSERIU É INVALIDO E O PROGRAMA NAO PODE CONTINUAR")
            time.sleep(5)
            sys.exit(1)

    while (perguntaARQ!="A" and perguntaARQ!="M"):
        perguntaARQ = input("Deseja inserir as entradas manualmente (insira M) ou utilizar o arquivo (insira A)?")
        perguntaARQ = perguntaARQ.upper()
        if (perguntaARQ!="A" and perguntaARQ!="M"):
            print("INVALIDO")

    if(perguntaARQ=="A"):
        with open("entradas.txt", "r") as arquivo:
            texto = arquivo.readlines()
            ct=0
            while texto[ct]!="\n":
                try:
                    float(texto[ct])
                except ValueError:
                    print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO NO ARQUIVO E O PROGRAMA NAO PODE CONTINUAR")
                    time.sleep(5)
                    sys.exit(1)
                if(teste == "S"):
                    X.append(float(texto[ct]))
                elif(teste=="N"):
                    X.append(math.log(float(texto[ct])))
                ct+=1
            ct+=1
            while texto[ct]!="\n":
                try:
                    float(texto[ct])
                except ValueError:
                    print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO NO ARQUIVO E O PROGRAMA NAO PODE CONTINUAR")
                    time.sleep(5)
                    sys.exit(1)
                if(teste == "S"):
                    Y.append(float(texto[ct]))
                elif(teste=="N"):
                    Y.append(math.log(float(testeyCOEF)*((float(texto[ct])) **float(testeyEXP))))
                ct+=1
            ct+=1
            while texto[ct]!="FIM":
                try:
                    float(texto[ct])
                except ValueError:
                    print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO NO ARQUIVO E O PROGRAMA NAO PODE CONTINUAR")
                    time.sleep(5)
                    sys.exit(1)
                IY.append(float(texto[ct]))
                ct+=1

    elif (perguntaARQ=="M"):
        while x!= 'P' and x!="p":
            x=input("Escreva uma coordenada x (ou digite P para parar)")
            if x!='P':
                try:
                    float(x)
                except ValueError:
                    print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO E O PROGRAMA NAO PODE CONTINUAR")
                    time.sleep(5)
                    sys.exit(1)
                if(teste == "S"):
                    X.append(float(x))
                elif(teste=="N"):
                    X.append(math.log(float(x)))
            
                y=input("Escreva uma coordenada y")
                try:
                    float(y)
                except ValueError:
                    print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO E O PROGRAMA NAO PODE CONTINUAR")
                    time.sleep(5)
                    sys.exit(1)
                if(teste == "S"):
                    Y.append(float(y))
                elif(teste=="N"):
                    Y.append(math.log(float(testeyCOEF)*((float(y)) **float(testeyEXP))))

                iy=input("Escreva uma incerteza para sua coordenada y")
                try:
                    float(iy)
                except ValueError:
                    print("FOI LIDO UM VALOR DIFERENTE DO ESPERADO E O PROGRAMA NAO PODE CONTINUAR")
                    time.sleep(5)
                    sys.exit(1)
                IY.append(float(iy))

    if(len(X)!=len(Y) or len(X)!=len(IY) or len(Y)!=len(IY)):
        print("A QUANTIDADE DE VALORES NAO BATE E O PROGRAMA NAO PODE CONTINUAR")
        time.sleep(5)
        sys.exit(1)
    elif(len(X)<=2):
        print("A QUANTIDADE DE VALORES DEVERIA SER MAIOR DO QUE 2 E POR ISSO O PROGRAMA NAO PODE CONTINUAR")
        time.sleep(5)
        sys.exit(1)

    N=len(X)
    som_x=sum(X)
    som_y=sum(Y)
    som_x2=sum(map(lambda i:i**2, X))
    D=N*som_x2 - som_x**2
    if D == 0:
        print("ERRO DE DIVISAO POR ZERO. POR FAVOR, VERIFIQUE SEUS DADOS DE ENTRADA")
        time.sleep(5)
        sys.exit(1)
    for i in range(N):
        som_xy += X[i]*Y[i]

    a = (som_x2*som_y - som_x*som_xy)/D
    b = (N*som_xy - som_x*som_y)/D

    for i in range(N):
        supsigma+=(Y[i]-a-b*X[i])**2

    sigmaQ = (1/(N-2))*supsigma


    ERROa = math.sqrt((som_x2*sigmaQ)/D)
    ERROb = math.sqrt((N*sigmaQ)/D)

    #segunda parte 

    mediaY = som_y/N
    numR2 = 0
    denR2 = 0
    chi2=0
    for i in range(N):
        numR2+=(a + b*X[i] - mediaY)**2
        denR2+=(Y[i]-mediaY)**2
        chi2+=((Y[i]-a-b*X[i])/(IY[i]))**2

    R2 = numR2/denR2



    print("a: ",a,"\n","b: ",b,"\n","chi^2: ",round(chi2,4),"\n","R^2: ", round(R2,4),"\n","incerteza de a: ", ERROa, "\nincerteza de b: ", ERROb) 
    sair=input("\n Deseja calcular novamente? Digite R para sim ou qualquer outra tecla para fechar o programa")
    sair = sair.upper()
    if(sair!="R"):
        repetir=0


