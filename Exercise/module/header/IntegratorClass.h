#ifndef _INTEGRATOR_CLASS_H_
#define _INTEGRATOR_CLASS_H_

#include "FBClass.h"

class Integrator : public FB {
    private:
        double m_Ti, m_Ts;
        void execute();
    public:
        Integrator(double ti=5, double ts=0.5);
};

#endif // _INTEGRATOR_CLASS_H_