#include <iostream>
#include "MatrixMultiplyUnit.h"

MatrixMultiplyUnit::MatrixMultiplyUnit() {
    systolicArraySize  = 128;     // 128x128 array
    computeThroughput  = 45.0f;   // Assume 45 TFLOPS
}

void MatrixMultiplyUnit::simulate() {
    std::cout << "[MXU] Simulating Matrix Multiply Unit...\n";
    std::cout << "[MXU] Systolic Array Size : " << systolicArraySize << "x" << systolicArraySize << "\n";
    std::cout << "[MXU] Compute Throughput  : " << computeThroughput << " TFLOPS\n";
}