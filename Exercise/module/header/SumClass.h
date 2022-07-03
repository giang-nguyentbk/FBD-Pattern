#ifndef _SUM_CLASS_H_
#define _SUM_CLASS_H_

#include "FBClass.h"

class Sum : public FB {
    private:
        vector<bool> m_sign;
        void execute();
    public:
        Sum(vector<bool> sign);
};

#endif // _SUM_CLASS_H_