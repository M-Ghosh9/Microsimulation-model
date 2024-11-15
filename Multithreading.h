// include/Multithreading.h
#ifndef MULTITHREADING_H
#define MULTITHREADING_H

#include <vector>
#include <thread>
#include <functional>

void parallelProcess(std::vector<std::function<void()>>& tasks);

#endif // MULTITHREADING_H
