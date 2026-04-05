import matplotlib.pyplot as plt
import math 
e = 0.01 #Inserir tolerancia aqui
cte_R = 1
cte_E = 2
cte_C = 0.5
cte_C2 = 0.5
def Function (x, y):
    return 5*x**2 + 3*x*y - y**2 + y**4 #Inserir funcao aqui

p1x = float(input("Informe o valor x1 do primeiro ponto"))
p1y = float(input("Informe o valor x2 do primeiro ponto"))
p2x = float(input("Informe o valor x1 do segundo ponto"))
p2y = float(input("Informe o valor x2 do segundo ponto"))
p3x = float(input("Informe o valor x1 do terceiro ponto"))
p3y = float(input("Informe o valor x2 do terceiro ponto"))

def Organization(p1x, p1y, p2x, p2y, p3x, p3y):
    if(Function(p1x, p1y)>=Function(p2x, p2y) and Function(p1x, p1y)>=Function(p3x, p3y)):
        xn = p1x
        yn = p1y
        if(Function(p2x, p2y)>=Function(p3x, p3y)):
            xs = p2x
            ys = p2y
            xl = p3x
            yl = p3y
        else: 
            xs = p3x
            ys = p3y
            xl = p2x
            yl = p2y
    elif(Function(p2x, p2y)>=Function(p1x, p1y) and Function(p2x, p2y)>=Function(p3x, p3y)):
        xn = p2x
        yn = p2y
        if(Function(p1x, p1y)>=Function(p3x, p3y)):
            xs = p1x
            ys = p1y
            xl = p3x
            yl = p3y
        else: 
            xs = p3x
            ys = p3y
            xl = p1x
            yl = p1y
    elif(Function(p3x, p3y)>=Function(p1x, p1y) and Function(p3x, p3y)>=Function(p2x, p2y)):
        xn = p3x
        yn = p3y
        if(Function(p1x, p1y)>=Function(p2x, p2y)):
            xs = p1x
            ys = p1y
            xl = p2x
            yl = p2y
        else: 
            xs = p2x
            ys = p2y
            xl = p1x
            yl = p1y
    return xl,yl, xs, ys, xn, yn

xl, yl, xs, ys, xn, yn = Organization(p1x, p1y, p2x, p2y, p3x, p3y)

ct = 0
iteracoes=[]
erros=[]
while (((xl - xn)**2 + (yl - yn)**2)**0.5 > e and ct < 1000):
    
    cx = (xs + xl)/2 #calculo do centroide
    cy = (ys + yl)/2

    xr = cx + cte_R * (cx - xn) #reflexao
    yr = cy + cte_R * (cy - yn)

    if(Function(xr, yr) <= Function(xl,yl)):
        
        xe = cx + cte_E*(xr - cx) #expansao
        ye = cy + cte_E*(yr - cy)
        
        if(Function(xe,ye)<Function(xr,yr)):
            xn = xe
            yn = ye
        else:
            xn = xr
            yn = yr
    elif(Function(xs, ys)<Function(xr, yr)):
        xc = cx + cte_C*(xr - cx) #contracao
        yc = cy + cte_C*(yr - cy)

        if(Function(xc, yc)<= Function(xr,yr) and Function(xc,yc)<Function(xn,yn)): 
            xn = xc
            yn = yc
        elif(Function(xr, yr) < Function(xn, yn)):
            xn = xr
            yn = yr
        else: 
            xs = xs + cte_C2*(xs - xl) #contracao encolhida
            ys = ys + cte_C2*(ys - yl) 
            xn = xn + cte_C2*(xn - xl)
            yn = yn + cte_C2*(yn - yl)
    else:
        xn = xr
        yn = yr
    ct+=1
    xl,yl, xs, ys, xn, yn = Organization(xl,yl, xs, ys, xn, yn)
    iteracoes.append(ct)
    erros.append(abs(Function(xn, yn) - Function(xl,yl)))
    print("ponto: (", xl,",",yl,") imagem: ", Function(xl, yl), " iteracao: ", ct, "erro: ",abs(Function(xn, yn) - Function(xl,yl)))

print("-------------------------------------------------------------------------------------------------------------------")

plt.plot(iteracoes, erros)
plt.title("Diminuicao do erro ao longo das iteracoes", fontsize=14, fontweight='bold', color='#4878E0')
plt.xlabel("Iteracoes", fontsize=14, fontweight='bold', color='#4878E0')
plt.ylabel("Erro", fontsize=12, fontweight='bold', color='#4878E0')
plt.grid(True, linestyle=':', color='gray', alpha=0.8, zorder=0)
plt.show()

