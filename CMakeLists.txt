cmake_minimum_required(VERSION 3.9)
project(MeasureTime)

set(CMAKE_CXX_STANDARD 17)

add_executable(MeasureTime main.cpp lib/IRunnable.h lib/IPreparable.h src/Stub.cpp lib/Stub.h lib/sorting.h src/MergeSort.cpp lib/MergeSort.h lib/HeapSort.h src/HeapSort.cpp src/sorting.cpp)