#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

// CODE FOR RANDOM ARRAY GENERATION
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

void useShift() {
    std::vector<int> arr = generateRandomArray(10000, 0, 100);
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = arr[i] << 1;
    }
}

void useMult() {
    std::vector<int> arr = generateRandomArray(10000, 0, 100);
    for(int i = 0; i < arr.size(); i++) {
        arr[i] *= 3;
    }
}

// Benchmark function
double benchmark(auto func, int iterations) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        func();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    int iterations = 100000;

    // Run benchmarks
    double shiftTime = benchmark(useShift, iterations);
    double multTime = benchmark(useMult, iterations);

    // Print results
    std::cout << "Shifting time: " << shiftTime << " ms\n";
    std::cout << "Multiplication time: " << multTime << " ms\n";

    // Calculate and print speedup
    double speedup = shiftTime / multTime;
    std::cout << "Speedup: " << speedup << "x\n";

    return 0;
}