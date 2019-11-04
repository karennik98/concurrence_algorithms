#include "fibonacci.hpp"

#include <iostream>

std::pair<int64_t, float> timer(std::function<int64_t(int64_t)> func, int64_t number)
{
    auto start = std::chrono::system_clock::now();

    int64_t result = func(number);

    auto end = std::chrono::system_clock::now();
    float diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return {result, diff};
}

int main()
{
    auto result_1 = timer(concurrent_fibonacci, 20);
    std::cout<<"Result of concurrent algorithm: "<<result_1.first
             <<"\nDuration: "<<result_1.second
             <<std::endl;
    
    auto result_2 = timer(single_thread_fibonacci, 20);
    std::cout<<"Result of single thread algorithm: "<<result_2.first
             <<"\nDuration: "<<result_2.second
             <<std::endl;

    return 0;
}
