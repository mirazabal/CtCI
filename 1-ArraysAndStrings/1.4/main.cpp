#include <iostream>
#include <string>
#include <unordered_map>

bool is_permutation_palindrome(std::string const& str)
{
	std::unordered_map<char , int> uM;
	for(auto& c : str){
		if(c != ' ')
		{
			if(uM.find(c) == uM.end())
				uM.insert(std::make_pair(c,1));
			else
				uM.at(c)++;
		}
	}
	
	int number_of_odds{0};
	for(auto& p : uM)
	{
		if((p.second % 2) == 1 )
			number_of_odds++;
	}
	
	return  (number_of_odds == 1) ? true : false;
};

int toggle(int bitvector, int index)
{
	if(index < 0 ) return bitvector;

	int mask = 1 << index;
	if(( bitvector & mask) == 0){
		bitvector |= mask;
	}else{
		bitvector &= ~mask;
	}
	return bitvector;
};

int create_bit_vector(std::string const& str)
{
	int bitvector{0};
	for(auto& c : str){
		int x = (int)c;
		bitvector = toggle(bitvector, int(c));
	}
	return bitvector;
};

bool check_exactly_on_bit_set(int bitvector)
{
	return (bitvector & (bitvector -1) == 0);
};


bool is_permutation_palindrome_optimized(std::string const& str)
{
	int bitvector = create_bit_vector(str);
	return bitvector == 0 || check_exactly_on_bit_set(bitvector);
	
	
};




int main()
{
	std::cout << "  " << std::endl;
	return 0;
};
