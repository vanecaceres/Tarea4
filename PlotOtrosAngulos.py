import numpy as np
import matplotlib.pyplot as plt

input = np.genfromtxt("DatosOtrosAngulos.dat", dtype=None, comments="#", delimiter="\n",unpack = False)
colors=["red","blue","green","pink","purple","orange","yellow"]
labels=["10°", "20°", "30°", "40°", "50°", "60°", "70°"]
c=0
