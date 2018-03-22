#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <fstream>
#include "lib/IRunnable.h"
#include "lib/Stub.h"
#include "lib/MergeSort.h"
#include "lib/HeapSort.h"
#include "lib/QuickSort.h"

using namespace std;
using namespace std::chrono;

auto measure_time(IRunnable& prog) {
    vector<double> times {};
    for (unsigned i = 0; i < 10; i++) {
        auto t1 = high_resolution_clock::now();
        prog.run();
        auto t2 = high_resolution_clock::now();
        duration<double> elapsed = t2 - t1;
        if (elapsed.count() > 30.0)
            return elapsed.count();
        times.push_back(elapsed.count());
    }
    auto avg = accumulate(times.cbegin(), times.cend(), 0.0) / times.size();
    return avg;
}

int main() {
//    ofstream data_file {"../mergesort.csv"};
    vector<unsigned> sizes {10, 100, 1000, 10000,
                       100000};
//    MergeSort mergeSort;
//    for(const auto& size: sizes) {
//        mergeSort.prepare(size);
//        data_file << size << ", " << measure_time(mergeSort) << endl;
//    }
//    data_file.close();
//
//    ofstream heapsort_data {"../heapsort.csv"};
//    HeapSort heapSort;
//    for(const auto& size: sizes) {
//        heapSort.prepare(size);
//        heapsort_data << size << ", " << measure_time(heapSort) << endl;
//    }
//    heapsort_data.close();
//    vector<int> worst_case_sizes {10, 100, 500, 1000, 5000,
//                                  10000, 25000, 50000, 100000};
//    ofstream quicksort_worst_data {"../quicksort_worst.csv"};
    QuickSort q_sort;
//    for(const auto& size: worst_case_sizes) {
//        q_sort.prepare(size, Case::worst);
//        quicksort_worst_data << size << ", " << measure_time(q_sort) << endl;
//    }
//    quicksort_worst_data.close();
    ofstream quicksort_avg_data {"../quicksort_avg.csv"};
    for(const auto& size: sizes) {
        q_sort.prepare(size, Case::average);
        quicksort_avg_data << size << ", " << measure_time(q_sort) << endl;
    }
    quicksort_avg_data.close();
}
