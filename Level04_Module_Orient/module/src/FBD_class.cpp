#include <iostream>
// For Windows MinGW
#include <Windows.h>
// For Linux 
/* #include <chrono>
#include <thread>
*/
#include "../header/FBD_class.h"
using namespace std;

FB::~FB() {
    // for(int i=0; i<input.size(); i++) {
    //     delete input.at(i);
    //     cout << "Deleted input at " << i << endl;
    // }
    for(int i=0; i<output.size(); i++) {
        delete output.at(i);
    }
}

double* FB::getOutputPort(int i) {
    if(i>= 0 && i < output.size())
        return output.at(i);
    else {
        cout << "Get output at " << i << "out of range!" << endl;
        return nullptr;
    }
}

void FB::setInputPort(double* pFromOutputPort, int i) {
    if(i>= 0 && i < input.size())
        input[i] = pFromOutputPort;
    else {
        cout << "Set input at " << i << " out of range!" << endl;
    }
}

Step::Step(double r) : R(r) {
    output.push_back(new double[1]);
}

void Step::execute() {
    *(output[0]) = R;
}

Sum::Sum(vector<bool> psign) {
    sign = psign;
    input.assign(psign.size(), nullptr);
    output.push_back(new double[1]);
}

void Sum::execute() {
    *(output[0]) = 0;
    for(int i=0; i<input.size(); i++) {
        if(nullptr != input[i]) {
            *(output[0]) += sign[i] ? *(input[i]) : -*(input[i]);
        } else {
            cout << "Sum: Input " << i << " is not connected!" << endl;
            return;
        }
    }
}

Gain::Gain(double k) {
    K = k;
    input.assign(1, nullptr);
    output.push_back(new double[1]);
    *(output[0]) = 0;
}

void Gain::execute() {
    if(nullptr != input[0]) {
        *(output[0]) = K*(*(input[0]));
    } else {
        cout << "Gain: Input is not connected!" << endl;
    }   
}

Limiter::Limiter(double hi, double lo) {
    Hi = hi;
    Lo = lo;
    input.assign(1, nullptr);
    output.push_back(new double[1]);
    *(output[0]) = 0;
}

void Limiter::execute() {
    if(nullptr != input[0]) {
        if(*(input[0]) > Hi) *(output[0]) = Hi;
        else if(*(input[0]) < Lo) *(output[0]) = Lo;
        else *(output[0]) = *(input[0]);
    } else {
        cout << "Limiter: Input is not connected!" << endl;
    }   
}

Integrator::Integrator(double ti, double ts) {
    Ti = ti;
    Ts = ts;
    input.assign(1, nullptr);
    output.push_back(new double[1]);
    *(output[0]) = 0;
}

void Integrator::execute() {
    if(nullptr != input[0]) {
        *(output[0]) += *(input[0])*Ts/Ti;
    } else {
        cout << "Integrator: Input is not connected!" << endl;
    }   
}

Sample::Sample(double ts) {
    Ts = ts;
    input.assign(1, nullptr);
    output.push_back(new double[1]);
    *(output[0]) = 0;
}

void Sample::execute() {
    if(nullptr != input[0]) {
        Sleep((unsigned long)(Ts*1000)); // For Windows MinGW
        // this_thread::sleep_for(chrono::milliseconds((unsigned long)(Ts*1000))); // For Linux

        *(output[0]) = *(input[0]);
    } else {
        cout << "Sample: Input is not connected!" << endl;
    }   
}

Scope::Scope() {
    input.assign(1, nullptr);
}

void Scope::execute() {
    if(nullptr != input[0]) {
        cout << "Scope: Output = " << *(input[0]) << endl; 
    } else {
        cout << "Scope: Input is not connected!" << endl;
    }   
}

FBD::FBD(double ts) : Ts(ts>0 ? ts : 1), running(true) {}

FBD::~FBD() {
    for(int i=0; i<size(); i++) {
        delete at(i);
    }
}

void FBD::addFB(FB* p) {
    push_back(p);
}

void FBD::connect(int fb1, int fb2, int fb1_outport, int fb2_inport) {
    FB* pFB1 = at(fb1);
    FB* pFB2 = at(fb2);
    pFB2->setInputPort(pFB1->getOutputPort(fb1_outport), fb2_inport);
}

void FBD::start() {
    while(running) {
        for(int i=0; i<size(); i++) {
            at(i)->execute();
        }
    }
}

void FBD::stop() {
    running = false;
}