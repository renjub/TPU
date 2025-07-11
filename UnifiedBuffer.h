#ifndef UNIFIED_BUFFER_H
#define UNIFIED_BUFFER_H

class UnifiedBuffer {
public:
    UnifiedBuffer();
    void simulate();  // Simulate memory access performance
private:
    int sizeKB;               // Buffer size in KB
    int bandwidthGBps;        // Memory bandwidth
    int accessLatencyCycles;  // Typical access latency in cycles
};

#endif