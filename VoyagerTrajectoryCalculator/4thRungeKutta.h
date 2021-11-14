//
// Created by Tyler Allen on 11/10/21.
//

#include <cmath>

class RungeKutta{
public:

    double G = 6.67e-11;

    double computeXAccel(double x1,double y1, double x2, double y2, double center_mass){
        double a_x = (G*center_mass*(x2-x1))/pow((pow((x2-x1),2)+pow((y2-y1),2)),1.5);

        return a_x;
    }

    double computeYAccel(double x1,double y1, double x2, double y2, double center_mass){
        double a_y = (G*center_mass*(y2-y1))/pow((pow((x2-x1),2)+pow((y2-y1),2)),1.5);

        return a_y;
    }

    void calcRK4(double delT, double x1, double y1,
                 double x2, double y2, double vx, double vy,
                 double center_mass,
                 double k[]){


        double k1_x, k1_y, k1_vx, k1_vy;
        double k2_x, k2_y, k2_vx, k2_vy;
        double k3_x, k3_y, k3_vx, k3_vy;
        double k4_x, k4_y, k4_vx, k4_vy;

        k1_x = vx;
        k1_y = vy;
        k1_vx = computeXAccel(x1,y1,x2,y2, center_mass);
        k1_vy = computeYAccel(x1,y1,x2,y2, center_mass);

        k2_x = vx + (delT/2)*k1_vx;
        k2_y = vy + (delT/2)*k1_vy;
        k2_vx = computeXAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y),x2,y2, center_mass);
        k2_vy = computeYAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y),x2,y2, center_mass);

        k3_x = vx + (delT/2)*k2_vx;
        k3_y = vy + (delT/2)*k2_vy;
        k3_vx = computeXAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y),x2,y2, center_mass);
        k3_vy = computeYAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y),x2,y2, center_mass);

        k4_x = vx + delT*k3_vx;
        k4_y = vy + delT*k3_vy;
        k4_vx = computeXAccel((x1+delT*k3_x), (y1+delT*k3_y),x2,y2,center_mass);
        k4_vy = computeYAccel((x1+delT*k3_x), (y1+delT*k3_y),x2,y2,center_mass);

        k[0] = k1_x;
        k[1] = k1_y;
        k[2] = k1_vx;
        k[3] = k1_vy;

        k[4] = k2_x;
        k[5] = k2_y;
        k[6] = k2_vx;
        k[7] = k2_vy;

        k[8] = k3_x;
        k[9] = k3_y;
        k[10] = k3_vx;
        k[11] = k3_vy;

        k[12] = k4_x;
        k[13] = k4_y;
        k[14] = k4_vx;
        k[15] = k4_vy;

    }







};


