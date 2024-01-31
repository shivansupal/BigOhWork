#include <iostream>
#include <vector>
using namespace std;

#include "MP.hpp"
#include "minister.hpp"
#include "pm.hpp"
#include " commissioner.hpp"

int main() {
    MP mp("Constituency1");
    Minister minister("Constituency2");
    PM pm("Constituency3");

    Commissioner commissioner;

    commissioner.canArrest(mp);
    commissioner.canArrest(minister, pm);

    return 0;
}