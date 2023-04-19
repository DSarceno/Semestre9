import numpy as np
from scipy.integrate import solve_ivp


k1 = 1
k2 = 1
k3 = 1
m1 = 1
m2 = 1


def odeSystem(t,y):
    x1, v1, x2, v2 = y
    f = [v1,
        -((k1 + k2)/m1)*x1 + (k2/m1)*x2,
        v2,
        (k3/m2)*x1 - ((k2 + k3)/m2)*x2]

t = np.linspace(0,50,5000)

# Condiciones iniciales
x1 = -0.5
v1 = 0
x2 = 0.5
v2 = 0


solution = solve_ivp(odeSystem, [0,50],[x1, v1, x2,
    v2],t_eval=np.linspace(0,50,5000))


file = open("data.dat","w")
for i in range(len(solution.y[0])):
    file.write(str(solution.t[i]) + '\t' + str( solution.y[0][i] ) + '\t'
            + str( solution.y[1][i] ) + '\t' + str( solution.y[2][i] ) + '\t'
            + str( solution.y[3][i] ) + '\n' )

file.close()








#
