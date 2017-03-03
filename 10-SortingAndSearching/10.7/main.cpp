/*
#include <array>
#include <limits>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


using arrGB = std::array<int, 1000000000/sizeof(int)>;

void setInt(int& i, int pos){
	i |= (1 << pos);
}

void setVectorTrue(int value, arrGB& arr)
{
	auto slot = value/(sizeof(int)*8);
	setInt(arr[slot], value%(sizeof(int)*8));
}


int readFirstMissing( arrGB& arr ){

	int slot{0}; 
	while(slot < 1000000000/sizeof(int) ){
		int pos{0};
		while(pos < sizeof(int)*8)
		{
			if( (arr[slot] & (1 << pos)) == 0 )
				return slot*32 + pos;

			pos++;
		}
		slot++;
		if(slot == 1001)
			cout  << "Slot = "<< slot << endl;
	}
	return -1;
}

int main()
{
	unique_ptr< arrGB > vs = make_unique< arrGB >();

	for( auto& val : *vs)
		val = 0;

	for(int i = 0; i < 20201; i++)
		setVectorTrue(i, *vs );

	cout << readFirstMissing(*vs) << endl;

	return 0;
}
*/

#include <array>
#include <limits>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


using arrGB = std::array<int, 1000000000/sizeof(int)>;

void setInt(int& i, int pos){
	i |= (1 << pos);
}

void setVectorTrue(int value, arrGB& arr)
{
	auto slot = value/(sizeof(int)*8);
	setInt(arr[slot], value%(sizeof(int)*8));
}


int readFirstMissing( arrGB& arr ){

	int slot{0}; 
	while(slot < 1000000000/sizeof(int) ){
		int pos{0};
		while(pos < sizeof(int)*8)
		{
			if( (arr[slot] & (1 << pos)) == 0)
				return slot*32 + pos;
			pos++;
		}
		slot++;
		if(slot == 1001)
			cout  << "Slot = "<< slot << endl;
	}
	return -1;
}

int main()
{
	unique_ptr< arrGB > vs = make_unique< arrGB >();

	for( auto& val : *vs)
		val = 0;

	for(int i = 0; i < 10000; i++)
		setVectorTrue(i, *vs );

	cout << readFirstMissing(*vs) << endl;

return 0;
}
