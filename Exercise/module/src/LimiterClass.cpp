#include <iostream>
#include <vector>
#include "../header/LimiterClass.h"

using namespace std;

Limiter::Limiter(double hi, double lo) : m_Hi(hi), m_Lo(lo) {
    m_input.assign(1, nullptr);
    m_output.push_back(new double[1]);
}

void Limiter::execute() {
    if(nullptr != m_input[0]) {
        if(*(m_input[0]) > m_Hi) {
            *(m_output[0]) = m_Hi;
        } else if (*(m_input[0]) < m_Lo) {
            *(m_output[0]) = m_Lo;
        } else {
            *(m_output[0]) = *(m_input[0]);
        }
        
    } else {
        cout << "Limiter: Input at 0 hasn't connected yet!" << endl;
    }
}