import matplotlib.pyplot as plt
import numpy as np
import imageio
import csv

def func(x, a, b, c):
    return a * x**2 + b*x +c

i = 1
with open("final/final"+str(i)+".dat", "r") as csvfile:
    plots = csv.reader(csvfile, delimiter='\t')
    x = []
    y = []
    for row in plots:
        x.append(float(row[0]))
        y.append(float(row[1]))

    plt.scatter(x,y,c="black")
    plt.savefig("final/plot"+str(i)+".png")
    plt.cla()
