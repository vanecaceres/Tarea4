from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np
import matplotlib.pyplot as plt
from math import ceil
#######GRAFICA DE 45 GRADOS
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
########GRAFICA DE 10,20,... HASTA 70 GRADOS
input1 = np.genfromtxt("DatosOtrosAngulos.dat", dtype=None, comments="#", delimiter="\n",unpack = False)
colors=["red","blue","green","pink","purple","orange","yellow"]
labels=["10°", "20°", "30°", "40°", "50°", "60°", "70°"]
c=0
plt.figure()
plt.title("Distancia reccorida vs altura del lanzamiento de un proyectil")
plt.grid()
plt.xlabel("distancia reccorida(mt)")
plt.ylabel("altura(mt)")
for i in range(0,25,4):
    size=int(input1[i])
    x=list(map(float,input1[i+1].split()))
    y=list(map(float,input1[i+2].split()))
    t=list(map(float,input1[i+3].split()))
    plt.plot(x, y,colors[c], label=labels[c])
    c+=1
    plt.legend()
    plt.savefig("OtrosAngulos.pdf")

######GRAFICAS DE ESTADOS LIBRES, ABIERTOS Y PERIODICOS

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
labelsCond=["Inicial", "Avance 1", "Avance 2", "Equilibrio", "Promedio"]
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
        ax.set_title(labelsCond[numeroGrafica])
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
plt.xlabel("tiempo (sg)")
plt.ylabel("temperatura  °K")
colors=["purple","red","pink"]
labels=["Fijas", "Abiertas", "Periodicas"]
plt.grid()
for i in range(3):
    plt.plot(tim,Tpromedio[i],colors[i],label=labels[i])
    plt.legend()
fig.savefig("temperaturaPromedio.pdf")
fig = plt.figure()
plt.title("Temperatura promedio vs Tiempo")
plt.xlabel("tiempo (sg)")
plt.ylabel("temperatura  (°K)")
colors=["red","orange","purple"]
labels=["Fijas", "Abiertas", "Periodicas"]
plt.semilogx()
#plt.semilogy()
plt.grid()
for i in range(3):
    plt.plot(tim,Tpromedio[i],colors[i],label=labels[i])
    plt.legend()
fig.savefig("temperaturaPromedioLogarimtica.pdf")





