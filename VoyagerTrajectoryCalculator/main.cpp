#include <iostream>
#include <fstream>

#include "rkComponents.h"
#include "initialConditions.h"
#include "rungeKuttaMain.h"

int main() {


    InitConditions iC;
    RungeKuttaHouse rk4;

    double Planet1Conds[4];
    double Planet2Conds[4];
    double Planet3Conds[4];

    iC.getInitialConditions("earth", Planet1Conds);
    iC.getInitialConditions("jupiter", Planet2Conds);
    iC.getInitialConditions("neptune", Planet3Conds);

    // Initial Conditions;
    // currently set for the Earths parameters

    double t0 = 0;
    double tEnd = (3.154e7)*200;

    double xSun = 0;
    double ySun = 0;

    // Earth initial conditions
    double x1 = Planet1Conds[0];
    double y1 = Planet1Conds[1];
    double vx1 = Planet1Conds[2];
    double vy1 = Planet1Conds[3];

    // Jupiter initial conditions
    double x2 = Planet2Conds[0];
    double y2 = Planet2Conds[1];
    double vx2 = Planet2Conds[2];
    double vy2 = Planet2Conds[3];

    // Neptune initial conditions
    double x3 = Planet3Conds[0];
    double y3 = Planet3Conds[1];
    double vx3 = Planet3Conds[2];
    double vy3 = Planet3Conds[3];

    double t = t0;

    // Time step
    // Currently 1 day in seconds
    double delT = 86400;

    double k[16];

    double mSun = 1.989e30;
    double mEarth = 5.972e24;

    //File which the results are being printed to.
    std::ofstream myfile;
    myfile.open ("../../output.csv");


    // Main body of Runge-kutta4 steps
    while(t<tEnd){

        // For the Earth orbiting the Sun
        rk4.calcRK4(delT,x1,y1,xSun,ySun,vx1,vy1,mSun,k);

        myfile << x1 << "," << y1 << ",";

        x1 += (delT/6) * (k[0]+ 2*k[4]+ 2*k[8]+ k[12]);
        y1 += (delT/6) * (k[1]+ 2*k[5]+ 2*k[9]+ k[13]);
        vx1 += (delT/6) * (k[2]+ 2*k[6]+ 2*k[10]+ k[14]);
        vy1 += (delT/6) * (k[3]+ 2*k[7]+ 2*k[11]+ k[15]);



        // For Jupiter orbiting the Sun
        rk4.calcRK4(delT,x2,y2,xSun,ySun,vx2,vy2,mSun,k);

        myfile << x2 << "," << y2 << ",";

        x2 += (delT/6) * (k[0]+ 2*k[4]+ 2*k[8]+ k[12]);
        y2 += (delT/6) * (k[1]+ 2*k[5]+ 2*k[9]+ k[13]);
        vx2 += (delT/6) * (k[2]+ 2*k[6]+ 2*k[10]+ k[14]);
        vy2 += (delT/6) * (k[3]+ 2*k[7]+ 2*k[11]+ k[15]);



        // For Neptune orbiting the Sun
        rk4.calcRK4(delT,x3,y3,xSun,ySun,vx3,vy3,mSun,k);

        myfile << x3 << "," << y3 << "\n";

        x3 += (delT/6) * (k[0]+ 2*k[4]+ 2*k[8]+ k[12]);
        y3 += (delT/6) * (k[1]+ 2*k[5]+ 2*k[9]+ k[13]);
        vx3 += (delT/6) * (k[2]+ 2*k[6]+ 2*k[10]+ k[14]);
        vy3 += (delT/6) * (k[3]+ 2*k[7]+ 2*k[11]+ k[15]);

        // Increase time by one time step
        t += delT;
    }
    myfile.close();


}
