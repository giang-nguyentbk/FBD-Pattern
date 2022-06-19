#include <iostream>
#include "../header/FBD_class.h"
using namespace std;

FB::~FB() {
    for(int i=0; i<input.size(); i++) {
        delete input.at(i);
        cout << "Deleted input at " << i << endl;
    }
    for(int i=0; i<output.size(); i++) {
        delete output.at(i);
        cout << "Deleted output at " << i << endl;
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
    if(i>= 0 && i < output.size())
        input[i] = pFromOutputPort;
    else {
        cout << "input at " << i << "out of range!" << endl;
    }
}

Step::Step(double r) : R(r) {
    output.push_back(new double[1]);
    cout << "Created output at " << output[0] << endl;
    execute();
}

void Step::execute() {
    *(output[0]) = R;
    cout << "Output: " << *(output[0]) << endl;
}

// void Sum::addInput(bool sign) {

// }

// void Sum::execute() {

// }

// Sum::Sum(bool plus_sign1 = true, bool plus_sign2 = false){

// }

// double* Sum::getOutputPort(int i=0) {

// }

// void Sum::setInputPort(double* pFromOutputPort, int i=0) {
    
// }

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