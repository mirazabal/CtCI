#include <stdio.h>

size_t numberOfPossibleJumps(size_t numberStairs)
{
	if (numberStairs == 0)
		return 1;

	if(numberStairs >= 3)
		return	numberOfPossibleJumps(numberStairs -3) + numberOfPossibleJumps(numberStairs -2) + numberOfPossibleJumps( numberStairs - 1); 
	else if( numberStairs >= 2)
		return	numberOfPossibleJumps(numberStairs -2) + numberOfPossibleJumps( numberStairs - 1); 
	else if( numberStairs >= 1)
		return	numberOfPossibleJumps( numberStairs - 1); 

}


int main()
{
	auto a = numberOfPossibleJumps(3);
	return 0;
}
