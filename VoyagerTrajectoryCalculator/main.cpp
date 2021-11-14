#include <iostream>
#include <fstream>
#include <vector>

#include "4thRungeKutta.h"
#include "rungeKuttaFreeBody.h"

int main() {

    RungeKutta rk4;
    RungeKuttaFreeBody rk4fb;

    std::ofstream myfile;

    double xVelCheck = 0;
    double yVelCheck = 0;

    double xSun = 0;
    double ySun = 0;
    double mSun = 1.989e30;
    double mEarth = 5.972e24;
    double mMars = 6.98e23;
    //double mMars = 6.98e27;
    double mJupiter = 1.90e27;

    double t = 0;
    double tEnd = (3.154e7)*2;
    double delT = 86400;

    double k[16];

    // Earth
    double x1overall = 8.97e10;
    double y1overall = 1.17e11;
    double vx1overall = -2.42e4;
    double vy1overall = 1.80e4;

    // Mars
    double x2overall = -1.48e11;
    double y2overall = 1.96e11;
    double vx2overall = -1.839e4;
    double vy2overall = -1.26e4;

    // Jupiter
    double x3overall = -8.004e11;
    double y3overall = -1.549e11;
    double vx3overall = 2.32e3;
    double vy3overall = -1.22e4;


    for (int xVel = -11000; xVel < 11000; xVel += 100) {
        for (int yVel = -11000; yVel < 11000; yVel += 100) {

            // Earth
            double x1 = x1overall;
            double y1 = y1overall;
            double vx1 = vx1overall;
            double vy1 = vy1overall;

            // Mars
            double x2 = x2overall;
            double y2 = y2overall;
            double vx2 = vx2overall;
            double vy2 = vy2overall;

            //Jupiter
            double x3 = x3overall;
            double y3 = y3overall;
            double vx3 = vx3overall;
            double vy3 = vy3overall;


            double xCraft = x1overall;
            double yCraft = y1overall;

            t = 0;
            double count = 0;
            double counter = 0;


            //the Craft starts off with Earth's velocity
            double vxCraft = vx1overall;
            double vyCraft = vy1overall;
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



                // For Mars orbiting the Sun
                rk4.calcRK4(delT, x2, y2, xSun, ySun, vx2, vy2, mSun, k);


                x2 += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y2 += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx2 += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy2 += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

                // For Jupiter orbiting the Sun
                rk4.calcRK4(delT, x3, y3, xSun, ySun, vx3, vy3, mSun, k);


                x3 += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y3 += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx3 += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy3 += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);


                // For a craft of negligible mass moving amongst these bodies

                rk4fb.RK4freebody(delT, xCraft, yCraft, vxCraft, vyCraft, xSun, ySun, mSun,
                                  x1, y1, mEarth,
                                  x2, y2, mMars,
                                  x3, y3, mJupiter, k);


                xCraft += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                yCraft += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vxCraft += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vyCraft += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

                // If craft went within S.O.I. of Mars
                if ((xCraft > (x2 - 5e8)) && (xCraft < (x2 + 5e8))) {
                    if ((yCraft > (y2 - 5e8)) && (yCraft < (y2 + 5e8))) {

                        count += 1;
                        }
                    }

                // If craft went within S.O.I. of Jupiter
                if ((xCraft > (x3 - 1e9)) && (xCraft < (x3 + 1e9))) {
                    if ((yCraft > (y3 - 1e9)) && (yCraft < (y3 + 5e9))) {
                        counter += 1;
                        //std::cout<<count<<" "<<counter <<"\n";
                    }
                }
                //this makes sure each planet is met
                if((count>0)) {

                        if (((vxCraft > 0) && (vx1 > 0)) || (((vxCraft < 0) && (vx1 < 0)))) {
                        if (((vyCraft > 0) && (vy1 > 0)) || (((vyCraft < 0) && (vy1 < 0)))) {

                        //std::cout << "days:"<<days << "\n";
                        std::cout << "vel:" << xVel << " " << yVel << "\n";
                        std::cout << "craftVel:" << vxCraft << " " << vyCraft << "\n";
                        std::cout << "----------" << "\n";
                        /*
                        std::cout << x2 << " " << y2 << "\n";
                        std::cout << xCraft << " " << yCraft << "\n";
                        std::cout << xVel << " " << yVel << "\n";
                        std::cout << vxCraft << " " << vyCraft << "\n";

                         */
                        xVelCheck = xVel;
                        yVelCheck = yVel;
                        goto exitLoops;
                        }
                        }
                    }

                // Increase time by one time step
                t += delT;
            }
        }
    }


    exitLoops:

    myfile.open ("../../outputIntersection.csv");


    // Earth
            double x1new = x1overall;
            double y1new = y1overall;
            double vx1new = vx1overall;
            double vy1new = vy1overall;

            // Mars
            double x2new = x2overall;
            double y2new = y2overall;
            double vx2new = vx2overall;
            double vy2new = vy2overall;

            // jupiter
            double x3new = x3overall;
            double y3new = y3overall;
            double vx3new = vx3overall;
            double vy3new = vy3overall;







            double xCraft = x1overall;
            double yCraft = y1overall;

            t = 0;
            //double vxCraft = 20000;
            //double vyCraft = 20000;

            //the Craft starts off with Earth's velocity
            double vxCraft  = vx1overall;
            double vyCraft = vy1overall;
            vxCraft += xVelCheck;
            vyCraft += yVelCheck;

            //std::cout << vxCraft << " " << vyCraft << "\n";
            while (t < tEnd) {


                // For the Earth orbiting the Sun
                rk4.calcRK4(delT, x1new, y1new, xSun, ySun, vx1new, vy1new, mSun, k);


                x1new += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y1new += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx1new += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy1new += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);



                // For Mars orbiting the Sun
                rk4.calcRK4(delT, x2new, y2new, xSun, ySun, vx2new, vy2new, mSun, k);


                x2new += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y2new += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx2new += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy2new += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);


                // For jupiter orbiting the Sun
                rk4.calcRK4(delT, x3new, y3new, xSun, ySun, vx3new, vy3new, mSun, k);


                x3new += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                y3new += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vx3new += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vy3new += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);

                // For a craft of negligible mass moving amongst these bodies

                rk4fb.RK4freebody(delT,xCraft,yCraft,vxCraft,vyCraft,
                                  xSun,ySun,mSun,x1new,y1new,mEarth,x2new,y2new,mMars,
                                  x3new,y3new, mJupiter,k);


                xCraft += (delT / 6) * (k[0] + 2 * k[4] + 2 * k[8] + k[12]);
                yCraft += (delT / 6) * (k[1] + 2 * k[5] + 2 * k[9] + k[13]);
                vxCraft += (delT / 6) * (k[2] + 2 * k[6] + 2 * k[10] + k[14]);
                vyCraft += (delT / 6) * (k[3] + 2 * k[7] + 2 * k[11] + k[15]);





                myfile << x1new << "," << y1new <<",";
                myfile << x2new << "," << y2new <<",";
                myfile << xCraft << "," << yCraft<<",";
                myfile << x3new << "," << y3new <<",";
                myfile << vxCraft << "," << vyCraft <<"\n";



                // Increase time by one time step
                t += delT;
            }

    myfile.close();



}
