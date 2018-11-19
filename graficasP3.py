import numpy as np
import matplotlib.pyplot as plt
#Importo los datos que generé con mi archivo cpp con los casos
input = np.genfromtxt("datos.dat", dtype=None, comments="#", delimiter="\n",unpack = False)
#numero que iré sumando para las imagenes
numeroLinea=0
#Arreglo con los nombres con los que voy a guardar mis imágenes en los 3 casos
nombresFig=[["FronterasFijasInicial.pdf","FronterasFijasAvance1.pdf","FronterasFijasAvance2.pdf","FronterasFijasEq.pdf","FronterasFijasPromedio.pdf"],
            ["FronterasAbiertasInicial.pdf","FronterasAbiertasAvance1.pdf","FronterasAbiertasAvance2.pdf","FronterasAbiertasEq.pdf","FronterasAbiertasPromedio.pdf"],
            ["FronterasPeriodicasInicial.pdf","FronterasPeriodicasAvance1.pdf","FronterasPeriodicasAvance2.pdf","FronterasPeriodicasEq.pdfFronterasPeriodicasPromedio.pdf"]]
#Tamaño de los casos de frontera
tamano = len(nombresFig)
#Hago un for para generar las 15 imagenes, cada una para los 3 casos
for condicion in range(tamano):
#N es mi input (datos) en la linea que va sumando
    N=int(input[numeroLinea])
#Sumo a la linea 1 para seguir con la otra linea
    numeroLinea+=1
    dx=float(input[numeroLinea])

