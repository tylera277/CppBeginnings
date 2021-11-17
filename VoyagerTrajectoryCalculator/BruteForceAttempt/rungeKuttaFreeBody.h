//
// Created by Tyler Allen on 11/12/21.
//

class RungeKuttaFreeBody{
public:

    double G = 6.67e-11;

    double computeXAccel(double x1,double y1, double x2, double y2, double center_mass){
        double a_x = (G*center_mass*(x2-x1))/pow((pow((x2-x1),2)+pow((y2-y1),2) + 0.001),1.5);

        return a_x;
    }

    double computeYAccel(double x1,double y1, double x2, double y2, double center_mass){
        double a_y = (G*center_mass*(y2-y1))/pow((pow((x2-x1),2)+pow((y2-y1),2)+0.001),1.5);

        return a_y;
    }

    void RK4freebody(double delT, double x1, double y1, double vx1, double vy1,
                     double xSun, double ySun, double mass_sun,
                     double x2, double y2, double mass2,
                     double x3, double y3, double mass3,
                     double x4, double y4, double mass4,
                     double x5, double y5, double mass5,
                     double k[]){

        double k1_x, k1_y, k1_vx, k1_vy;
        double k2_x, k2_y, k2_vx, k2_vy;
        double k3_x, k3_y, k3_vx, k3_vy;
        double k4_x, k4_y, k4_vx, k4_vy;

        k1_x = vx1;
        k1_y = vy1;
        k1_vx = computeXAccel(x1,y1,xSun,ySun, mass_sun) + computeXAccel(x1,y1,x2,y2,mass2) +
                computeXAccel(x1,y1,x3,y3,mass3)+ computeXAccel(x1,y1,x4,y4,mass4) +
                computeXAccel(x1,y1,x5,y5,mass5);


        k1_vy = computeYAccel(x1,y1,xSun,ySun, mass_sun) + computeYAccel(x1,y1,x2,y2,mass2) +
                computeYAccel(x1,y1,x3,y3,mass3) + computeYAccel(x1,y1,x4,y4,mass4) +
                computeYAccel(x1,y1,x5,y5,mass5);

        k2_x = vx1 + (delT/2)*k1_vx;
        k2_y = vy1 + (delT/2)*k1_vy;
        k2_vx = computeXAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y),xSun,ySun, mass_sun) +
                computeXAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y),x2,y2,mass2 )+
                computeXAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y), x3,y3,mass3)+
                computeXAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y), x4,y4,mass4)+
                computeXAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y), x5,y5,mass5);


        k2_vy = computeYAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y),xSun,ySun, mass_sun) +
                computeYAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y),x2,y2,mass2 )+
                computeYAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y), x3,y3,mass3)+
                computeYAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y), x4,y4,mass4)+
                computeYAccel((x1+(delT/2)*k1_x), (y1+(delT/2)*k1_y), x5,y5,mass5);


        k3_x = vx1 + (delT/2)*k2_vx;
        k3_y = vy1 + (delT/2)*k2_vy;
        k3_vx = computeXAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y),xSun,ySun, mass_sun) +
                computeXAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y),x2,y2,mass2 )+
                computeXAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y), x3,y3,mass3)+
                computeXAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y), x4,y4,mass4)+
                computeXAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y), x5,y5,mass5);


        k3_vy = computeYAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y),xSun,ySun, mass_sun) +
                computeYAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y),x2,y2,mass2 )+
                computeYAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y), x3,y3,mass3)+
                computeYAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y), x4,y4,mass4)+
                computeYAccel((x1+(delT/2)*k2_x), (y1+(delT/2)*k2_y), x5,y5,mass5);



        k4_x = vx1 + delT*k3_vx;
        k4_y = vy1 + delT*k3_vy;
        k4_vx = computeXAccel((x1+delT*k3_x), (y1+delT*k3_y),xSun,ySun, mass_sun) +
                computeXAccel((x1+delT*k3_x), (y1+delT*k3_y),x2,y2,mass2 )+
                computeXAccel((x1+delT*k3_x), (y1+delT*k3_y), x3,y3,mass3)+
                computeXAccel((x1+delT*k3_x), (y1+delT*k3_y), x4,y4,mass4)+
                computeXAccel((x1+delT*k3_x), (y1+delT*k3_y), x5,y5,mass5);



        k4_vy = computeYAccel((x1+delT*k3_x), (y1+delT*k3_y),xSun,ySun, mass_sun) +
                computeYAccel((x1+delT*k3_x), (y1+delT*k3_y),x2,y2,mass2 )+
                computeYAccel((x1+delT*k3_x), (y1+delT*k3_y), x3,y3,mass3) +
                computeYAccel((x1+delT*k3_x), (y1+delT*k3_y), x4,y4,mass4) +
                computeYAccel((x1+delT*k3_x), (y1+delT*k3_y), x5,y5,mass5);




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