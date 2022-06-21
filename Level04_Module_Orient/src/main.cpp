#include <iostream>
#include <vector>
#include "../module/header/FBD_class.h"
using namespace std;

int main() {
    double Ts = 0.5;
    vector<bool> sign{true, false};

    FBD fbd(Ts);
    fbd.addFB(new Step(1)); //0
    fbd.addFB(new Sum(sign)); //1
    fbd.addFB(new Gain(1)); //2
    fbd.addFB(new Limiter(10, -10)); //3
    fbd.addFB(new Integrator(10, Ts)); //4
    fbd.addFB(new Delay(2*Ts, Ts)); //5
    fbd.addFB(new Scope(1)); //6
    fbd.connect(0, 1, 0, 0);
    fbd.connect(5, 1, 0, 1);
    fbd.connect(1, 2, 0, 0);
    fbd.connect(2, 3, 0, 0);
    fbd.connect(3, 4, 0, 0);
    fbd.connect(4, 5, 0, 0);
    fbd.connect(5, 6, 0, 0);
    fbd.start();

    return 0;
}