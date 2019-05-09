import matplotlib.pyplot as plt
import numpy as np
import imageio

datos = np.loadtxt("datos.dat")

images = []
for filename in filenames:
    images.append(imageio.imread(filename))
imageio.mimsave('/path/to/movie.gif', images)