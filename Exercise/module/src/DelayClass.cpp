#include <iostream>
#include <vector>
#include <cmath>
#include "../header/DelayClass.h"

// For Windows MinGW
#include <Windows.h>
// For Linux 
/* #include <chrono>
#include <thread>
*/

using namespace std;

Delay::Delay(double td, double ts) : m_Td(td), m_Ts(ts) {
    if(m_Td >= 0 && m_Ts > 0) {
        m_buffer.assign((int) ceil(m_Td/m_Ts), 0);
    } else {
        m_buffer.assign(1, 0);
    }
    m_input.assign(1, nullptr);
    m_output.push_back(new double[1]);
    
}

void Delay::execute() {
    if(nullptr != m_input[0]) {
        *(m_output[0]) = m_buffer[0];
        for(int i=0; i<m_buffer.size()-1; i++) {
            m_buffer[i] = m_buffer[i+1];
        }
        m_buffer[m_buffer.size()-1] = *(m_input[0]);
        Sleep((unsigned long)(m_Ts*1000)); // For Windows MinGW
            // this_thread::sleep_for(chrono::milliseconds((unsigned long)(Ts*1000))); // For Linux
        
    } else {
        cout << "Delay: Input at 0 hasn't connected yet!" << endl;
    }
}