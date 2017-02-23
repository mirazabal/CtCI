#include <array>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


void representCents(size_t cents, std::string str, std::array<size_t,4>& values, size_t index)
{
	if(cents == 0){
		std::cout << str << '\n';
		return;
	}

	if(index < values.size() -1){
		auto tempVal = index + 1;
		representCents(cents, str, values, tempVal);
	}

	while(cents >= values[index] ){
		cents -= values[index];
		auto newIndex = [&]()
			{
				return index < values.size() - 1 ? index +1 : index;
			}();

		representCents(cents, str + std::to_string(values[newIndex]), values, newIndex);
	}

}


int main()
{
	std::array<size_t,4> values{ 25, 10, 5, 1};
	representCents(25,"", values, 0);
	return 0;
}
