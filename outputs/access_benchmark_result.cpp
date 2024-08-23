#include <iostream>
#include <vector>
#include <ctime>

const int ARRAY_SIZE = 10000000;
const int ITERATIONS = 1000;

// Function using pass by value
long long passByValue(std::vector<int> arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}

// Function using pass by reference
long long passByReference(const std::vector<int>& arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}

double benchmark(long long (*func)(std::vector<int>), const std::vector<int>& arr) {
    clock_t start = clock();
    func(arr);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}

double benchmarkRef(long long (*func)(const std::vector<int>&), const std::vector<int>& arr) {
    clock_t start = clock();
    func(arr);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}

int main() {
    std::vector<int> testVector(ARRAY_SIZE, 1);

    std::cout << "running passByValue..." << std::endl;

    double valueTime = benchmark(passByValue, testVector);

    std::cout << "running passByRef..." << std::endl;

    double referenceTime = benchmarkRef(passByReference, testVector);

    std::cout << "Pass by value time: " << valueTime << " ms" << std::endl;
    std::cout << "Pass by reference time: " << referenceTime << " ms" << std::endl;
    std::cout << "Ratio (value/reference): " << valueTime / referenceTime << std::endl;

    return 0;
}
/*
Program Output:
===============
running passByValue...
running passByRef...
Pass by value time: 37848.6 ms
Pass by reference time: 35280.2 ms
Ratio (value/reference): 1.0728
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Function using pass by value
std::vector<int> passByValue(std::vector<int> arr) {
    for (int& num : arr) {
        num *= 2;
    }
    return arr;
}

// Function using pass by reference
void passByReference(std::vector<int>& arr) {
    for (int& num : arr) {
        num *= 2;
    }
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
    int iterations = 100;

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
Pass by value time: 1141.07 ms
Pass by reference time: 880.561 ms
Pass by reference is 1.29585x faster
*/
// ======================================================================================================================================================
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Function using pass by value
std::vector<int> passByValue(std::vector<int> arr) {
    for (int& num : arr) {
        num *= 2;
    }
    return arr;
}

// Function using pass by reference
void passByReference(std::vector<int>& arr) {
    for (int& num : arr) {
        num *= 2;
    }
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
    int iterations = 100;

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
Pass by value time: 1121 ms
Pass by reference time: 843.531 ms
Pass by reference is 1.32894x faster
*/
// ======================================================================================================================================================
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Function using pass by value
std::vector<int> passByValue(std::vector<int> arr) {
    for (int& num : arr) {
        num *= 2;
    }
    return arr;
}

// Function using pass by reference
void passByReference(std::vector<int>& arr) {
    for (int& num : arr) {
        num *= 2;
    }
}


/*
Program Output:

===============
Pass by value time: 1127.84 ms
Pass by reference time: 891.393 ms
Pass by reference is 1.26525x faster
*/
// ======================================================================================================================================================
#include <iostream>
#include <vector>
#include <chrono>

const int ARRAY_SIZE = 100000;
const int ITERATIONS = 1000;

// Function using pass by value
long long passByValue(std::vector<int> arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}

// Function using pass by reference
long long passByReference(const std::vector<int>& arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}
/*
Program Output:

===============
Pass by value time: 368.079 ms
Pass by reference time: 371.043 ms
Ratio (value/reference): 0.992012
*/
// ======================================================================================================================================================
#include <iostream>
#include <vector>
#include <chrono>

const int ARRAY_SIZE = 1000000;
const int ITERATIONS = 1000;

// Function using pass by value
long long passByValue(std::vector<int> arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}

// Function using pass by reference
long long passByReference(const std::vector<int>& arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}


/*
Program Output:

===============
Pass by value time: 372.653 ms
Pass by reference time: 377.543 ms
Ratio (value/reference): 0.987049
*/
// ======================================================================================================================================================
#include <iostream>
#include <vector>
#include <chrono>

const int ARRAY_SIZE = 100000;
const int ITERATIONS = 1000;

// Function using pass by value
long long passByValue(std::vector<int> arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}

// Function using pass by reference
long long passByReference(const std::vector<int>& arr) {
    long long sum = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            sum += arr[j];
        }
    }
    return sum;
}

double benchmark(long long (*func)(std::vector<int>), const std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    func(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

double benchmarkRef(long long (*func)(const std::vector<int>&), const std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    func(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    std::vector<int> testVector(ARRAY_SIZE, 1);

    double valueTime = benchmark(passByValue, testVector);
    double referenceTime = benchmarkRef(passByReference, testVector);

    std::cout << "Pass by value time: " << valueTime << " ms" << std::endl;
    std::cout << "Pass by reference time: " << referenceTime << " ms" << std::endl;
    std::cout << "Ratio (value/reference): " << valueTime / referenceTime << std::endl;

    return 0;
}
/*
Program Output:

===============
Pass by value time: 369.894 ms
Pass by reference time: 373.354 ms
Ratio (value/reference): 0.990731
*/
// ======================================================================================================================================================
