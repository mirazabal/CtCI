#include <string>

void printPermutations( std::string& str, size_t l)
{
	if(l == str.size() -1){
		std::cout << str << std::endl;
		return;
	}


	for(auto i = l+1; l < str.size() -1; i++){
		if( str[l] != str[i]){
			std::swap(str[l], str[i]);
			printPermutations(str, l+1);
			std::swap(str[i], str[l] )
		}
}


}

int main()
{
	return 0;
}
