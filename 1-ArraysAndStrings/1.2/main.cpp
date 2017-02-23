#include <array>
#include <iostream>
#include <string>

bool check_permutation(std::string str1, std::string str2)
{
	if(str1.size() != str2.size())
		return false;
	// we will assume is extended ASCII
	std::array<int, 256> arr;
	for(auto& i : arr)
		i = 0;

	for(auto& c : str1 ){
		arr[c]++;	
	}

	for(auto& c : str2){
		arr[c]--;
		if(arr[c] < 0)
			return false;
	}
	return true;
};




int main()
{
 std::cout << check_permutation("asdlkjkhgf", "asdfghjkl") << std::endl;
	return 0;

};


