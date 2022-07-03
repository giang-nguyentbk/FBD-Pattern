#include <iostream>
#include <vector>
#include "../header/FBClass.h"

using namespace std;

FB::~FB() {
    for(int i=0; i<m_output.size(); i++) {
        delete m_output[i];
    }
}

double* FB::getOutputPort(int i) {
    if(i>=0 && i < m_output.size()) {
        return m_output[i];
    } else {
        return nullptr;
        cout << "Output at " << i << " is out of range!" << endl;
    }
}

void FB::setInputPort(double* pFromOutputPort, int i) {
    if(i>=0 && i < m_input.size()) {
        m_input[i] = pFromOutputPort;
    } else {
        cout << "Input at " << i << " is out of range!" << endl;
    }
}