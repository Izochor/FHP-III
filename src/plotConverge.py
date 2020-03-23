import matplotlib.pyplot as plt
import numpy as np
import imageio
import csv

def func(x, a, b, c):
    return a * x**2 + b*x +c

i = 22
with open("converge/converge"+str(i)+".dat", "r") as csvfile:
    plots = csv.reader(csvfile, delimiter='\t')
    x = []
    y = []
    for row in plots:
        x.append(float(row[0]))
        y.append(float(row[1]))

plt.hlines(0.1,0,len(x),colors='red')
plt.scatter(x,y,c="black",s=0.5)
plt.savefig("converge/plot"+str(i)+".png")
plt.cla()
