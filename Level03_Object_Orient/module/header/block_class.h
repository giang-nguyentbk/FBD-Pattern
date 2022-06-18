#ifndef _BLOCK_CLASS_H_
#define _BLOCK_CLASS_H_

class Step {
    public:
        double operator()(double step);
};

class Sum {
    public:
        double operator()(double input1, double input2);
};

class Gain {
    private:
        double K;
    public:
        Gain(double k = 1) : K(k) {}
        double operator()(double input);
};

class Limiter {
    private:
        double Hi, Lo;
    public:
        Limiter(double hi = 10, double lo = -10) : Hi(hi), Lo(lo) {}
        double operator()(double input);
};

class Integrator {
    private:
        double Ti, Ts;
        double I;
    public:
        Integrator(double ti, double ts) : Ti(ti), Ts(ts), I(0) {}
        double operator()(double input);
};

class Sample {
    public:
        void operator()(double Ts);
};

class Scope {
    public:
        void operator()(double output);
};

#endif //_BLOCK_CLASS_H_