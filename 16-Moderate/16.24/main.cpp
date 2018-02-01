#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template<typename T>
std::vector<std::pair<T,T>> findPairVals(std::vector<T> vec, T result)
{
    std::vector<std::pair<T,T>> retVec;
    std::sort(std::begin(vec), std::end(vec), [](T a, T b){ return a < b; } );
    for(auto it = std::begin(vec); it != std::end(vec) - 1; ++it){
        auto it_found = std::find(it+1, std::end(vec), result - *it );
        if(it_found != std::end(vec))
            retVec.emplace_back(std::make_pair(*it, *it_found) );
    }
    return retVec;
}



int main()
{
    std::vector<int> vec {1,5,3,3,4,4,2};
    auto retVal = findPairVals(vec,6);
    for(auto const& pair_: retVal){
        std::cout << pair_.first << " " << pair_.second << '\n';
    }
    return 0;
}




