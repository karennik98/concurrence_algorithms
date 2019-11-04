#include "merge_sort.hpp"

#include <iostream>

int main()
{
    std::vector<int> vec{4,9,7,3,1,9,9,14,5,6,4};

    concurrent_merge_sort<int>(vec, 0, vec.size());
    
    for(const auto& el : vec)
    {
        std::cout<<el<<std::ends;
    }
    std::cout<<std::endl;

    return 0;
}