#ifndef _LIMITER_CLASS_H_
#define _LIMITER_CLASS_H_

#include "FBClass.h"

class Limiter : public FB {
    private:
        double m_Hi, m_Lo;
        void execute();
    public:
        Limiter(double hi=10, double lo=-10);
};

#endif // _LIMITER_CLASS_H_