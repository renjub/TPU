#ifndef HOST_INTERFACE_H
#define HOST_INTERFACE_H

#include <string>
#include <vector>

struct Command {
    std::string operation;
    int M, N, K;
};

struct Tensor {
    std::vector<std::vector<float>> data;
};

class HostInterface {
public:
    HostInterface();
    void simulate();

    // New API methods
    void sendTensor(const std::string& name, const Tensor& t);
    void sendCommand(const Command& cmd);

private:
    float pcieBandwidthGBps;
    int latencyMicroseconds;
};

#endif
