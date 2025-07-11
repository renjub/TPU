// This is a scaffold for TPU performance modeling in C++
// One file per unit: Matrix Multiply Unit, Vector Unit, Scalar Unit, etc.
// Below is the main file to orchestrate them.

#include <iostream>
#include "MatrixMultiplyUnit.h"
#include "VectorUnit.h"
#include "ScalarUnit.h"
#include "UnifiedBuffer.h"
#include "Accumulator.h"
#include "ActivationUnit.h"
#include "DMAEngine.h"
#include "HostInterface.h"

int main() {
    std::cout << "==== TPU Performance Model ====" << std::endl;

    MatrixMultiplyUnit mxu;
    VectorUnit vpu;
    ScalarUnit spu;
    UnifiedBuffer buffer;
    Accumulator acc;
    ActivationUnit act;
    DMAEngine dma;
    HostInterface host;

    mxu.simulate();
    vpu.simulate();
    spu.simulate();
    buffer.simulate();
    acc.simulate();
    act.simulate();
    dma.simulate();
    host.simulate();

    return 0;
}