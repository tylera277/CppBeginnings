//
// Created by Tyler Allen on 11/9/21.
//
// This houses the initial conditions for each of the planets

class InitConditions{
public:

    void getInitialConditions(const std::string planet, double conds[]){

        if(planet == "earth"){
            conds[0] = 1.01e11;
            conds[1] = 1.08e11;
            conds[2] = -22100;
            conds[3] = 20380;
        }else if(planet == "jupiter"){
            conds[0] = 6.73e11;
            conds[1] = -3.26e11;
            conds[2] = 5.54e3;
            conds[3] = 1.24e4;
        }else if(planet == "neptune"){
            conds[0] = 4.428e12;
            conds[1] = -6.362e11;
            conds[2] = 7.37e2;
            conds[3] = 5.413e3;
        }


    }

};
