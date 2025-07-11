#include <iostream>
#include "VectorUnit.h"

VectorUnit::VectorUnit() {
    lanes         = 256;     // 256 SIMD lanes
    opsPerCycle   = 256.0f;  // One op per lane per cycle
    frequencyGHz  = 1.2f;    // 1.2 GHz clock
}

void VectorUnit::simulate() {
    float throughput = opsPerCycle * frequencyGHz;
    std::cout << "[VPU] Simulating Vector Unit...\n";
    std::cout << "[VPU] SIMD Lanes         : " << lanes << "\n";
    std::cout << "[VPU] Frequency          : " << frequencyGHz << " GHz\n";
    std::cout << "[VPU] Vector Throughput  : " << throughput << " GOPS\n";
}