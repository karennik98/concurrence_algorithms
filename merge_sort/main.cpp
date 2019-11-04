#include "merge_sort.hpp"

#include <iostream>
#include <functional>
#include <chrono>

using int_vec_type = std::vector<int>;

float timer(std::function<void(int_vec_type&, size_t, size_t)> func, 
            int_vec_type& vec, size_t left, size_t right)
{
    auto start = std::chrono::system_clock::now();

    func(vec, 0, vec.size());

    auto end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main()
{
    int_vec_type vec_1 {4,9,7,3,1,9,9,14,5,6,4};
    int_vec_type vec_2(vec_1);

    float firts_diff = timer(concurrent_merge_sort<int>, vec_1, 0, vec_1.size());

    std::cout<<"Cuncurrent function result\n";
    for(const auto& el : vec_1)
    {
        std::cout<<el<<" ";
    }
    std::cout<<"\nDuration: "<<firts_diff<<std::endl;

    float second_diff = timer(single_thread_merge_sort<int>, vec_2, 0, vec_2.size());
    
    std::cout<<"\nSingle thread function result\n";
    for(const auto& el : vec_2)
    {
        std::cout<<el<<" ";
    }
    std::cout<<"\nDuration: "<<second_diff<<std::endl;

    return 0;
}