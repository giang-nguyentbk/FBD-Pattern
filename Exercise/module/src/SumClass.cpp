#include <iostream>
#include <vector>
#include "../header/SumClass.h"

using namespace std;

Sum::Sum(vector<bool> sign) : m_sign(sign) {
    m_input.assign(sign.size(), nullptr);
    m_output.push_back(new double[1]);
    
}

void Sum::execute() {
    *(m_output[0]) = 0;
    for(int i=0; i < m_input.size(); i++) {
        if(nullptr != m_input[i]) {
            *(m_output[0]) += m_sign[i] ? (*(m_input[i])) : -(*(m_input[i]));
        } else {
            cout << "Sum: Input at " << i << " hasn't connected yet!" << endl;
            break;
        }
    }
}