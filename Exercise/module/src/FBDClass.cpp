#include <vector>
#include "../header/FBClass.h"
#include "../header/FBDClass.h"

using namespace std;

FBD::FBD(double ts) : Ts(ts>0 ? ts : 1), running(true) {}

FBD::~FBD() {
    for(int i=0; i<size(); i++) {
        delete at(i);
    }
}

void FBD::addFB(FB* p) {
    push_back(p);
}

void FBD::connect(int fb1, int fb2, int fb1_outport, int fb2_inport) {
    FB* pFB1 = at(fb1);
    FB* pFB2 = at(fb2);
    pFB2->setInputPort(pFB1->getOutputPort(fb1_outport), fb2_inport);
}

void FBD::start() {
    while(running) {
        for(int i=0; i<size(); i++) {
            at(i)->execute();
        }
    }
}

void FBD::stop() {
    running = false;
}