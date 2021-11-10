
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Getting the calculation results from the csv file.
EarthTrajectory = pd.read_csv('./../output.csv')


EarthTrajectory = EarthTrajectory.to_numpy()
xEarth = []
yEarth = []
xJupiter = []
yJupiter = []
xNeptune = []
yNeptune = []

# Dissecting the dataframe into each planets components for
# easier plotting.
for i in range(0, len(EarthTrajectory[:])):
    xEarth.append(EarthTrajectory[i][0])
    yEarth.append(EarthTrajectory[i][1])
    xJupiter.append(EarthTrajectory[i][2])
    yJupiter.append(EarthTrajectory[i][3])
    xNeptune.append(EarthTrajectory[i][4])
    yNeptune.append(EarthTrajectory[i][5])


plt.ion()
for i in range(len(xEarth)):

    plt.scatter(xEarth[i], yEarth[i], s=5, c='blue')
    plt.scatter(xJupiter[i], yJupiter[i], s=5, c='orange')
    plt.scatter(xNeptune[i], yNeptune[i], s=5, c='magenta')


    plt.xlim([-1e13, 1e13])
    plt.ylim([-1e13, 1e13])
    plt.draw()
    plt.pause(0.001)
    plt.clf()


