#include <array>
#include <iostream>

template<typename T>
constexpr bool isTwo(T const x)
{
	return (x == 2 ) ? true : false;
};

template<typename T>
constexpr T loopInNumber(T const x)
{
	return ( x < 10 ) ? 
	 					isTwo(x) == true ? 1 : 0  :				
						 loopInNumber(x/10) + (isTwo(x%10)  == true ? 1 : 0) ;
};

template<typename T, std::size_t N>
struct findTwo
{
	static constexpr inline T result(T const* a){
		return (  loopInNumber(*a) + findTwo<T, N-1>::result(a+1) );
	}
};

template<typename T>
struct findTwo<T, 1u>{
	static constexpr inline T result(T const* a){
			return loopInNumber(*a);
	}
};

template<typename T, size_t N>
constexpr auto findTerminatingArr(std::array<T,N> const&  arr)
{
	return findTwo<T,N>::result( arr.begin() );	
}


int main()
{
	constexpr std::array<int,10> arr{ 2222027  , 102 , 1045, 897642, 1287, 22, 34, 56792, 34, 245 };
	constexpr auto retVal = findTerminatingArr(arr);
	std::cout << "Number of 2s in array = " << retVal << '\n';
	return 0;
}

