#include <stdio.h>


size_t insertBitSequence(size_t number,size_t numberToBeInserted ,size_t pos1, size_t pos2){

	size_t mask = 0;
	for(auto i = pos2+1; i != pos1+1; --i){
		mask |= (1 << i);	
	}
	number &= (~mask);
	numberToBeInserted << pos2+1;
	number |= numberToBeInserted;
	return number;
}


int main()
{
	auto a = insertBitSequence(200, 10, 1 ,4 );
	return 0;
}
