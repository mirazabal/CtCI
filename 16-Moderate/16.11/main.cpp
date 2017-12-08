#include <map>

std::set<int64_t> getAllLenghts(int64_t numWoods, int64_t short_lenght, int64_t long_length){
	
	if(short_lenght == long_length)
		return std::set<int64_t>(numWoods*short_lenght); 
	
	std::set<int64_t> retSet;
	retSet.reserve(numWoods);

	for(auto i = 0; i < numWoods + 1 ; ++i){
		retSet.push_back( i*short_lenght + (numWoods - i)*long_length );
	}
	return retSet;
}


int main()
{

	return 0;
}
