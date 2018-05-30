#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

void sortPeople(std::vector<std::pair<std::size_t, std::size_t>> & list )
{
	std::sort(std::begin(list), std::end(list), 
			[](auto const& x, auto const& y){
		 							return (x.first < y.first) || ( !(y.first < x.first) && (x.second < y.second) );
			});
}

std::size_t biggestTowerPossible (std::vector<std::pair< std::size_t, std::size_t > >& list )
{
	assert(list.size() > 0);

	sortPeople(list);
	std::vector<std::size_t> aux(list.size(), 1);
	for(size_t i = 1; i < list.size(); ++i ){
		for( size_t j = 0; j < i; ++j ){
			if( list[i].second > list[j].second)
			 aux[i] = std::max(aux[i], aux[j] + 1);	
		}
	}	
	auto it = std::max_element(std::begin(aux), std::end(aux));
	return *it;
}

void checkAvailabilityEmplace( size_t val, std::vector<size_t>& tail)
{
	for(int i = tail.size() -1 ; i > -1 ; --i){
		if(tail[i] < val ){
			if(tail[i+1] > val)
				tail[i+1] = val;
			return;
		}
	}
}

std::size_t biggestTowerPossibleOpt(std::vector<std::pair<std::size_t, std::size_t>>& vec)
{
	using vec_pair = std::vector<std::pair<std::size_t, std::size_t>> ;
	sortPeople(vec);
	std::vector< size_t >  tail;
	for(auto const& p_ : vec){
		if(tail.size() == 0 ){
			tail.emplace_back(p_.second);
		}else if( p_.second > tail[tail.size()-1] ){ // insert at the end
			tail.emplace_back(p_.second); 
		}else{
			checkAvailabilityEmplace(p_.second, tail);
		}	
	}



	return tail.size();
}


int main()
{
	std::vector<std::pair<std::size_t, std::size_t>> vec;
	vec.push_back(std::make_pair(150,50));
	vec.push_back(std::make_pair(160,60));
	vec.push_back(std::make_pair(170,90));
	vec.push_back(std::make_pair(180,70));
	vec.push_back(std::make_pair(190,75));
	vec.push_back(std::make_pair(195,80));
	vec.push_back(std::make_pair(157,100));
	vec.push_back(std::make_pair(167,50));

	std::cout << "Biggest value of the tower = " << biggestTowerPossible(vec) << '\n';
	std::cout << "Biggest value of the tower op = " << biggestTowerPossibleOpt(vec) << '\n';
	return 0;
}
