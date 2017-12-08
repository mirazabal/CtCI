#include <set>
#include <vector>
#include <assert.h>
#include <cstddef>

enum class Color
{
	Red,
	Green,
	Yellow,
	Blue
};


struct MasterMind 
{
	std::vector<Color> vals;
};

struct Result
{
	std::size_t hits;
	std::size_t semi_hits;
};



Result getGuess(const MasterMind& guess, const MasterMind& solution)
{
	assert(guess.vals.size() == 4);
	assert(guess.vals.size() == solution.vals.size());

	Result retResult;
	retResult.hits = 0;
	retResult.semi_hits = 0;

	std::multiset<Color> partial_results; 
	for(auto i = 0; i < guess.vals.size(); ++i ){
		if(guess.vals[i] == solution.vals[i])
			retResult.hits++;
		else{
			auto search = partial_results.find(guess.vals[i]); 
		   	if ( search != partial_results.end() ){
				partial_results.erase(search);
				retResult.semi_hits++;
			} else {
				partial_results.insert(solution.vals[i]);
			}
		}
	}
	return retResult;
}



int main()
{

}




