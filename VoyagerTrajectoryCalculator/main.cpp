#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "4thRungeKutta.h"
#include "rungeKuttaFreeBody.h"
#include "longTermSimulator.h"

int main() {

    RungeKutta rk4;
    RungeKuttaFreeBody rk4fb;
    StormerVerlet sv;

    std::ofstream myfile;

    double xVelCheck = 0;
    double yVelCheck = 0;

    double xSun = 0;
    double ySun = 0;
    double mSun = 1.989e30;
    double mEarth = 5.972e24;
    double mJupiter = 1.90e27;
    double mSaturn = 5.6834e26;
    double mUranus = 8.681e25;

    double t = 0;
    double tEnd = (3.154e7) * 6;
    double delT = 86400/24.0;
    double overalldelT = 86400/2.0;

    double k[16];

    // Earth: 8/17/1977
    double x1overall = 1.233218897893897e11;
    double y1overall = -8.904226031790185e10;
    double vx1overall = 1.691561372411719e4;
    double vy1overall = 2.409137633730570e4;

    // Jupiter
    double x2overall = 1.276407046650211e11;
    double y2overall = 7.502104796350324e11;
    double vx2overall = -1.303355618412759e4;
    double vy2overall = 2.797053507139675e3;

    // Saturn
    double x3overall = -1.064448548304196e12;
    double y3overall = 8.662220705457528e11;
    double vx3overall = -6.619064632070407e3;
    double vy3overall = -7.517691833339467e3;

    // Uranus
    double x4overall = -2.084217532928676e12;
    double y4overall = -1.840739460405314e12;
    double vx4overall = 4.457405735484686e3;
    double vy4overall = -5.422629262296935e3;

    // Using the fastest launch velocity ever achieved to make program
    // a bit simpler; only varying the angle of launch.
    static double craftLaunchVelocity =10800;

    double radians;

    double oldxAcceleration = 0;
    double oldyAcceleration = 0;

    double newXacceleration = 0;
    double newYacceleration = 0;

    //std::cout<<std::setprecision(16)<<"beep:"<<x1overall<<"\n";


//for(int days=0; days<3.154e7; days += overalldelT) {
for(int days=0; days<(86400)*6; days += overalldelT){


    std::cout << days / 86400 << "\n";

    // Long term orbit simulator goes here.
    // Trying to use a symplectic integrator here for the long term motion of the
    // planetary bodies.

    // Earth
    oldxAcceleration = sv.oldXAcceleration(x1overall, y1overall, xSun, ySun, mSun);
    oldyAcceleration = sv.oldYAcceleration(x1overall, y1overall, xSun, ySun, mSun);

    x1overall += vx1overall * overalldelT + (1.0 / 2.0) * oldxAcceleration * pow(overalldelT, 2);
    y1overall += vy1overall * overalldelT + (1.0 / 2.0) * oldyAcceleration * pow(overalldelT, 2);

    newXacceleration = rk4.computeXAccel(x1overall, y1overall, xSun, ySun, mSun);
    newYacceleration = rk4.computeYAccel(x1overall, y1overall, xSun, ySun, mSun);

    vx1overall += (1.0 / 2.0) * (oldxAcceleration + newXacceleration) * overalldelT;
    vy1overall += (1.0 / 2.0) * (oldyAcceleration + newYacceleration) * overalldelT;

    //
    // -------------------------
    // Jupiter
    oldxAcceleration = rk4.computeXAccel(x2overall, y2overall, xSun, ySun, mSun);
    oldyAcceleration = rk4.computeYAccel(x2overall, y2overall, xSun, ySun, mSun);

    x2overall += vx2overall * overalldelT + (1.0 / 2.0) * oldxAcceleration * pow(overalldelT, 2);
    y2overall += vy2overall * overalldelT + (1.0 / 2.0) * oldyAcceleration * pow(overalldelT, 2);

    newXacceleration = rk4.computeXAccel(x2overall, y2overall, xSun, ySun, mSun);
    newYacceleration = rk4.computeYAccel(x2overall, y2overall, xSun, ySun, mSun);

    vx2overall += (1.0 / 2.0) * (oldxAcceleration + newXacceleration) * overalldelT;
    vy2overall += (1.0 / 2.0) * (oldyAcceleration + newYacceleration) * overalldelT;

    //
    // -------------------------
    // Saturn
    oldxAcceleration = rk4.computeXAccel(x3overall, y3overall, xSun, ySun, mSun);
    oldyAcceleration = rk4.computeYAccel(x3overall, y3overall, xSun, ySun, mSun);

    x3overall += vx3overall * overalldelT + (1.0 / 2.0) * oldxAcceleration * pow(overalldelT, 2);
    y3overall += vy3overall * overalldelT + (1.0 / 2.0) * oldyAcceleration * pow(overalldelT, 2);

    newXacceleration = rk4.computeXAccel(x3overall, y3overall, xSun, ySun, mSun);
    newYacceleration = rk4.computeYAccel(x3overall, y3overall, xSun, ySun, mSun);

    vx3overall += (1.0 / 2.0) * (oldxAcceleration + newXacceleration) * overalldelT;
    vy3overall += (1.0 / 2.0) * (oldyAcceleration + newYacceleration) * overalldelT;

    //
    // -------------------------
    // Uranus
    oldxAcceleration = rk4.computeXAccel(x4overall, y4overall, xSun, ySun, mSun);
    oldyAcceleration = rk4.computeYAccel(x4overall, y4overall, xSun, ySun, mSun);

    x4overall += vx4overall * overalldelT + (1.0 / 2.0) * oldxAcceleration * pow(overalldelT, 2);
    y4overall += vy4overall * overalldelT + (1.0 / 2.0) * oldyAcceleration * pow(overalldelT, 2);

    newXacceleration = rk4.computeXAccel(x4overall, y4overall, xSun, ySun, mSun);
    newYacceleration = rk4.computeYAccel(x4overall, y4overall, xSun, ySun, mSun);

    vx4overall += (1.0 / 2.0) * (oldxAcceleration + newXacceleration) * overalldelT;
    vy4overall += (1.0 / 2.0) * (oldyAcceleration + newYacceleration) * overalldelT;


    // Angle to Jupiter, using this to try to limit the range of degrees
    // that my program needs to check over.
    double angle2Jup = (((atan((y2overall - y1overall) / (x2overall - x1overall))) * 180) / M_PI);

    //std::cout << angle2Jup/10.0 << "\n";

    double angle2Jup2 = 0;

    // Determine which quadrant it lies in
    if(((x2overall-x1overall)>0)&&((y2overall-y1overall)>0)){
        angle2Jup2 = abs(angle2Jup);
    }else if(((x2overall-x1overall)<0)&&((y2overall-y1overall)>0)){
        angle2Jup2 = 180 - abs(angle2Jup);
    }else if(((x2overall-x1overall)<0)&&((y2overall-y1overall)<0)){
        angle2Jup2 = 180 + abs(angle2Jup);
    }else if(((x2overall-x1overall)>0)&&((y2overall-y1overall)<0)){
        angle2Jup2 = 360 - abs(angle2Jup);
    }

    std::cout << angle2Jup2 << "\n";

    double angle2JupiterFromSun = (((atan((y2overall) / (x2overall))) * 180) / M_PI);
    double angle2SaturnFromSun = (((atan((y3overall) / (x3overall))) * 180) / M_PI);



        // Loop which checks over the various angles of launch
        //for (int angle = angle2Jup - 300; angle <= angle2Jup + 300; angle += 1) {
        //for (int angle = (angle2Jup2*10.0)-100; angle <= (angle2Jup2*10.0)+100; angle += 1) {
        for(double angle = angle2Jup2-5; angle<=angle2Jup2+5; angle += 0.1){

            // Increments the angle by 0.1 degrees
            double angleReduced = double(angle);
            //std::cout << angleReduced<<"\n";


            // Earth
            double x1 = x1overall;
            double y1 = y1overall;
            double vx1 = vx1overall;
            double vy1 = vy1overall;

            // Jupiter
            double x2 = x2overall;
            double y2 = y2overall;
            double vx2 = vx2overall;
            double vy2 = vy2overall;

            //Saturn
            double x3 = x3overall;
            double y3 = y3overall;
            double vx3 = vx3overall;
            double vy3 = vy3overall;

            //Uranus
            double x4 = x4overall;
            double y4 = y4overall;
            double vx4 = vx4overall;
            double vy4 = vy4overall;


            double xCraft = x1overall;
            double yCraft = y1overall;

            t = 0;
            double countJupiter = 0;
            double countSaturn = 0;
            double countUranus = 0;


            //the Craft starts off with Earth's velocity
            double vxCraft = vx1overall;
            double vyCraft = vy1overall;


            radians = (angleReduced * M_PI) / 180.0;

            double xVel = craftLaunchVelocity * cos(radians);
            double yVel = craftLaunchVelocity * sin(radians);
            vxCraft += xVel;
            vyCraft += yVel;

            //std::cout << vxCraft << " " << vyCraft << "\n";
            while (t < tEnd) {



                // For the Earth orbiting the Sun
                rk4.calcRK4(delT, x1, y1, xSun, ySun, vx1, vy1, mSun, k);


                x1 += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y1 += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx1 += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy1 += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);



                // For Jupiter orbiting the Sun
                rk4.calcRK4(delT, x2, y2, xSun, ySun, vx2, vy2, mSun, k);


                x2 += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y2 += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx2 += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy2 += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

                // For Saturn orbiting the Sun
                rk4.calcRK4(delT, x3, y3, xSun, ySun, vx3, vy3, mSun, k);


                x3 += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y3 += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx3 += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy3 += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

                // For Uranus orbiting the Sun
                rk4.calcRK4(delT, x4, y4, xSun, ySun, vx4, vy4, mSun, k);


                x4 += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y4 += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx4 += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy4 += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);


                // For a craft of negligible mass moving amongst these bodies

                rk4fb.RK4freebody(delT, xCraft, yCraft, vxCraft, vyCraft,
                                  xSun, ySun, mSun,
                                  x1, y1, mEarth,
                                  x2, y2, mJupiter,
                                  x3, y3, mSaturn,
                                  x4, y4, mUranus,k);


                xCraft += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                yCraft += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vxCraft += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vyCraft += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

                // If craft went within region of Jupiter
                if ((xCraft > (x2 - 6.5e8)) && (xCraft < (x2 + 6.5e8))) {
                    if ((yCraft > (y2 - 6.5e8) && (yCraft < (y2 + 6.5e8)))) {

                        countJupiter += 1;
                    }
                }


                // If craft went within region of Saturn; 1.5e8
                if ((xCraft >= (x3 - 5e8)) && (xCraft <= (x3 + 5e8))) {
                    if ((yCraft >= (y3 - 5e8)) && (yCraft <= (y3 + 5e8))) {
                        countSaturn += 1;
                    }
                }



                // If craft went within region of Saturn
                if ((xCraft >= (x4 - 1e12)) && (xCraft <= (x4 + 1e12))) {
                    if ((yCraft >= (y4 - 1e12)) && (yCraft <= (y4 + 1e12))) {
                        countUranus += 1;
                    }
                }
                

                //this makes sure each condition of trajectory is met
                if ((countJupiter > 0) && (countSaturn>0)) {
                    std::cout << "check!" << "\n";


                        //std::cout << "days:"<<days << "\n";
                        std::cout << "vel:" << xVel << " " << yVel << "\n";
                        std::cout << "craftVel:" << vxCraft << " " << vyCraft << "\n";
                        std::cout << "angle:" << angleReduced << "\n";
                        std::cout<<y2overall-y1overall<<"\n";
                        std::cout<<x2overall-x1overall<<"\n";

                        std::cout << "----------" << "\n";

                        xVelCheck = xVel;
                        yVelCheck = yVel;
                        goto exitLoops;


                }


                // Increase time by one time step
                t += delT;
            }
        }
    }

    exitLoops:

    myfile.open("../../outputIntersection.csv");


    // Earth
    double x1new = x1overall;
    double y1new = y1overall;
    double vx1new = vx1overall;
    double vy1new = vy1overall;

    // Jupiter
    double x2new = x2overall;
    double y2new = y2overall;
    double vx2new = vx2overall;
    double vy2new = vy2overall;

    // Saturn
    double x3new = x3overall;
    double y3new = y3overall;
    double vx3new = vx3overall;
    double vy3new = vy3overall;

    // Uranus
    double x4new = x4overall;
    double y4new = y4overall;
    double vx4new = vx4overall;
    double vy4new = vy4overall;



    double xCraft = x1overall;
    double yCraft = y1overall;

    t = 0;

    //the Craft starts off with Earth's velocity
    double vxCraft = vx1overall;
    double vyCraft = vy1overall;
    vxCraft += xVelCheck;
    vyCraft += yVelCheck;

    // Loop used for plotting the trajectory that meets all the criteria
    while (t < tEnd) {


        // For the Earth orbiting the Sun
        rk4.calcRK4(delT, x1new, y1new, xSun, ySun, vx1new, vy1new, mSun, k);


        x1new += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
        y1new += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
        vx1new += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
        vy1new += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);



        // For Jupiter orbiting the Sun
        rk4.calcRK4(delT, x2new, y2new, xSun, ySun, vx2new, vy2new, mSun, k);


        x2new += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
        y2new += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
        vx2new += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
        vy2new += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);


        // For Saturn orbiting the Sun
        rk4.calcRK4(delT, x3new, y3new, xSun, ySun, vx3new, vy3new, mSun, k);


        x3new += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
        y3new += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
        vx3new += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
        vy3new += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

        // For Uranus orbiting the Sun
        rk4.calcRK4(delT, x4new, y4new, xSun, ySun, vx4new, vy4new, mSun, k);


        x4new += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
        y4new += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
        vx4new += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
        vy4new += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

        // For a craft of negligible mass moving amongst these bodies

        rk4fb.RK4freebody(delT, xCraft, yCraft, vxCraft, vyCraft,
                          xSun, ySun, mSun, x1new, y1new, mEarth,
                          x2new, y2new, mJupiter,
                          x3new, y3new, mSaturn,
                          x4new, y4new, mUranus,
                          k);


        xCraft += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
        yCraft += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
        vxCraft += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
        vyCraft += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);


        myfile << x1new << "," << y1new << ",";
        myfile << x2new << "," << y2new << ",";
        myfile << x3new << "," << y3new << ",";
        myfile << x4new << "," << y4new << ",";
        myfile << xCraft << "," << yCraft << ",";
        myfile << vxCraft << "," << vyCraft << "\n";


        // Increase time by one time step
        t += delT;
    }

    myfile.close();



}