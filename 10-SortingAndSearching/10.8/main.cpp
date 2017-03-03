#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

void printDuplicates(unsigned int dataStructure[], unsigned short value){
	
	auto slot = value/( 8*sizeof(int) );
	auto remainder = (1 << (value%( 8*sizeof(int) )) );

	if(remainder & dataStructure[slot]){
		auto valSlot = dataStructure[slot];
		cout << "Double value = " << value << " slot = " << slot << " dataStructure[slot] =  " << valSlot << "remainder = " << remainder << endl;
	}
	else
		dataStructure[slot] |= remainder;
}

void printDuplicates(unsigned short data[], size_t size)
{
	unsigned int* dataStructure = new unsigned int[ 4096 /sizeof(unsigned int) ]() ;

	std::memset(dataStructure, 0, 4096);

	for(size_t i = 0; i < size; ++i){
		printDuplicates(dataStructure,data[i]);
	}

	delete[] dataStructure;
}

int main()
{
	unsigned short* data = new unsigned short[32100];
	for(auto i = 0; i < 32035; i++){
		data[i] = i;
	}

	for(auto i = 0; i < 65; i++){
		data[32035+i] = i+10000;
	}
	
	printDuplicates(data,32100);

	delete[] data;
	return 0;
}
