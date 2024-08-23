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