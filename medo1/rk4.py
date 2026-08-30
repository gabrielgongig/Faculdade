#8.2
import math

def Du (x, v, mi, r1, r2): #calculo de du/dt
    return 2*v + x - ((1 - mi) * (x + mi))/r1**3 - (mi*(x-1+mi))/r2**3

def Dv (y, u, mi, r1, r2): #calculo de dv/dt
    return -2*u + y - ((1-mi)*y)/r1**3 - (mi*y)/r2**3



def Rk4(passe, x0, y0, u0, v0, mi, Tf):
      w = [x0, y0, u0, v0] #vetor inicial

      X = [w[0]]
      Y = [w[1]] #eixos x e y do grafico
      U = [w[2]]
      V = [w[3]] #eixos u e v do grafico

      r1 = math.sqrt((w[0] + mi)**2 + w[1]**2)   
      r2 = math.sqrt((w[0] -1 + mi)**2 + w[1]**2) #r1 e r2 (equacao 6 do pdf)

      C = [x0**2 + y0**2 + (2*(1 - mi))/r1 + (2*mi)/r2 - (u0**2 + v0**2)] #integral de jacobiano (equacao 7 do pdf)

      it = round(Tf/passe) #define o numero de iteracoes do metodo

      for i in range(it):

            r1 = math.sqrt((w[0] + mi)**2 + w[1]**2)  
            r2 = math.sqrt((w[0] -1 + mi)**2 + w[1]**2)

            dx = w[2]                            
            dy = w[3]                            
            du = Du(w[0], w[3], mi, r1, r2)        #sistema do problema terra lua (equacoes 21 a 24 do pdf)
            dv = Dv(w[1], w[2], mi, r1, r2)        

            k1 = [dx, dy, du, dv]    #k1 de rk4
            
            r1 = math.sqrt(((w[0] + 0.5*k1[0]*passe) + mi)**2 + (w[1] + 0.5*k1[1]*passe)**2)
            r2 = math.sqrt(((w[0] + 0.5*k1[0]*passe) - 1 + mi)**2 + (w[1] + 0.5*k1[1]*passe)**2) #atualizacao de r1 e r2 para o calculo de k2

            k2 = [w[2] + 0.5*k1[2]*passe,
                  w[3] + 0.5*k1[3]*passe,    #k2 de rk4
                  Du(w[0] + 0.5*k1[0]*passe, w[3] + 0.5*k1[3]*passe, mi, r1, r2 ), 
                  Dv(w[1] + 0.5*k1[1]*passe, w[2] + 0.5*k1[2]*passe, mi, r1, r2 ) 
                  ]
            
            r1 = math.sqrt(((w[0] + 0.5*k2[0]*passe) + mi)**2 + (w[1] + 0.5*k2[1]*passe)**2)
            r2 = math.sqrt(((w[0] + 0.5*k2[0]*passe) - 1 + mi)**2 + (w[1] + 0.5*k2[1]*passe)**2)
              
            k3 = [w[2] + 0.5*k2[2]*passe, 
                  w[3] + 0.5*k2[3]*passe,    #k3 de rk4
                  Du(w[0] + 0.5*k2[0]*passe, w[3] + 0.5*k2[3]*passe, mi, r1, r2 ), 
                  Dv(w[1] + 0.5*k2[1]*passe, w[2] + 0.5*k2[2]*passe, mi, r1, r2 ) 
                  ]
            
            r1 = math.sqrt(((w[0] + k3[0]*passe) + mi)**2 + (w[1] + k3[1]*passe)**2)
            r2 = math.sqrt(((w[0] + k3[0]*passe) - 1 + mi)**2 + (w[1] + k3[1]*passe)**2)

            k4 = [w[2] + k3[2]*passe,         
                  w[3] + k3[3]*passe,        #k4 de rk4
                  Du(w[0] + k3[0]*passe, w[3] + k3[3]*passe, mi, r1, r2 ), 
                  Dv(w[1] + k3[1]*passe, w[2] + k3[2]*passe, mi, r1, r2 ) 
                  ]

            w = [w[0] + (1/6)*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0])*passe, 
                  w[1] + (1/6)*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1])*passe,   #equacao 24
                  w[2] + (1/6)*(k1[2] + 2*k2[2] + 2*k3[2] + k4[2])*passe,
                  w[3] + (1/6)*(k1[3] + 2*k2[3] + 2*k3[3] + k4[3])*passe
                  ]

            r1 = math.sqrt((w[0] + mi)**2 + w[1]**2)   
            r2 = math.sqrt((w[0] -1 + mi)**2 + w[1]**2)
            
            X.append(w[0])
            Y.append(w[1])
            U.append(w[2])
            V.append(w[3]) #adicao dos valores de x, y, u e v em cada iteracao para geracao do grafico da trajetoria
            C.append(w[0]**2 + w[1]**2 + (2*(1 - mi))/r1 + (2*mi)/r2 - (w[2]**2 + w[3]**2)) #adicao do valor da integral de jacobi em cada iteracao para geracao do grafico de erro relativo


      return w, X, Y, C, U, V

