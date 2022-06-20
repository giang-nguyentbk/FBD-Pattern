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

// class Gain : public FB {
//     public:
//         Gain(double k=1);
//         void execute();
//     private:
//         double K;
//         double* in[1];
//         double* out[1];
//         double* getOutputPort(int i=0);
//         void setInputPort(double* pFromOutputPort, int i=0);
// };

// class Limiter : public FB {
//     public:
//         Limiter(double hi=10, double lo=-10);
//         void execute();
//     private:
//         double Hi, Lo;
//         double* in[1];
//         double* out[1];
//         double* getOutputPort(int i=0);
//         void setInputPort(double* pFromOutputPort, int i=0);
// };

// class Integrator : public FB {
//     public:
//         Integrator(double ti=5, double ts=0.5);
//         void execute();
//     private:
//         double Ti, Ts;
//         double* in[1];
//         double* out[1];
//         double* getOutputPort(int i=0);
//         void setInputPort(double* pFromOutputPort, int i=0);
// };

// class Sample : public FB {
//     public:
//         Sample(double ts=0.5);
//         void execute();
//     private:
//         double Ts;
//         double* in[1];
//         double* out[1];
//         double* getOutputPort(int i=0);
//         void setInputPort(double* pFromOutputPort, int i=0);
// };

// class Scope : public FB {
//     public:
//         void execute();
//     private:
//         double* in[1];
//         double* getOutputPort(int i=0);
//         void setInputPort(double* pFromOutputPort, int i=0);
// };

#endif //_FBD_CLASS_H_