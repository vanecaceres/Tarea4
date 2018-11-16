import numpy as np
import matplotlib.pyplot as plt

input = np.genfromtxt("DatosOtrosAngulos.dat", dtype=None, comments="#", delimiter="\n",unpack = False)
colors=["red","blue","green","pink","purple","orange","yellow"]
labels=["10°", "20°", "30°", "40°", "50°", "60°", "70°"]
c=0
plt.figure()
plt.title("Distancia reccorida vs altura del lanzamiento de un proyectil")
plt.grid()
plt.xlabel("distancia reccorida(mt)")
plt.ylabel("altura(mt)")
for i in range(0,25,4):
    size=int(input[i])
    x=list(map(float,input[i+1].split()))
    y=list(map(float,input[i+2].split()))
    t=list(map(float,input[i+3].split()))
    plt.plot(x, y,colors[c], label=labels[c])
    c+=1
    plt.legend()
    plt.savefig("OtrosAngulos.pdf")
