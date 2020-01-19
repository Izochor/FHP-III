# import numpy as np
import matplotlib.pyplot as plt
import imageio
import csv

nData = 10
datafiles = []
for i in range(0,nData+1):
    print("plotting",i)
    # datafiles.append("data/data"+str(i)+".dat")

    # f = open("data/data"+str(i)+".dat", "r")
    # print(f.read()) 
    with open("data/data"+str(i)+".dat", "r") as csvfile:
        plots = csv.reader(csvfile, delimiter='\t')
        x = []
        y = []
        for row in plots:
            x.append(float(row[0]))
            y.append(float(row[1]))

        plt.scatter(x,y,c="black")
        plt.savefig("plots/plot"+str(i)+".png")
        plt.cla()
        

# filenames = []

# plt.imshow(board, cmap='binary')
# plt.savefig("life\life.png")
# filenames.append("life\life.png")



#     plt.imshow(board, cmap='binary')
#     plt.savefig("life\life"+str(iteration)+".png")
#     filenames.append("life\life"+str(iteration)+".png")

# with imageio.get_writer('life\movie.gif', mode='I', duration = 0.5) as writer:
#     for filename in filenames:
#         image = imageio.imread(filename)
#         writer.append_data(image)

# print("GIF READY!")