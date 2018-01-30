#include <algorithm>
#include <exception>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

template<typename T, std::size_t N>
constexpr T getSum(T const (&arr)[N], std::size_t i = 0u )
{
	return i < N ? arr[i] + getSum(arr, ++i) : 0u;
};

template<typename T, std::size_t N>
constexpr std::unordered_map<T, uint64_t> getPosArr(T const(&arr)[N] ) 
{
	std::unordered_map<T, uint64_t> retPosArr;
	retPosArr.reserve(N);

	for(auto i = 0u; i < N ; ++i){
		retPosArr.emplace(arr[i],i);
	}
	return retPosArr;
};


std::pair<int64_t, int64_t> getPos(std::unordered_map<uint64_t ,uint64_t> const&  uM, const uint64_t arr[], uint64_t size, int64_t value){

	for(auto i = 0u; i < size; ++i){
		auto got = uM.find(value - arr[i]); 
		if( got != std::end(uM) )
			return std::make_pair<int64_t, int64_t>( got->second ,i);
	}
	return std::make_pair<int64_t, int64_t>(-1,-1);
}

int main()
{
	constexpr uint64_t arr1[] = {4,1,2,1,1,2};
	constexpr uint64_t arr2[] = {3,6,3,3};

	auto val1 = getSum(arr1);
	auto val2 = getSum(arr2);

	auto uM = getPosArr(arr1);

	auto ret = getPos(uM, arr2, sizeof(arr2)/(sizeof(arr2[0])), val2 - val1 );

	std::cout << ret.first << " " << ret.second << '\n';


	std::vector<uint64_t> vec1{4,1,2,1,1,2};
	std::vector<uint64_t> vec2{3,6,3,3};
	auto val12 = std::accumulate(std::begin(vec1), std::end(vec1), 0);
	auto val22 = std::accumulate(std::begin(vec2), std::end(vec2), 0);
	
	uint64_t arr12[vec1.size()];
	std::copy(std::begin(vec1), std::end(vec1), arr12);
	auto uM2 = getPosArr(arr12); 
	auto ret2 = getPos(uM2, &vec2[0], vec2.size(), val22 - val12);
	std::cout << ret2.first << " " << ret2.second << std::endl;
}
