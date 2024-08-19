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
