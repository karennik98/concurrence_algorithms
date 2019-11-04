#pragma once

#include <stdint.h>
#include <thread>
#include <future>

int64_t concurrent_fibonacci(int64_t number )
{
    if(number == 0)
        return 0;
    if(number == 1 || number == 2)
        return 1;

    std::future<int64_t> future_1 = std::async(concurrent_fibonacci, number-1);
    //maybe second thread useless
    std::future<int64_t> future_2 = std::async(concurrent_fibonacci, number-2);

    future_1.wait();
    future_2.wait();

    return future_1.get() + future_2.get();
}

int64_t single_thread_fibonacci(int64_t number )
{
    if(number == 0)
        return 0;
    if(number == 1 || number == 2)
        return 1;

    int64_t el_1 = single_thread_fibonacci(number-1);
    int64_t el_2 = single_thread_fibonacci(number-2);

    return el_1 + el_2;
}