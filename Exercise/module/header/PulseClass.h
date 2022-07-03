#ifndef _PULSE_CLASS_H_
#define _PULSE_CLASS_H_

#include <vector>
#include "FBClass.h"
using namespace std;

class Pulse : public FB {
    private:
        double m_Amp, m_Tck, m_Ts;
        int m_count;
        void execute();
    public:
        Pulse(double amp=0.2, double tck=0.1, double ts=0.5);
};

#endif // _PULSE_CLASS_H_