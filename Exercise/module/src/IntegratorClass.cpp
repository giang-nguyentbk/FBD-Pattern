#include <iostream>
#include <vector>
#include "../header/IntegratorClass.h"

using namespace std;

Integrator::Integrator(double ti, double ts) : m_Ti(ti), m_Ts(ts) {
    m_input.assign(1, nullptr);
    m_output.push_back(new double[1]);
}

void Integrator::execute() {
    if(nullptr != m_input[0]) {
        *(m_output[0]) += *(m_input[0])*m_Ts/m_Ti;
    } else {
        cout << "Integrator: Input at 0 hasn't connected yet!" << endl;
    }
}