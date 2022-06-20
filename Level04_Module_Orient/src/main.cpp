#include <iostream>
#include <vector>
#include "../module/header/FBD_class.h"
using namespace std;

int main() {
    double Ts = 0.5;
    vector<bool> sign{true, false};

    FBD fbd(Ts);
    fbd.addFB(new Step(10));
    fbd.addFB(new Step(5));
    fbd.addFB(new Sum(sign));
    fbd.connect(0, 2, 0, 0);
    fbd.connect(1, 2, 0, 1);
    fbd.start();

    return 0;
}