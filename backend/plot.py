import matplotlib.pyplot as plt
import imageio
import csv

nData = 15000
datafiles = []
for i in range(0,nData+1):
    if(i%100 == 0):
        print("plotting",i)
    with open("data/data"+str(i)+".dat", "r") as csvfile:
        plots = csv.reader(csvfile, delimiter='\t')
        x = []
        y = []
        value = []
        for row in plots:
            x.append(float(row[0]))
            y.append(float(row[1]))
            value.append(float(row[2]))

        plt.scatter(x,y,c=value)
        plt.savefig("plots/plot"+str(i)+".png")
        plt.cla()
