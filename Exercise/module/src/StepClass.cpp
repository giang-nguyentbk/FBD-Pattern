#include <vector>
#include "../header/StepClass.h"

using namespace std;

Step::Step(double r) : m_R(r) {
    m_output.push_back(new double[1]);
}

void Step::execute() {
    *(m_output[0]) = m_R;
}