#include<bits/stdc++.h>
using namespace std;

//Driver code

#ifndef INVERTER_HPP
#define INVERTER_HPP 1


/*
     for all kind or inverter
*/
class Inverter{
    //Data Member
    protected:
        double current; //for current
        double voltage;   //for voltage
        double power;    //for power
    
    public:
        /*
            Abstract class Inverter Constructor for init
            
        */
        Inverter(double current, double voltage){
            this->current = current;
            this->voltage = voltage;
            this->power = current * voltage;
        }

        /*
            getPowerRating method returns the rating of Inverter
                       
        */
        double getPowerRating() const{
            return this->power;
        }
        /*
            Virtual fucntion for drived class to override it
            @param : void
            @return : string
        */
        virtual string getInverterType() const {
            return "Generic Inverter";
        }
};

#endif