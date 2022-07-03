#ifndef _SCOPE_CLASS_H_
#define _SCOPE_CLASS_H_

#include <vector>
#include "FBClass.h"
using namespace std;

class Scope : public FB {
    private:
        int m_numChannel;
        void execute();
    public:
        Scope(int numChannel=1);
};

#endif // _SCOPE_CLASS_H_