#include <algorithm>
#include <iterator>
#include <iostream>
#include <variant>
#include <vector>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

auto countDiffLetterNumbers(std::vector<std::variant<int,char>> const& vec){

	std::vector<std::pair<int, decltype(std::begin(vec)) >> vecPos;
	vecPos.reserve(vec.size());

	int difference{0};
	for(auto it = std::begin(vec) ; it != std::end(vec); ++it){
        std::visit(overloaded {
            [&](int arg) {
					 									--difference;
					 									vecPos.emplace_back(  std::make_pair( difference,it)); },
            [&](char arg) {
					 									++difference;
														vecPos.emplace_back(std::make_pair(difference,it) ); }
   			}, *it);
	}	

	return vecPos;
}

auto getRange(std::vector<std::pair<int, std::vector<std::variant<int,char>>::const_iterator > > const& vecPos){

	std::pair<decltype(vecPos[0].second), decltype(vecPos[0].second)> retVal;
	int ptr_distance{0};

	for(auto it = std::begin(vecPos); it != std::end(vecPos); ++it ){
		// there also exist the option to pass through the vector with a hash table and account the number of occurrences, and the position in the vector which would had take O(N) time at cost of space 
	 	auto it_last = std::find_if(std::rbegin(vecPos), std::rend(vecPos), [&]( std::pair<int, decltype(vecPos[0].second)> const & p ) { return p.first == it->first; } );

		auto dist = std::distance(it, (it_last+1).base() );
	
		if(dist > ptr_distance){
			ptr_distance = dist;
			auto val = std::make_pair(it->second +1, ((it_last+1).base())->second );
			retVal = val;
		}
	}
	return retVal;
}

auto findLongestSubarrayEqNumLetters(std::vector<std::variant<int,char>> const& vec)
{
	auto vecPos = countDiffLetterNumbers(vec);
	auto range = getRange(vecPos);
	return range;
}

int main()
{
	
	std::vector<std::variant<int,char>> vec{ 1, 'a', 2, 'b', 3, 44, 55, 'c', 6, 'd', 7, 'e', 8, 'f', 9, 'g'};

	auto retVal = findLongestSubarrayEqNumLetters(vec); 

  std::visit(overloaded {
            [&](int arg) { std::cout << "first value " << arg << '\n' ; },
            [&](char arg) {  std::cout << "first value " << arg << '\n' ; },
   			}, *(retVal.first));

  std::visit(overloaded {
            [&](int arg) { std::cout << "second value " << arg << '\n' ; },
            [&](char arg) {  std::cout << " second value " << arg << '\n' ; },
   			}, *(retVal.second));

	return 0;
}
