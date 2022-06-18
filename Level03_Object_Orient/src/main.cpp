#include <iostream>
#include <csignal>
#include "../module/header/block_class.h"
using namespace std;

bool running = true;

static void signal_handler(int signum) {
    cout << "Shutting down ... " << endl;
    running = false;
}

int main(int argc, char **argv) {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    double K = 1, Hi = 10, Lo = -10,  Ti = 5, Ts = 0.5;

    Step step;
    Sum sum;
    Gain gain(K);
    Limiter limiter(Hi, Lo);
    Integrator integrator(Ti, Ts);
    Scope scope;
    Sample sample;

    double r = 0, e = 0, ug = 0, ul = 0, ui = 0, y = 0;
    
    while(running) {
        // Step
        r = step(1);
        // Sum
        e = sum(r, -y);
        // StaticGain
        ug = gain(e);
        // Limiter
        ul = limiter(ug);
        // Integrator
        ui = integrator(ul);
        y = ui;
        // Scope
        scope(y);
        // Sampling
        sample(Ts);
    }

    return 0;
}