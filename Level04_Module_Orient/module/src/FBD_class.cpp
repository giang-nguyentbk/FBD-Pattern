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
        cout << "output at " << i << "out of range!" << endl;
        return nullptr;
    }
}

void FB::setInputPort(double* pFromOutputPort, int i) {
    if(i>= 0 && i < input.size())
        input[i] = pFromOutputPort;
    else {
        cout << "input at " << i << " out of range!" << endl;
    }
}

Step::Step(double r) : R(r) {
    output.push_back(new double[1]);
}

void Step::execute() {
    *(output[0]) = R;
    cout << "Step output = " << *(output[0]) << endl;
}

Sum::Sum(vector<bool> psign) {
    sign = psign;
    input.assign(psign.size(), nullptr);
    output.push_back(new double[1]);
    *(output[0]) = 0;
}

void Sum::execute() {
    *(output[0]) = 0;
    for(int i=0; i<input.size(); i++) {
        if(nullptr != input[i]) {
            *(output[0]) += sign[i] ? *(input[i]) : -*(input[i]);
        } else {
            cout << "Input " << i << " is not connected!" << endl;
        }
    }
    cout << "Sum output = " << *(output[0]) << endl;    
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
        Sleep((unsigned long)(Ts*1000)); // For Windows MinGW
        // this_thread::sleep_for(chrono::milliseconds((unsigned long)(Ts*1000))); // For Linux
    }
}

void FBD::stop() {
    running = false;
}

// Gain::Gain(double k=1){

// }

// void Gain::execute() {

// }

// double* Gain::getOutputPort(int i=0) {

// }

// void Gain::setInputPort(double* pFromOutputPort, int i=0) {
    
// }

// Limiter::Limiter(double hi=10, double lo=-10){

// }

// void Limiter::execute() {

// }

// double* Limiter::getOutputPort(int i=0) {

// }

// void Limiter::setInputPort(double* pFromOutputPort, int i=0) {
    
// }

// Integrator::Integrator(double ti=5, double ts=0.5){

// }

// void Integrator::execute() {

// }

// double* Integrator::getOutputPort(int i=0) {

// }

// void Integrator::setInputPort(double* pFromOutputPort, int i=0) {
    
// }

// Sample::Sample(double ts=0.5){

// }

// void Sample::execute() {

// }

// double* Sample::getOutputPort(int i=0) {

// }

// void Sample::setInputPort(double* pFromOutputPort, int i=0) {
    
// }