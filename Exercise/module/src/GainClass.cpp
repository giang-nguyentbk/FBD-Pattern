#include <iostream>
#include <vector>
#include "../header/GainClass.h"

using namespace std;

Gain::Gain(double k) : m_K(k) {
    m_input.assign(1, nullptr);
    m_output.push_back(new double[1]);
}

void Gain::execute() {
    if(nullptr != m_input[0]) {
        *(m_output[0]) = m_K*(*(m_input[0]));
    } else {
        cout << "Gain: Input at 0 hasn't connected yet!" << endl;
    }
}