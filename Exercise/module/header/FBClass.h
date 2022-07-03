#ifndef _FB_CLASS_H_
#define _FB_CLASS_H_

#include <vector>
#include "FBDClass.h"
using namespace std;

class FB {
    protected:
        vector<double*> m_input;
        vector<double*> m_output;
        virtual void execute() = 0;
        double* getOutputPort(int i=0);
        void setInputPort(double* pFromOutputPort, int i=0);
        friend class FBD;
    public:
        ~FB();

};

#endif //_FB_CLASS_H_