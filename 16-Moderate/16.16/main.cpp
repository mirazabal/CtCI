#include <array>
#include <algorithm>
#include <iostream>

struct pair_pos
{
	std::array<int64_t, 10>::const_iterator first;
	std::array<int64_t, 10>::const_iterator last;
};

std::array<int64_t,10>::const_iterator getLeftSubarray(const std::array<int64_t,10>& arr)
{
	for(auto it = std::begin(arr); it != std::end(arr)-1; ++it){
		if( *(it+1) < *it )
			return it;	
	}
	return std::end(arr); 
}

std::array<int64_t,10>::const_iterator getRightSubarray(const std::array<int64_t,10>& arr)
{
	for(auto it = std::end(arr); it != std::begin(arr)+1; --it){
		if( *(it-1) > *it )
			return it;	
	}
	return std::begin(arr); 
}

std::array<int64_t,10>::const_iterator findRightIt(const std::array<int64_t, 10>& arr,
	   																std::array<int64_t, 10>::const_iterator rightIt,
																   	int64_t val)
{
	if(*rightIt >= val)
		return rightIt;
	++rightIt;
	return findRightIt(arr, rightIt, val);
}


std::array<int64_t,10>::const_iterator findLeftIt(const std::array<int64_t, 10>& arr,
	   																std::array<int64_t, 10>::const_iterator leftIt,
																   	int64_t val)
{
	if(*leftIt <= val)
		return leftIt;
	leftIt--;
	return findLeftIt(arr, leftIt, val);
}


pair_pos getPos(const std::array<int64_t,10>& arr)
{
	auto leftSubArrIt = getLeftSubarray(arr);
	auto it_min = std::min_element( leftSubArrIt, std::end(arr) );
	auto leftIt = findLeftIt( arr, leftSubArrIt, *it_min );

	auto rightSubArrIt = getRightSubarray(arr);
	auto it_max = std::max_element(std::begin(arr), rightSubArrIt);
	auto rightIt = findRightIt( arr,rightSubArrIt, *it_max);
	

	pair_pos retVal;
	retVal.first = leftIt;
	retVal.last = rightIt;
	return retVal;
}

int main()
{
	std::array<int64_t, 10> arr{ {1, 2, 3, 8, 5, 6, 7, 3, 9, 10} };
	auto res = getPos(arr);
	std::cout << "The positions are =  " << res.first - std::begin(arr) << " " << res.last - std::begin(arr) << std::endl;
	
	return 0;
}

