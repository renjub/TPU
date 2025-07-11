#include "HostInterface.h"

int main() {
    // Prepare tensors and command
    Tensor A = {{1, 2}, {3, 4}};
    Tensor B = {{5, 6}, {7, 8}};
    Command cmd = {"matmul", 2, 2, 2};

    // Interact with HostInterface
    HostInterface host;
    host.sendTensor("A", A);
    host.sendTensor("B", B);
    host.sendCommand(cmd);

    return 0;
}
