#pragma onec

#include <thread>
#include <vector>

template<typename T>
void merge(std::vector<T>& vec, size_t start, size_t mid, size_t end)
{
    std::vector<T> one (vec.begin() + start, vec.begin() + mid + 1);
    std::vector<T> two (vec.begin() + mid + 1, vec.begin() + end + 1);

    size_t i = 0;
    size_t j = 0;
    size_t index = start;
    
    while (i < one.size() && j < two.size())
    {
        if (one[i] < two[j])
            vec[index ++] = one[i ++];
        else 
            vec[index ++] = two[j ++];
    }

    while (i < one.size())
        vec[index ++] = one[i ++];
    while (j < two.size())
        vec[index ++] = two[j ++];
}

template<typename T>
void concurrent_merge_sort(std::vector<T>& vec, size_t start, size_t end)
{
    if (start >= end)
        return;

    size_t mid = start + (end - start) / 2;

    std::thread first(concurrent_merge_sort<T>, std::ref(vec), start, mid);
    std::thread second(concurrent_merge_sort<T>, std::ref(vec), mid + 1, end);

    first.join();
    second.join();

    merge(vec, start, mid, end);
}

template<typename T>
void single_thread_merge_sort(std::vector<T>& vec, size_t start, size_t end)
{
    if (start >= end)
        return;

    size_t mid = start + (end - start) / 2;
    
    single_thread_merge_sort<T>(vec, start, mid);
    single_thread_merge_sort<T>(vec, mid + 1, end); 
    
    merge(vec, start, mid, end);
}

