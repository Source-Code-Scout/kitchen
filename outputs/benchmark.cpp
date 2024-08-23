#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Function using pass by value
std::vector<int> passByValue(std::vector<int> arr) {
    return arr;
}


// Function using pass by reference
std::vector<int> passByReference(std::vector<int>& arr) {
    return arr;
}

// Benchmark function
double benchmark(auto func, const std::vector<int>& arr, int iterations) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        std::vector<int> copy = arr; // Create a new copy of the array for each iteration
        func(copy);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    // Create a large vector for testing
    std::vector<int> testVector(1000000, 1);
    int iterations = 1000;

    // Run benchmarks
    double valueTime = benchmark(passByValue, testVector, iterations);
    double referenceTime = benchmark([](std::vector<int>& v) { passByReference(v); }, testVector, iterations);

    // Print results
    std::cout << "Pass by value time: " << valueTime << " ms\n";
    std::cout << "Pass by reference time: " << referenceTime << " ms\n";
    std::cout << "Pass by reference is " << valueTime / referenceTime << "x faster\n";

    return 0;
}
/*
Program Output:

===============
Pass by value time: 2539.23 ms
Pass by reference time: 2487.34 ms
Pass by reference is 1.02086x faster
*/
======================================================================================================================================================
