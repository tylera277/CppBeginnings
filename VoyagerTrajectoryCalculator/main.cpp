#include <iostream>
#include <fstream>

#include "rkComponents.h"

int main() {


    // Initial Conditions;
    // currently set for the Earths parameters
    double x0 = 1.01e11;
    double y0 = 1.08e11;
    double vx0 = -22100;
    double vy0 = 20380;
    double t0 = 0;
    double tEnd = 3.154e7;
    double h = 1;

    double x = x0;
    double y = y0;
    double vx = vx0;
    double vy = vy0;
    double t = t0;

    // Time step
    // Currently 1 day in seconds
    double delT = 86400/24;



    double k1_x,k1_y,k1_vx,k1_vy;
    double k2_x,k2_y,k2_vx,k2_vy;
    double k3_x,k3_y,k3_vx,k3_vy;
    double k4_x,k4_y,k4_vx,k4_vy;

    compute c1;

    //File which the results are being printed to.
    std::ofstream myfile;
    myfile.open ("../../output.csv");


    // Main body of Runge-kutta4 steps
    while(t<tEnd){

        k1_x = vx;
        k1_y = vy;
        k1_vx = c1.computeXAccel(x,y);
        k1_vy = c1.computeYAccel(x,y);

        k2_x = vx + (delT/2)*k1_vx;
        k2_y = vy + (delT/2)*k1_vy;
        k2_vx = c1.computeXAccel((x+(delT/2)*k1_x), (y+(delT/2)*k1_y));
        k2_vy = c1.computeYAccel((x+(delT/2)*k1_x), (y+(delT/2)*k1_y));

        k3_x = vx + (delT/2)*k2_vx;
        k3_y = vy + (delT/2)*k2_vy;
        k3_vx = c1.computeXAccel((x+(delT/2)*k2_x), (y+(delT/2)*k2_y));
        k3_vy = c1.computeYAccel((x+(delT/2)*k2_x), (y+(delT/2)*k2_y));

        k4_x = vx + delT*k3_vx;
        k4_y = vy + delT*k3_vy;
        k4_vx = c1.computeXAccel((x+delT*k3_x), (y+delT*k3_y));
        k4_vy = c1.computeYAccel((x+delT*k3_x), (y+delT*k3_y));

        myfile << x << "," << y <<"\n";



        x += (delT/6) * (k1_x+2*k2_x+2*k3_x+k4_x);
        y += (delT/6) * (k1_y+2*k2_y+2*k3_y+k4_y);
        vx += (delT/6) * (k1_vx+2*k2_vx+2*k3_vx+k4_vx);
        vy += (delT/6) * (k1_vy+2*k2_vy+2*k3_vy+k4_vy);

        t += delT;
    }
    myfile.close();


}
