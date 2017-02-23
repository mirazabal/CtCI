
#include <iterator>
#include <iostream>
#include <string>

std::string string_compresor(std::string const& str)
{
	std::string retString;
	retString.reserve(str.size());

	auto it2 = std::begin(str);
	for(auto it1 = std::begin(str); it1 != std::end(str) + 1; ++it1){
		if(*it1 == *it2)
			continue;
		else{
			retString += *it2;
			int number = it1 - it2;
			if(number > 1)
				retString += std::to_string(number);
			
			it2 = it1;
		}
	}
	
	return retString;
};


int main()
{
	std::string str("aaaBBeeeee");
	auto str2 =  string_compresor(str); 
	std::cout << str2 << std::endl;
	return 0;
};

