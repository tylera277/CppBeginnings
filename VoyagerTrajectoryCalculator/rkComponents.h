//
// Created by Tyler Allen on 11/8/21.
//

#include <cmath>

class compute{
public:

    double G = 6.67e-11;
    double M_sun = 1.989e30;


    double computeXAccel(double x,double y){
        double a_x = -(G*M_sun*x)/pow((pow(x,2)+pow(y,2)),1.5);

        return a_x;
    }

    double computeYAccel(double x,double y){
        double a_y = -(G*M_sun*y)/pow((pow(x,2)+pow(y,2)),1.5);

        return a_y;
    }

};
