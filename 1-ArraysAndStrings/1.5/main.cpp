#include <iostream>
#include <string>



int one_way(std::string& str1, std::string& str2)
{
	auto it1 = std::begin(str1);
	auto it2 = std::begin(str2);
	unsigned numberChanges{0};

	while(it1 != std::end(str1)){
		if(*it1 != *it2){
			numberChanges++;
			if(numberChanges > 1)
				return false;

			if(str1.length() > str2.length()){
				++it1;
				continue;
			}
			else if(str1.length() < str2.length() ){
				++it2;
				continue;
			}
		}
		++it1;
		++it2;
	}

	return true;
	
};


int main()
{	
	std::string str1("pale");
	std::string str2("pal");
	std::cout << one_way(str1, str2) << std::endl;
	return 0;
};
