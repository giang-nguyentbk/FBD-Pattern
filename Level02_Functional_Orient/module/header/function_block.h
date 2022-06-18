#ifndef _FUNCTION_BLOCK_H_
#define _FUNCTION_BLOCK_H_

double step(double step);
double sum(double input1, double input2);
double gain(double K, double input);
double limit(double Hi, double Lo, double input);
double integrate(double Ti, double Ts, double input);
void scope(double ouput);
void sampling(double Ts);

#endif //_FUNCTION_BLOCK_H_