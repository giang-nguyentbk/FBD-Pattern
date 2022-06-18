#include <iostream>
#include <csignal>
#include "../module/header/function_block.h"
using namespace std;

bool running = true;

static void signal_handler(int signum) {
    cout << "Shutting down ... " << endl;
    running = false;
}

int main(int argc, char **argv) {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    double r = 0, e = 0;
    double K = 1.5, ug = 0;
    double Hi = 10, Lo = -10, ul = 0;
    double Ti = 5, Ts = 0.5, ui = 0, y = 0;

    while(running) {
        // Step
        r = step(1);
        // Sum
        e = sum(r, -y);
        // StaticGain
        ug = gain(K, e);
        // Limiter
        ul = limit(Hi, Lo, ug);
        // Integrator
        ui = integrate(Ti, Ts, ul);
        y = ui;
        // Scope
        scope(y);
        // Sampling
        sample(Ts);
    }

    return 0;
}