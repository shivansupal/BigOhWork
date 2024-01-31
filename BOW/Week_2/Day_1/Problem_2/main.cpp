#include <bits/stdc++.h>
using namespace std;

#include "PCU.hpp"  //header of PCU 
#include "GTI.hpp"  //header of GTI 
#include "Regalia.hpp"  //header of Regalia 
#include "Zelio.hpp"    //header of Zelio 
#include "iCruze.hpp"   //header of iCruze 

/*
    Test Cases for checking
*/
void test(){
    PCU pcu(13, 220);
    GTI gti(5, 220);
    Regalia regalia(9, 220);
    Zelio zelio(2, 220);
    iCruze icruze(19, 200);

    cout<<"Test Case"<<endl;
    cout<<"Type of Inverter is = "<<pcu.getInverterType()<<" Power Rating : "<<pcu.getPowerRating()<<" Watt "<<endl;
    cout<<"Type of Inverter is = "<<gti.getInverterType()<<" Power Rating : "<<gti.getPowerRating()<<" Watt "<<endl;
    cout<<"Type of Inverter is = "<<regalia.getInverterType()<<" Power Rating : "<<regalia.getPowerRating()<<" Watt "<<endl;
    cout<<"Type of Inverter is = "<<zelio.getInverterType()<<" Power Rating : "<<zelio.getPowerRating()<<" Watt "<<endl;
    cout<<"Type of Inverter is = "<<icruze.getInverterType()<<" Power Rating : "<<icruze.getPowerRating()<<" Watt "<<endl;
                    
}

int main()
{
    test(); //Testing
    return 0;
}