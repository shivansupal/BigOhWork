#include<bits/stdc++.h>
using namespace std;

/*
    Security Check for non repeatation
*/
#ifndef INVERTER_HPP
#include "Inverter.hpp"
#endif
#ifndef SOLAR_INVERTER_HPP
#define SOLAR_INVERTER_HPP 1

/*
    Parent Class : SolarInverter 
    Child Class  : Regalia 
*/
class SolarInverter : public Inverter{
    //Visiablity Mode
    protected:
        bool has_battery;   //For batter options
        bool grid_on;   //For Grid Options
    
    public:
        /*
            SolarInverter Constructure for init.
            
        */
        SolarInverter(double current, double voltage, bool battery, bool grid) : Inverter(current,voltage){

            this->has_battery = battery;   
            this->grid_on = grid;   

        }

        /*
            getInverterType is overridden method of Inverter Base class
        */
        
        string getInverterType() const override{
            
            return "Solar Inverter";   

        }

        /*
            hasBattery method return the value of battery option i.e (Battery supported or not)
            
        */
        bool hasBattery() const {
            return this->has_battery;
        }

        /*
            isGridOn method return the value of grid option i.e (grid on or not)
            
        */
        bool isGridOn() const {
            return this->grid_on;
        }
};
#endif