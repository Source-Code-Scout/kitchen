// the concept is pretty straight forward - global variable lookup takes more time than local variable lookup. so caching a reference to the global variable locally actually helps.

// get a function


#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>



// Function using pass by reference
std::vector<int> passByReference(std::vector<int>& arr) {
    for(int i=0; i<arr.size();i++) {
        arr[i]*=2; 
    }
    return arr;
}


// Function using pass by reference
std::vector<int> passByReferenceLocal(std::vector<int>& arr) {
    std::vector<int> _arr = arr;
    for(int i=0; i<arr.size();i++) {
        _arr[i]*=2; 
    }
    return _arr;
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
    std::vector<int> testVector(100000, 1);
    int iterations = 1000;

    // Run benchmarks
    double referenceTime = benchmark([](std::vector<int>& v) { passByReference(v); }, testVector, iterations);
    double referenceTimeLocal = benchmark([](std::vector<int>& v) { passByReferenceLocal(v); }, testVector, iterations);

    // Print results
    std::cout << "Pass by reference time: " << referenceTime << " ms\n";
    std::cout << "Pass by reference Local time: " << referenceTimeLocal << " ms\n";

    return 0;
}