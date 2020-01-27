import matplotlib.pyplot as plt
import imageio
import csv

i = 0
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
