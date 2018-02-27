#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int64_t> generate_set(std::vector<int64_t> const& arr, uint64_t num )
{
    std::vector<int64_t> retVal;
    retVal.reserve(num);
    for(auto i = 0u; i < num ; ++i){
        retVal.push_back(arr[i]);
    }
    for(auto i = num; i < arr.size(); i++){
        int random = rand() % i;
        if(random < num)
            retVal[random] = arr[i];
    } 
    return retVal;
}

int main()
{
    std::vector<int64_t> vec(100);
    std::iota(std::begin(vec), std::end(vec), 0);

    auto retVal = generate_set(vec,10);
    for(auto val : retVal)
        std::cout << val << '\n';

    return 0;
}

