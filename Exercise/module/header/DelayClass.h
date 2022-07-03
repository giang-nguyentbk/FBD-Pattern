#ifndef _DELAY_CLASS_H_
#define _DELAY_CLASS_H_

#include <vector>
#include "FBClass.h"
using namespace std;

class Delay : public FB {
    private:
        double m_Td, m_Ts;
        vector<double> m_buffer;
        void execute();
    public:
        Delay(double td=1, double ts=0.5);
};

#endif // _DELAY_CLASS_H_