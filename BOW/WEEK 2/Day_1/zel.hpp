#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for non repeatation
*/
#ifndef INVERTER_HPP
#include "Inverter.hpp"
#endif
/*
    Parent Class : Inverter 
    Child Class  : Zelio 
*/
class Zelio : public Inverter{
    public:
        /*
            Zelio Constructor for init obj.
            
        */
        Zelio(double current, double voltage) : Inverter(current, voltage) {}
        
        /*
            getInverterType is overridden method of Inverter Base class
            
        */
        string getInverterType() const override {
            return "Zelio Inverter";    //Return Type of Inverter
        }
};