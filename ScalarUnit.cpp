#include <iostream>
#include "ScalarUnit.h"

ScalarUnit::ScalarUnit() {
    frequencyGHz = 1.5f;   // 1.5 GHz
    ipc          = 1.0f;   // 1 instruction per cycle
}

void ScalarUnit::simulate() {
    float throughput = ipc * frequencyGHz;
    std::cout << "[SPU] Simulating Scalar Unit...\n";
    std::cout << "[SPU] Frequency         : " << frequencyGHz << " GHz\n";
    std::cout << "[SPU] Instructions/Cycle: " << ipc << "\n";
    std::cout << "[SPU] Scalar Throughput : " << throughput << " GIPS\n";
}
