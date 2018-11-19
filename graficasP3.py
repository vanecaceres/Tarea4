from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np
import matplotlib.pyplot as plt
from math import ceil

#Importo los datos que generé con mi archivo cpp con los casos
input = np.genfromtxt("datos.dat", dtype=None, comments="#", delimiter="\n",unpack = False)
#numero que iré sumando para las imagenes
numeroLinea=0
#Arreglo con los nombres con los que voy a guardar mis imágenes en los 3 casos
nombresFig=[["FronterasFijasInicial.pdf","FronterasFijasAvance1.pdf","FronterasFijasAvance2.pdf","FronterasFijasEq.pdf","FronterasFijasPromedio.pdf"],
            ["FronterasAbiertasInicial.pdf","FronterasAbiertasAvance1.pdf","FronterasAbiertasAvance2.pdf","FronterasAbiertasEq.pdf","FronterasAbiertasPromedio.pdf"],
            ["FronterasPeriodicasInicial.pdf","FronterasPeriodicasAvance1.pdf","FronterasPeriodicasAvance2.pdf","FronterasPeriodicasEq.pdf","FronterasPeriodicasPromedio.pdf"]]
#Tamaño de los casos de frontera
tamano = len(nombresFig)
Tpromedio=[]
#Hago un for para generar las 15 imagenes, cada una para los 3 casos
for condicion in range(tamano):
#N es mi input (datos) en la linea que va sumando
    N=int(input[numeroLinea])
#Sumo a la linea 1 para seguir con la otra linea
    numeroLinea+=1
    dx=float(input[numeroLinea])
    numeroLinea+=1
    T=[[0 for i in range(N)] for j in range(N)]
    x=[i*dx for i in range(N)]
    x1=np.array(x)
    x=[ x1.copy() for i in range(N)]
    y=[np.array([x1[i]for j in range(N)]) for i in range(N) ]
    for numeroGrafica in range(5):
        for i in range(N):
            for j in range(N):
                T[i][j]=float(input[numeroLinea])
                numeroLinea+=1
        fig = plt.figure()
        ax = fig.add_subplot(111, projection="3d")
        ax.set_title("Propagación calor varilla")
        ax.set_xlabel("distancia horizontal (metros)")
        ax.set_ylabel("distancia vertical (metros)")
        ax.set_zlabel("temperatura en °K")
        T=np.array(T)
        ax.plot_surface(x,y,T, cmap=cm.coolwarm,linewidth=0, antialiased=False)
        fig.savefig(nombresFig[condicion][numeroGrafica])
        plt.title(nombresFig[condicion][numeroGrafica][:-3])
    tiempo=int(input[numeroLinea])
    numeroLinea+=1
    Tpromedio.append([])
    for i in range(tiempo):
        Tpromedio[-1].append(float(input[numeroLinea]))
        numeroLinea+=1
tim=[i*10 for i in range(tiempo)]
fig = plt.figure()
plt.title("Temperatura promedio vs Tiempo")
plt.xlabel("tiempo sg")
plt.ylabel("temperatura  °K")
colors=["purple","red","pink"]
labels=["Fijas", "Abiertas", "Periodicas"]
for i in range(3):
    plt.plot(tim,Tpromedio[i],colors[i],label=labels[i])
    plt.grid()
    plt.legend()
fig.savefig("temperaturaPromedio.png")
fig = plt.figure()
plt.title("Temperatura promedio vs Tiempo")
plt.xlabel("tiempo (sg)")
plt.ylabel("temperatura  (°K)")
colors=["red","orange","yellow"]
labels=["Fijas", "Abiertas", "Periodicas"]
plt.semilogx()
plt.semilogy()
for i in range(3):
    plt.plot(tim,Tpromedio[i],colors[i],label=labels[i])
    plt.grid()
    plt.legend()
fig.savefig("temperaturaPromedioLogarimtica.png")
