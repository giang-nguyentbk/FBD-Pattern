#ifndef _STEP_CLASS_H_
#define _STEP_CLASS_H_

#include "FBClass.h"

class Step : public FB {
    private:
        double m_R;
        void execute();
    public:
        Step(double r=0);
};

#endif // _STEP_CLASS_H_