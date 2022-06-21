# FBD-Pattern
![alt text](./Topic/problem.png?raw=true)

1. Level 1: Classical Orientation ✅
```c++
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
    // Sample
    Sleep((unsigned long)(Ts*1000));
    // Scope
    cout << "Output: " << y << endl;
}
```

2. Level 2: Functional Orientation ✅
```c++
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
    // Sampling
    sample(Ts);
    // Scope
    scope(y);
}
```

3. Level 3: Object Orientation ✅
```c++
Step step;
Sum sum;
Gain gain(K);
Limiter limiter(Hi, Lo);
Integrator integrator(Ti, Ts);
Scope scope;
Sample sample;

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
```

4. Level 4: Module Orientation 
```c++
double Ts = 0.5;
vector<bool> sign{true, false};

FBD fbd(Ts);
fbd.addFB(new Step(1)); //0
fbd.addFB(new Sum(sign)); //1
fbd.addFB(new Gain(1)); //2
fbd.addFB(new Limiter(10, -10)); //3
fbd.addFB(new Integrator(10, Ts)); //4
fbd.addFB(new Delay(2*Ts, Ts)); //5
fbd.addFB(new Scope(1)); //6
fbd.connect(0, 1, 0, 0);
fbd.connect(5, 1, 0, 1);
fbd.connect(1, 2, 0, 0);
fbd.connect(2, 3, 0, 0);
fbd.connect(3, 4, 0, 0);
fbd.connect(4, 5, 0, 0);
fbd.connect(5, 6, 0, 0);
fbd.start();
```