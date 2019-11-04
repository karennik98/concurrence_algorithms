#include "merge_sort.hpp"

#include <iostream>
#include <functional>
#include <chrono>

// float timer(std::function<void(int, size_t, size_t) func, size_t left, size_t right)
// {
//     std::chrono::time_point<std::chrono::system_clock> start, end;
//     float start = std::chrono::system_clock::now();
//     func(left, right);
//     float end = std::chrono::system_clock::now();
//     return std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
// }

int main()
{
    std::vector<int> vec_1 {4,9,7,3,1,9,9,14,5,6,4};
    std::vector<int> vec_2(vec_1);

    // float one = timer(concurrent_merge_sort<int>(vec, 0, vec.size()));

    // std::cout<<"Cuncurrent function result\n";
    // for(const auto& el : vec_1)
    // {
    //     std::cout<<el<<std::ends;
    // }
    // std::cout<<"\nDuration: "<<one<<std::endl;

    // float two = timer(single_thread_merge_sort<int>(vec, 0, vec.size()));
    
    // std::cout<<"Single thread function result\n";
    // for(const auto& el : vec_2)
    // {
    //     std::cout<<el<<std::ends;
    // }
    // std::cout<<"\nDuration: "<<two<<std::endl

    //std::chrono::time_point<std::chrono::system_clock> start1, end1;
    auto start1 = std::chrono::system_clock::now();
    concurrent_merge_sort(vec_1, 0, vec_1.size());
    auto end1 = std::chrono::system_clock::now();
    auto time_1 =  std::chrono::duration_cast<std::chrono::seconds>(end1-start1).count();

    //std::chrono::time_point<std::chrono::system_clock> start2, end2;
    auto start2 = std::chrono::system_clock::now();
    single_thread_merge_sort(vec_2, 0, vec_2.size());
    auto end2 = std::chrono::system_clock::now();
    auto time_2 =  std::chrono::duration_cast<std::chrono::seconds>(end2-start2).count();

    std::cout<<time_1<<"  "<<time_2<std::endl;

    return 0;
}