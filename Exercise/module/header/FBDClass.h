#ifndef _FBD_CLASS_H_
#define _FBD_CLASS_H_

#include <vector>
#include "FBClass.h"

using namespace std;

class FBD : public vector<FB* > {
    private:
        double Ts;
        bool running;
    public:
        FBD(double ts=0.5);
        ~FBD();
        void addFB(FB* p);
        void connect(int fb1, int fb2, int fb1_outport=0, int fb2_inport=0);
        void start();
        void stop();
};

#endif // _FBD_CLASS_H_