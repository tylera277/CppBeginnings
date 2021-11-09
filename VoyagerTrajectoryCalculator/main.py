


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


EarthTrajectory = pd.read_csv('./../output.csv')
EarthTrajectory.columns = ['xEarth', 'yEarth']

print(EarthTrajectory)

EarthTrajectory.plot(x='xEarth', y='yEarth', kind='scatter', s=1)
plt.show()
