#ifndef ACTIVATION_UNIT_H
#define ACTIVATION_UNIT_H

class ActivationUnit {
public:
    ActivationUnit();
    void simulate();  // Simulate activation function performance
private:
    int parallelLanes;         // Number of parallel activation units
    float opsPerLanePerCycle;  // Ops per lane per cycle
    float frequencyGHz;        // Clock speed
};

#endif
