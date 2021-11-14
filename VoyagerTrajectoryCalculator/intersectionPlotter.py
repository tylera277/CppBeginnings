import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Getting the calculation results from the csv file.
EarthTrajectory = pd.read_csv('./../outputIntersection.csv')

EarthTrajectory = EarthTrajectory.to_numpy()

xEarth = []
yEarth = []
xMars = []
yMars = []
xCraft = []
yCraft = []
xJupiter = []
yJupiter = []

for i in range(0, len(EarthTrajectory), 15):
    xEarth.append(EarthTrajectory[i][0])
    yEarth.append(EarthTrajectory[i][1])
    xMars.append(EarthTrajectory[i][2])
    yMars.append(EarthTrajectory[i][3])
    xCraft.append(EarthTrajectory[i][4])
    yCraft.append(EarthTrajectory[i][5])
    xJupiter.append(EarthTrajectory[i][6])
    yJupiter.append(EarthTrajectory[i][7])





plt.ion()
fig = plt.figure(figsize=(6, 6))
for i in range(len(xEarth)):
    plt.scatter(xEarth[i], yEarth[i], s=1, c='blue')
    plt.scatter(xMars[i], yMars[i], s=1, c='red')
    plt.scatter(xCraft[i], yCraft[i], s=1, c='black')
    plt.scatter(xJupiter[i], yJupiter[i], s=1, c='orange')

    #plt.xlim([xMars[i] - 5e10, xMars[i] + 5e10])
    #plt.ylim([yMars[i] - 5e10, yMars[i] + 5e10])
    plt.xlim([0 - 1e12, 0 + 1e12])
    plt.ylim([0 - 1e12, 0 + 1e12])

    plt.draw()
    plt.pause(0.00001)
