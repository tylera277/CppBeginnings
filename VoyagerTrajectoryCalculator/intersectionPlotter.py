import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Getting the calculation results from the csv file.
EarthTrajectory = pd.read_csv('../outputIntersection.csv')


EarthTrajectory = EarthTrajectory.to_numpy()

xEarth = []
yEarth = []
xJupiter = []
yJupiter = []
xSaturn = []
ySaturn = []
xUranus = []
yUranus = []

xCraft = []
yCraft = []
vxCraft = []
vyCraft = []


for i in range(0, len(EarthTrajectory)):
    xEarth.append(EarthTrajectory[i][0])
    yEarth.append(EarthTrajectory[i][1])
    xJupiter.append(EarthTrajectory[i][2])
    yJupiter.append(EarthTrajectory[i][3])
    xSaturn.append(EarthTrajectory[i][4])
    ySaturn.append(EarthTrajectory[i][5])
    xUranus.append(EarthTrajectory[i][6])
    yUranus.append(EarthTrajectory[i][7])

    xCraft.append(EarthTrajectory[i][8])
    yCraft.append(EarthTrajectory[i][9])
    vxCraft.append(EarthTrajectory[i][10])
    vyCraft.append(EarthTrajectory[i][11])

# For dynamically plotting the calculation results

plt.ion()
fig = plt.figure(figsize=(6, 6))
for i in range(0, len(xEarth), 500):
    plt.scatter(xEarth[i], yEarth[i], s=1, c='blue')
    plt.scatter(xJupiter[i], yJupiter[i], s=1, c='blue')
    plt.scatter(xSaturn[i], ySaturn[i], s=1, c='orange')
    plt.scatter(xUranus[i], yUranus[i], s=1, c='purple')

    plt.scatter(xCraft[i], yCraft[i], s=1, c='black')

    plt.xlabel((vxCraft[i]**2+vyCraft[i]**2)**(1/2))
    #plt.xlim([xJupiter[i] - 1e11, xJupiter[i] + 1e11])
    #plt.ylim([yJupiter[i] - 1e11, yJupiter[i] + 1e11])
    plt.xlim([0 - 3e12, 0 + 3e12])
    plt.ylim([0 - 3e12, 0 + 3e12])


    plt.draw()
    plt.pause(0.00001)
