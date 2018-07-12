import numpy as np
import matplotlib.pyplot as plt
import os, sys


os.system("./mandelbrot" + " " + sys.argv[1] + " " + sys.argv[2] + " " + sys.argv[3] + " " + sys.argv[4] + " " + sys.argv[5] + " " + sys.argv[6] + " " + sys.argv[7] + " " + sys.argv[8] + " mandelbrot.txt")

mandel = []
with open("mandelbrot.txt", "r") as f:
    for line in f:
        mandel += [ line.split(" ") ]
mandel = np.array(mandel, dtype="uint8")
plt.imsave("mandelbrot.png", mandel)
