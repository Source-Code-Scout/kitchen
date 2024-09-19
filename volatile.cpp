#include <iostream>
#include <thread>
bool keepRunning = true;
volatile bool volatileKeepRunning = true;

void regularVariableExample() {
    // Simulate an infinite loop
    while (keepRunning) {
        int count = 1;
        // This loop may be optimized away or the variable may be cached,
        // assuming the value of keepRunning doesn't change unexpectedly.
        
        std::cout << "Regular loop :: " << count++ << std::endl;

    }
    std::cout << "Regular loop exited!" << std::endl;
}

void volatileVariableExample() {
    // Simulate an infinite loop
    while (volatileKeepRunning) {
        int count = 1;

        // The compiler is forced to read volatileKeepRunning from memory
        // every time, ensuring it gets any external changes.
        std::cout << "Volatile loop :: " << count++ << std::endl;

    }
    std::cout << "Volatile loop exited!" << std::endl;
}

int main() {
    // In a real-world scenario, some external factor (such as a signal
    // handler, another thread, or hardware) would change the value of 
    // keepRunning and volatileKeepRunning.

    // In this simple demonstration, we'll simulate the external change
    // by stopping the loops after a small delay.

    // Run the regular variable loop in a different thread
    std::thread regularThread(regularVariableExample);

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Change the variable from outside the loop
    keepRunning = false;

    // Wait for the regular loop to exit
    regularThread.join();

    // Run the volatile variable loop in a different thread
    std::thread volatileThread(volatileVariableExample);

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Change the volatile variable from outside the loop
    volatileKeepRunning = false;

    // Wait for the volatile loop to exit
    volatileThread.join();

    return 0;
}
