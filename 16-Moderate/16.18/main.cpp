#include <iostream>
#include <map>
#include <string>
#include <vector>

void generateToken(std::string val, std::vector<std::string> vs, std::vector<std::vector<std::string>>& retVal)
{
	for(auto it = std::begin(val); it != std::end(val); ++it){
		std::vector<std::string> temp {vs};
		temp.emplace_back(std::string( std::begin(val), std::next(it) ) );

		if(std::next(it) == std::end(val) ){
			retVal.push_back(temp);
			return;
		}
		generateToken(std::string( std::next(it), std::end(val) ) , temp , retVal);	
	}
}


bool matches_pattern( const std::string& pattern, const std::string value )
{
	std::vector<std::vector<std::string>> retVal;	
	std::vector<std::string> vs;
	generateToken(value,vs, retVal );

	std::map<char, std::string> mapVal;
	for(const auto& vecStr : retVal){
		if(vecStr.size() != pattern.size() )
			continue;
		auto it_vecStr = std::begin(vecStr);
		for(auto it_pattern = std::begin(pattern); it_pattern != std::end(pattern); ++it_pattern, ++it_vecStr ){
			auto it_map = mapVal.find(*it_pattern);
			if( it_map == mapVal.end() )
				mapVal.insert(std::pair<char,std::string>(*it_pattern, *it_vecStr ) );
			else {
				if(*it_vecStr != (it_map->second) )
					break;
			}
			if( std::next(it_pattern) == std::end(pattern) )
				return true;
		}
		mapVal.clear();
	}
	return false;
}



int main()
{
	std::cout << matches_pattern("ababc", "catgocatgoe") << '\n';

	return 0;
}

