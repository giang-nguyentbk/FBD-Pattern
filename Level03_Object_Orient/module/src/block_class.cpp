#include <iostream>
#include "../header/block_class.h"
// For Windows MinGW
#include <Windows.h>
// For Linux 
/* #include <chrono>
#include <thread>
*/
using namespace std;

double Step::operator()(double step) {
    return step;
}

double Sum::operator()(double input1, double input2) {
    return input1 + input2;
}

double Gain::operator()(double input) {
    return K*input;
}

double Limiter::operator()(double input) {
    if(input > Hi) input = Hi;
    if(input < Lo) input = Lo;
    return input;
}

double Integrator::operator()(double input) {
    I += input*Ts/Ti;
    return I;
}

void Sample::operator()(double Ts) {
    Sleep((unsigned long)(Ts*1000)); // For Windows MinGW
    // this_thread::sleep_for(chrono::milliseconds((unsigned long)(Ts*1000))); // For Linux
}

void Scope::operator()(double output) {
    cout << "Output: " << output << endl;
}