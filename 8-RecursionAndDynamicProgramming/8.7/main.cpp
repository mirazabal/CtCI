#include <string>
#include <iostream>
#include <stdio.h>

void printPermutationsString(std::string & str, size_t l)
{
	if(l == str.size() -1 ){
		std::cout << str << std::endl; 
		return;
	}

	for( auto i = l; i <= str.size() -1; i++ )
	{
		std::swap(str[l], str[i]);
		printPermutationsString(str, l+1);
		std::swap(str[i],str[l]);
	}


}


int main()
{
	return 0;
}
