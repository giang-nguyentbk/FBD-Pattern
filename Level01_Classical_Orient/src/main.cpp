#include <iostream>
#include <algorithm>
#include <csignal>
// For Windows MinGW
#include <Windows.h>
// For Linux 
/* #include <chrono>
#include <thread>
*/
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
        r = 1;
        // Sum
        e = r - y;
        // StaticGain
        ug = K*e;
        // Limiter
        ul = max(min(ug, Hi), Lo);
        // Integrator
        ui += ul*Ts/Ti;
        y = ui;
        // Scope
        cout << "Output: " << y << endl;
        // Sampling
        Sleep(2000); // For Windows MinGW
        // this_thread::sleep_for(chrono::milliseconds(2000)); // For Linux
    }

    return 0;
}