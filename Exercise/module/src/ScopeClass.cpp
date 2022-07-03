#include <iostream>
#include <vector>
#include <cmath>
#include "../header/ScopeClass.h"

// For Windows MinGW
#include <Windows.h>
// For Linux 
/* #include <chrono>
#include <thread>
*/

using namespace std;

Scope::Scope(int numChannel) : m_numChannel(numChannel) {
    m_input.assign(m_numChannel, nullptr);    
}

void Scope::execute() {
    if(nullptr != m_input[0]) {
        for(int i=0; i<m_numChannel; i++) {
            cout << "[Scope 0] Channel " << i << ": " << *(m_input[i]) << endl;
        }
    } else {
        cout << "Scope: Input at 0 hasn't connected yet!" << endl;
    }
}