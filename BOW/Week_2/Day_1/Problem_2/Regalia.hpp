#include <bits/stdc++.h>
using namespace std;

/*
    Security Check
*/
#ifndef SOLAR_INVERTER_HPP
#include "SolarInverter.hpp"
#endif

/*
    Parent Class : SolarInverter 
    Child Class  : Regalia 
*/
class Regalia : public SolarInverter{
    public:
        /*
            Regalia Constructor
            
        */
        Regalia(double current, double voltage) : SolarInverter(current, voltage, false, false){}

        /*
            getInverterType is overridden method of Inverter Base class
        
        */
        string getInverterType() const override{
            
            return "Regalia Solar Inverter";

        }
};