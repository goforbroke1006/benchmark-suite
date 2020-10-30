//
// Created by GOFORBROKE on 30.10.2020.
//

#ifndef BENCHMARK_SUITE_BTEST_H
#define BENCHMARK_SUITE_BTEST_H

#include <iostream>
#include <chrono>

#include "rss.h"


// https://stackoverflow.com/a/9928177/2048322

unsigned long long number_of_allocs = 0;

void *operator new(std::size_t size) throw(std::bad_alloc) {
    ++number_of_allocs;
    void *p = malloc(size);
    if (!p) throw std::bad_alloc();
    return p;
}

void *operator new[](std::size_t size) throw(std::bad_alloc) {
    ++number_of_allocs;
    void *p = malloc(size);
    if (!p) throw std::bad_alloc();
    return p;
}

void *operator new[](std::size_t size, const std::nothrow_t &) throw() {
    ++number_of_allocs;
    return malloc(size);
}

void *operator new(std::size_t size, const std::nothrow_t &) throw() {
    ++number_of_allocs;
    return malloc(size);
}

void operator delete(void *ptr) throw() { free(ptr); }

void operator delete(void *ptr, const std::nothrow_t &) throw() { free(ptr); }

void operator delete[](void *ptr) throw() { free(ptr); }

void operator delete[](void *ptr, const std::nothrow_t &) throw() { free(ptr); }

// ~ https://stackoverflow.com/a/9928177/2048322


#define BENCHMARK_TEST(functionName, caseName, lambdaBody) {                                    \
    size_t memBefore = getCurrentRSS();                                                         \
    auto start = std::chrono::high_resolution_clock::now();                                     \
    auto lambda = [&]() lambdaBody;                                                              \
    unsigned long long allocBefore = number_of_allocs;                                          \
    lambda();                                                                                   \
    unsigned long long allocAfter = number_of_allocs;                                           \
    auto finish = std::chrono::high_resolution_clock::now();                                    \
    size_t memAfter = getCurrentRSS();                                                          \
    \
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();     \
    auto memUsage = memAfter - memBefore;                                                           \
    auto allocCount = allocAfter - allocBefore;                                                     \
    \
    std::cout << #functionName << " / " << #caseName << " : " << duration << " ns" << std::endl;        \
    std::cout << #functionName << " / " << #caseName << " : " << memUsage << " bytes" << std::endl;     \
    std::cout << #functionName << " / " << #caseName << " : " << allocCount << " allocs" << std::endl;  \
}

#endif //BENCHMARK_SUITE_BTEST_H
