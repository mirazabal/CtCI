#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int searchRotatedVector(vector<int>& v, int start, int end, int valueSearched)
{
	if(start >= end)
		return -1;

	if(valueSearched == v[start])
		return start;
	
	if(valueSearched == v[end])
		return end;


	int middle = start + (end - start)/2;

	if(valueSearched == v[middle])
		return middle;


	if(v[start] <= v[middle] && v[end] <= v[middle]){ // the rotation in the roght side
	
		if(valueSearched >= v[start] && valueSearched <= v[middle])
			return searchRotatedVector(v, start, middle -1, valueSearched );
		else 
			return searchRotatedVector(v, middle+1, end, valueSearched );

	} else if( v[start] >= v[middle] && v[middle] <= v[end]){ // the rotation in the left side
	
		if(valueSearched > v[middle] && valueSearched < v[end])
			return searchRotatedVector(v, middle+1, end, valueSearched );
		else
			return searchRotatedVector( v, start, middle-1, valueSearched );

	} else if( v[start] <= v[middle] && v[middle] <= v[end] ){ // no rotation

		if( valueSearched < v[middle])
			return searchRotatedVector(v, start, middle-1, valueSearched);
		else
			return searchRotatedVector(v, middle+1, end, valueSearched);
	}
}

int searchRotatedVector(vector<int>& v, int valueSearched )
{
	return searchRotatedVector(v, 0, v.size()-1, valueSearched );
}

int main()
{
   // looks like a std::rotate would had been nice :-)
	vector<int> v{ 15,16,19,20,25,1,3,4,5,7,10,14};
	cout << searchRotatedVector(v,22) << '\n';

	return 0;
}
