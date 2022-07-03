#ifndef _GAIN_CLASS_H_
#define _GAIN_CLASS_H_

#include "FBClass.h"

class Gain : public FB {
    private:
        double m_K;
        void execute();
    public:
        Gain(double k=1);
};

#endif // _GAIN_CLASS_H_