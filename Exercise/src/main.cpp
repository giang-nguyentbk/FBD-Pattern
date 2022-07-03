#include <iostream>
#include <vector>
#include "../module/header/FBDclass.h"
#include "../module/header/StepClass.h"
#include "../module/header/SumClass.h"
#include "../module/header/GainClass.h"
#include "../module/header/LimiterClass.h"
#include "../module/header/IntegratorClass.h"
#include "../module/header/DelayClass.h"
#include "../module/header/PulseClass.h"
#include "../module/header/ScopeClass.h"

using namespace std;

int main() {
    double Ts = 0.5;
    vector<bool> sign1{true, false};
    vector<bool> sign2{true, true};

    FBD fbd(Ts);

    fbd.addFB(new Step(1)); //0
    fbd.addFB(new Sum(sign1)); //1
    fbd.addFB(new Gain(1.5)); //2
    fbd.addFB(new Limiter(10, -10)); //3
    fbd.addFB(new Integrator(10, Ts)); //4
    fbd.addFB(new Delay(3*Ts, Ts)); //5
    fbd.addFB(new Sum(sign2)); //6
    fbd.addFB(new Scope(2)); //7
    fbd.addFB(new Pulse(0.2, 0.3, Ts)); //8

    for(int i=0; i<7; i++) {
        fbd.connect(i, i+1, 0, 0);
    }

    fbd.connect(6, 1, 0, 1); // Sum1-Sum2
    fbd.connect(3, 7, 0, 1); // Limiter-Scope
    fbd.connect(8, 6, 0, 1); // Pulse-Sum2 

    fbd.start();

    return 0;
}