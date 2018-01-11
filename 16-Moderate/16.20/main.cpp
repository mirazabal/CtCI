#include <array>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<std::vector<char>> arr = { {}, {}, {'a', 'b', 'c' }, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v' }, {'w','x','y','z'} };

std::deque<uint32_t> get_digits(uint32_t number){

	std::deque<uint32_t> retDeque;
	do {
		retDeque.push_front( number % 10 );
		number /= number;
	
	} while (number > 0);
	return retDeque;
}

std::vector<std::string> generate_words( uint32_t dig, uint32_t arr_pos, const std::vector<std::string>& vs)
{
	std::vector<std::string> retVec;
	retVec.reserve(vs.size()*4);
	auto it = std::begin(vs);
	do{
		for(auto char_it = std::begin(arr); char_it != std::end(char_it); ++char_it  ){
			retVec.emplace_back(*it + *char_it );
		}
		++it;
	} while(it != std::end(vs) )
	
	return retVec;
}

std::vector<std::string> generate_all_words(std::deque<uint32_t>& deq){

		std::vector<std::string> vs; 
		while(deq.size() > 0){
			auto dig = deq.pop();
			vs = generate_words(dig, vs);
		}
		return vs;
}

std::vector<std::string> possible_words(uint32_t number, std::set<std::string>& words)
{
	auto deq = get_digits(number);
 	return generate_all_words(deq);
}

int main()
{
	std::set<std::string> set_str= {"tree", "hello", "nope", "qwert" };
	auto retVec = possible_words( 1234 , set_str);
	for( const auto& a : retVec)
		std::cout << a  << '\n';

}
