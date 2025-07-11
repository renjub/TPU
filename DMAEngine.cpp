#include <iostream>
#include "DMAEngine.h"

DMAEngine::DMAEngine() {
    bandwidthGBps          = 450.0f;  // 450 GB/s bandwidth
    maxConcurrentTransfers = 8;       // Up to 8 concurrent transfers
}

void DMAEngine::simulate() {
    std::cout << "[DMA] Simulating DMA Engine...\n";
    std::cout << "[DMA] Bandwidth               : " << bandwidthGBps << " GB/s\n";
    std::cout << "[DMA] Concurrent Transfers    : " << maxConcurrentTransfers << "\n";
}
