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
    std::vector<int> arr = generateRandomArray(1000, 0, 100);
    for(int i = 0; i < arr.size(); i++) {
        arr[i] =arr[i] << 1;
    }
}

void useMult() {
    std::vector<int> arr = generateRandomArray(1000, 0, 100);
    for(int i = 0; i < arr.size(); i++) {
        arr[i] *= 2;
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
    int iterations = 1000;

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
/*
Program Output:

===============
Shifting time: 35.8865 ms
Multiplication time: 34.5275 ms
Speedup: 1.03936x
*/
// ======================================================================================================================================================
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
        arr[i] *= 2;
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
    int iterations = 1000;

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
/*
Program Output:

===============
Shifting time: 354.56 ms
Multiplication time: 341.582 ms
Speedup: 1.03799x
*/
// ======================================================================================================================================================
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
        arr[i] *= 2;
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
    int iterations = 10000;

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
/*
Program Output:

===============
Shifting time: 3554.82 ms
Multiplication time: 3400.78 ms
Speedup: 1.0453x
*/
// ======================================================================================================================================================
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
    int iterations = 10000;

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
/*
Program Output:

===============
Shifting time: 3587.11 ms
Multiplication time: 3420.22 ms
Speedup: 1.0488x
*/
// ======================================================================================================================================================
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
/*
Program Output:

===============
Shifting time: 35661.3 ms
Multiplication time: 35061.2 ms
Speedup: 1.01712x
*/
// ======================================================================================================================================================
