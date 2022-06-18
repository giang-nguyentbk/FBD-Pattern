#include <iostream>
// For Windows MinGW
#include <Windows.h>
// For Linux 
/* #include <chrono>
#include <thread>
*/
#include "../header/function_block.h"

using namespace std;

double step(double step) {
    return step;
}

double sum(double input1, double input2) {
    return input1 + input2;
}

double gain(double K, double input) {
    return K*input;
}

double limit(double Hi, double Lo, double input) {
    if(input > Hi) input = Hi;
    if(input < Lo) input = Lo;
    return input;
}

double integrate(double Ti, double Ts, double input) {
    static double ui = 0;
    ui += input*Ts/Ti;
    return ui;
}

void scope(double output) {
    cout << "Output: " << output << endl;
}

void sampling(double Ts) {
    Sleep((unsigned long)(Ts*1000)); // For Windows MinGW
    // this_thread::sleep_for(chrono::milliseconds((unsigned long)(Ts*1000))); // For Linux
}