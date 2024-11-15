// src/Multithreading.cpp
#include "Multithreading.h"

void parallelProcess(std::vector<std::function<void()>>& tasks) {
    std::vector<std::thread> threads;
    for (auto& task : tasks) {
        threads.emplace_back(task);
    }
    for (auto& thread : threads) {
        if (thread.joinable()) thread.join();
    }
}
