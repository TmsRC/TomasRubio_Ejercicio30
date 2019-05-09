import matplotlib.pyplot as plt
import numpy as np
import imageio

datos = np.loadtxt("datos.dat")

x= np.linspace(0,1,101)

print(x.shape,datos[0].shape)

for i in range(200):
    img = plt.figure()
    plt.plot(x,datos[i])
    plt.xlabel("Posicion")
    plt.ylabel("U")
    plt.title("Tiempo: "+str(0.01*i))
    plt.grid()
    plt.savefig(str(i))
    plt.close(img)

with imageio.get_writer('resultados.gif', mode='I') as writer:
    for filename in range(200):
        image = imageio.imread(str(filename)+".png")
        writer.append_data(image)