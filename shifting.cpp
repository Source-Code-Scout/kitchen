#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::vector<int> generateRandomArray(size_t length, int minValue, int maxValue) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(minValue, maxValue);

    std::vector<int> randomArray(length);
    for (size_t i = 0; i < length; ++i) {
        randomArray[i] = distribution(generator);
    }

    return randomArray;
}

// Use volatile to prevent optimization
volatile int dummy;

void useShift(std::vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        dummy = arr[i] << 1;  // Use volatile to force the operation
    }
}

void useMult(std::vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        dummy = arr[i] * 2;  // Use volatile to force the operation
    }
}

// Use function pointers to prevent inlining
typedef void (*OperationFunc)(std::vector<int>&);

// Benchmark function
double benchmark(OperationFunc func, std::vector<int>& arr, int iterations) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        func(arr);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    int iterations = 10000;
    std::vector<int> arr = generateRandomArray(10000, 0, 100);

    // Run benchmarks using function pointers
    double shiftTime = benchmark(useShift, arr, iterations);
    double multTime = benchmark(useMult, arr, iterations);

    // Print results
    std::cout << "Shifting time: " << shiftTime << " ms\n";
    std::cout << "Multiplication time: " << multTime << " ms\n";

    // Calculate and print speedup
    double speedup = multTime / shiftTime;
    std::cout << "Speedup (Shift over Mult): " << speedup << "x\n";

    return 0;
}