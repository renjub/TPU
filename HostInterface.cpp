#include <iostream>
#include "HostInterface.h"

HostInterface::HostInterface() {
    pcieBandwidthGBps   = 32.0f;
    latencyMicroseconds = 5;
}

void HostInterface::simulate() {
    std::cout << "[HOST] Simulating Host Interface...\n";
    std::cout << "[HOST] PCIe Bandwidth       : " << pcieBandwidthGBps << " GB/s\n";
    std::cout << "[HOST] Latency              : " << latencyMicroseconds << " µs\n";
}

void HostInterface::sendTensor(const std::string& name, const Tensor& t) {
    std::cout << "[HOST] Sending tensor '" << name << "' with shape "
              << t.data.size() << "x" << t.data[0].size() << "\n";
}

void HostInterface::sendCommand(const Command& cmd) {
    std::cout << "[HOST] Sending command: " << cmd.operation
              << "(" << cmd.M << "," << cmd.N << "," << cmd.K << ")\n";
}
