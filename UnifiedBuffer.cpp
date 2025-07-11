#include <iostream>
#include "UnifiedBuffer.h"

UnifiedBuffer::UnifiedBuffer() {
    sizeKB             = 32768;  // 32 MB = 32768 KB
    bandwidthGBps      = 600;    // 600 GB/s peak
    accessLatencyCycles = 2;     // Very low latency
}

void UnifiedBuffer::simulate() {
    std::cout << "[UB] Simulating Unified Buffer...\n";
    std::cout << "[UB] Size               : " << sizeKB << " KB\n";
    std::cout << "[UB] Bandwidth          : " << bandwidthGBps << " GB/s\n";
    std::cout << "[UB] Access Latency     : " << accessLatencyCycles << " cycles\n";
}