#include <iostream>
#include <vector>
#include <cmath>
#include "../header/PulseClass.h"

// For Windows MinGW
#include <Windows.h>
// For Linux 
/* #include <chrono>
#include <thread>
*/

using namespace std;

Pulse::Pulse(double amp, double tck, double ts) : m_Amp(amp), m_Tck(tck), m_Ts(ts), m_count(0) {
    m_output.push_back(new double[1]);
}

void Pulse::execute() {
    if(m_count >= 1000) {
        m_count = 0;
    }
    m_count += 1;
    if((int) floor(m_count*m_Ts/m_Tck) % 2 == 0) {
        *(m_output[0]) = m_Amp;
    } else {
        *(m_output[0]) = 0;
    }
    
}