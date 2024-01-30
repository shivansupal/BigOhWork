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
    PCU pcu(10.0, 220.0);
    GTI gti(9.0, 220);
    Regalia regalia(8.0, 220);
    Zelio zelio(7.0, 220);
    iCruze icruze(6.0, 200);

    cout<<"Test Case"<<endl;
    cout<<"Inveter Type : "<<pcu.getInverterType()<<" Power Rating : "<<pcu.getPowerRating()<<" Watt "<<endl;
    cout<<"Inveter Type : "<<gti.getInverterType()<<" Power Rating : "<<gti.getPowerRating()<<" Watt "<<endl;
    cout<<"Inveter Type : "<<regalia.getInverterType()<<" Power Rating : "<<regalia.getPowerRating()<<" Watt "<<endl;
    cout<<"Inveter Type : "<<zelio.getInverterType()<<" Power Rating : "<<zelio.getPowerRating()<<" Watt "<<endl;
    cout<<"Inveter Type : "<<icruze.getInverterType()<<" Power Rating : "<<icruze.getPowerRating()<<" Watt "<<endl;
                    
}

int main(int argc, char const *argv[])
{
    test(); //Testing
    return 0;
}