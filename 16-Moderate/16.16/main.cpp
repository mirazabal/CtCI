#include <array>
#include <iostream>

struct pair_pos
{
	size_t first;
	size_t last;
};



size_t getLeftSubarray(const std::array<int64_t,10>& arr)
{
	for(auto it = std::begin(arr); it != std::end(arr)-1; ++it){
		if( *(it+1) < *it )
			return std::distance(it - std::begin(arr));	
	}
	return std::end(arr); 
}

size_t getRightSubarray()
{


}

size_t findMax(const pair_pos& its, std::array<int64_t,10>& arr)
{


}

size_t findMin(const pair_pos& its, std::array<int64_t,10>& arr)
{


}



pair_pos getPos(const std::array<int64_t,10>& arr)
{
	size_t first{0};
	size_t last{0};

	auto leftSubArrIt = getLeftSubarray(arr);

	int64_t first_val = arr[0];
	for(auto i = 1; i < arr.size(); ++i){
		if(first_val < arr[i]){
		
		}
	}


}






int main()
{
	std::array<int64_t, 10> arr{ {1, 2, 8, 4, 5, 6, 7, 3, 9, 10} };
	auto res = getPos(arr);
	std::cout << "The positions are =  " << res.first << " " << res.last << std::endl;
	
	return 0;
}

