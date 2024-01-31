//Driver code

#include <iostream>
#include <vector>
using namespace std;

//Including HPP files of all class
#include "MP.hpp"
#include "minister.hpp"
#include "pm.hpp"
#include " commissioner.hpp"

//main function execution start here

int main() {
    MP mp("Constituency1");
    Minister minister("Constituency2");
    PM pm("Constituency3");

    Commissioner commissioner;

    commissioner.canArrest(mp);
    commissioner.canArrest(minister, pm);

    return 0;
}
