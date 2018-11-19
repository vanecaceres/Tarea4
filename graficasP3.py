import numpy as np
import matplotlib.pyplot as plt

input = np.genfromtxt("datos.dat", dtype=None, comments="#", delimiter="\n",unpack = False)
numeroLinea=0
nombresFig=[["FronterasFijasInicial.pdf","FronterasFijasAvance1.pdf","FronterasFijasAvance2.pdf","FronterasFijasEq.pdf","FronterasFijasPromedio.pdf"],
            ["FronterasAbiertasInicial.pdf","FronterasAbiertasAvance1.pdf","FronterasAbiertasAvance2.pdf","FronterasAbiertasEq.pdf","FronterasAbiertasPromedio.pdf"],
            ["FronterasPeriodicasInicial.pdf","FronterasPeriodicasAvance1.pdf","FronterasPeriodicasAvance2.pdf","FronterasPeriodicasEq.pdfFronterasPeriodicasPromedio.pdf"]]
