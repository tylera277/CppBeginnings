
ULTIMATE GOAL: To compute when a interplanetary trip like the Voyager's mission, can take place in the future.


Program which computes the trajectory of a planet in C++ then outputs that into an intermediate csv file to then be taken in
by a python program to be plotted in matplotlib.

DONE (11/8/2021)- Step 1: Get the 4th order Runge-Kutta working for a simple system of the Earth orbiting the Earth around the Sun located at the origin of the system.

<p align="center">
<img width="611" alt="Screen Shot 2021-11-08 at 9 36 05 PM" src="https://user-images.githubusercontent.com/37377528/140851467-349368a9-3139-4202-94ee-2b76b87ea1d1.png">
</p>
  
DONE (11/9/2021) - Step 2: Get the output from the C++ program plotted in python more dynamically. i.e. can see objects moving over time instead of just seeing its overall end path that it took.

DONE (11/9/2021) - Step 3: Place more than one planet in the system orbiting the sun.

<p align="center">
<img width="611" alt="Screen Shot 2021-11-09 at 8 45 42 PM" src="https://user-images.githubusercontent.com/37377528/141034925-bc7914aa-10ba-431a-89a3-6bc398f056d8.png">
</p>

DONE (11/10/2021) - Step 4: Calculate a mass of negligible amount, a craft, being shot from the earth at some angle with some speed and see its trajectory evolve over time.

DONE (11/10/2021) - Step 5: Get a simple 1-body gravitational slingshot of the craft around a planetary body other than its starting point of the Earth.

- Demonstration slingshot of a craft around a body at mars position with jupiters mass. Number at bottom of chart is resultant velocity.
- Red is Mars with Jupiter's mass, black is the craft, and blue is the Earth
<p align="center">
<img width="546" alt="slingPart1" src="https://user-images.githubusercontent.com/37377528/141162141-ca781094-42e2-4cd8-8043-613dd99d7b9b.png">
</p>

<p align="center">
<img width="546" alt="slingPart2" src="https://user-images.githubusercontent.com/37377528/141162115-3e84e8d1-5e3b-459e-ad13-2ee85863dde9.png">

</p>


Step 6: Somehow figure out what angle and speed needs to be given to the craft in order for it to get the slingshot affect from another body
  --> I have a program that I can easily scale to many bodies in orbit of the sun. I now need to determine how to calculate what date and with what velocity to launch the craft with and towards, in order for the craft to reach another body for a slingshot.
  

Step 7: Somehow chain these slingshots together so that the craft can go from one body to another.

I can get the craft to hit Jupiter and slingshot to Saturn, but after that it loses velocity and doesn't proceed to Uranus.
<img width="594" alt="Screen Shot 2021-11-17 at 3 45 17 PM" src="https://user-images.githubusercontent.com/37377528/142280117-2f293cad-fe84-478e-8df2-99f65ac59ff3.png">



Step x: Maybe update graphics 
Step x+2:...

