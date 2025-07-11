cmake_minimum_required(VERSION 3.10)
project(TPUPerformanceModel)

set(CMAKE_CXX_STANDARD 17)

# TPU simulation sources
set(SIM_SOURCES
    Main.cpp
    MatrixMultiplyUnit.cpp
    VectorUnit.cpp
    ScalarUnit.cpp
    UnifiedBuffer.cpp
    Accumulator.cpp
    ActivationUnit.cpp
    DMAEngine.cpp
    HostInterface.cpp
)

set(SIM_HEADERS
    MatrixMultiplyUnit.h
    VectorUnit.h
    ScalarUnit.h
    UnifiedBuffer.h
    Accumulator.h
    ActivationUnit.h
    DMAEngine.h
    HostInterface.h
)

# Main TPU simulator
add_executable(TPUPerformanceModel ${SIM_SOURCES} ${SIM_HEADERS})

# Example host input program
add_executable(ExampleInput
    example_input_to_host.cpp
    HostInterface.cpp        # shared logic
)
