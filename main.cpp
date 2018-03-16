#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <fstream>
#include "lib/IRunnable.h"
#include "lib/Stub.h"
#include "lib/sorting.h"

using namespace std;
using namespace std::chrono;

auto measure_time(IRunnable& prog) {
    vector<int> times {};
    for (unsigned i = 0; i < 50; i++) {
        auto t1 = high_resolution_clock::now();
        prog.run();
        auto t2 = high_resolution_clock::now();
        auto elapsed = duration_cast<duration<int, micro>>(t2 - t1);
        times.push_back(elapsed.count());
    }
    auto avg = accumulate(times.cbegin(), times.cend(), 0) / times.size();
    return avg;
}

int main() {
    ofstream data_file {"../data.txt"};
    vector<unsigned> sizes {250, 500, 1000, 2500,
                       5000, 7500, 10000, 15000};
    Stub stub;
    for(const auto& size: sizes) {
        stub.prepare(size);
        data_file << size << " " << measure_time(stub) << endl;
    }
    data_file.close();
    return 0;
}
