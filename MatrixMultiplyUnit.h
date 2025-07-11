#ifndef MATRIX_MULTIPLY_UNIT_H
#define MATRIX_MULTIPLY_UNIT_H

class MatrixMultiplyUnit {
public:
    MatrixMultiplyUnit();
    void simulate();  // Simulate matrix multiply performance
private:
    int systolicArraySize;   // e.g. 128x128
    float computeThroughput; // in TFLOPS
};

#endif