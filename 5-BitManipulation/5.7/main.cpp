#include <stdio.h>

size_t swappositions(size_t n1)
{
	 return ((n1 >> 1) & 0x5555555555555555 ) | ((n1 << 1) & 0xAAAAAAAAAAAAAAAA); 
}


int main()
{
	return 0;
}
