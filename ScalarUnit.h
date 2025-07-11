#ifndef SCALAR_UNIT_H
#define SCALAR_UNIT_H

class ScalarUnit {
public:
    ScalarUnit();
    void simulate();  // Simulate scalar operation performance
private:
    float frequencyGHz;    // Clock speed
    float ipc;             // Instructions per cycle
};

#endif
