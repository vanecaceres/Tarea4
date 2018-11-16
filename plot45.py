import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("datos45.dat", dtype=None, comments="#", delimiter="\n",unpack = False, skip_header = 1)

###print (datos[0][0],datos[0][1],datos[0][2])

c=0
x=[]
y=[]
t=[]
while True:
    try:
        s=list(datos[c].split())
        x.append(float(s[0]))
        y.append(float(s[1]))
        t.append(float(s[2]))
        c+=1
    except:
        break

fig = plt.figure()
plt.plot(x, y,  "purple", label = "45°")
plt.legend()
plt.grid()
plt.title("Distancia reccorida vs altura del lanzamiento de un proyectil")
plt.xlabel("distancia reccorida(mt)")
plt.ylabel("altura(mt)")
plt.savefig("45.pdf")
