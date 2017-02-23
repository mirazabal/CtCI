#include <stdio.h>


size_t numberToFlipBits( size_t n1, size_t n2)
{
	size_t retVal{0};

	while( n1 != 0 && n2 != 0){
		
		if( n1&1 != n2&1)
			retVal++;
	
		n1 >> 1;
		n2 >> 1;
	}
	return retVal;
}


int main()
{

	return 0;
}
