#ifndef _FBD_CLASS_H_
#define _FBD_CLASS_H_

#include <vector>
using namespace std;

class FB {
    public:
        ~FB();
    protected:
        vector<double*> input;
        vector<double*> output;
        virtual void execute() = 0;
        double* getOutputPort(int i=0);
        void setInputPort(double* pFromOutputPort, int i=0);
        friend class FBD;
};

class Step : public FB {
    public:
        Step(double r=1);
    private:
        double R;
        void execute();
};

class Sum : public FB {
    public:
        Sum(vector<bool> psign);
    private:
        vector<bool> sign;
        void execute();
};

class Gain : public FB {
    public:
        Gain(double k=1);
    private:
        double K;
        void execute();
};

class Limiter : public FB {
    public:
        Limiter(double hi=10, double lo=-10);
    private:
        double Hi, Lo;
        void execute();
};

class Integrator : public FB {
    public:
        Integrator(double ti=5, double ts=0.5);
    private:
        double Ti, Ts;
        void execute();
};

class Sample : public FB {
    public:
        Sample(double ts=0.5);
    private:
        double Ts;
        void execute();
};

class Scope : public FB {
    public:
        Scope();
    private:
        void execute();
};

class Delay : public FB {
    public:
        Delay(double td=0, double ts=1);
    private:
        vector<double> buffer;
        int buffsize;
        double Td, Ts;
        void execute();
        void createBuffer(int size);
};

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

#endif //_FBD_CLASS_H_