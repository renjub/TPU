#include <iostream>
#include "ActivationUnit.h"

ActivationUnit::ActivationUnit() {
    parallelLanes        = 256;    // 256 parallel activation lanes
    opsPerLanePerCycle   = 1.0f;   // One activation per cycle per lane
    frequencyGHz         = 1.2f;   // 1.2 GHz
}

void ActivationUnit::simulate() {
    float throughput = parallelLanes * opsPerLanePerCycle * frequencyGHz;

    std::cout << "[ACT] Simulating Activation Unit...\n";
    std::cout << "[ACT] Parallel Lanes        : " << parallelLanes << "\n";
    std::cout << "[ACT] Frequency             : " << frequencyGHz << " GHz\n";
    std::cout << "[ACT] Activation Throughput : " << throughput << " GOPS\n";
}
