//
// Created by Tyler Allen on 11/8/21.
//

#include <cmath>

class compute{
public:

    double G = 6.67e-11;
    double M_sun = 1.989e30;


    double computeXAccel(double x1,double y1, double x2, double y2){
        double a_x = (G*M_sun*(x2-x1))/pow((pow((x2-x1),2)+pow((y2-y1),2)),1.5);

        return a_x;
    }

    double computeYAccel(double x1,double y1, double x2, double y2){
        double a_y = (G*M_sun*(y2-y1))/pow((pow((x2-x1),2)+pow((y2-y1),2)),1.5);

        return a_y;
    }

};
