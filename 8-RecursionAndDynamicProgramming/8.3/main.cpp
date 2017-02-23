#include <stdio.h>
#include <vector>

using namespace std;

size_t magicNumber(int l, int r, vector<int>& v){

	if(l <= r)
		return -1;

	int m = (r - l)/2;

	if( v[m] == m) return m;
	else if( v[m] < m){
		return magicNumber(l, m-1,v);
	} else {
		return magicNumber(m+1, r, v );
	}
}

size_t magicNumber( vector<int>& v )
{
	return magicNumber(0, v.size()-1,v);
}

int main()
{
	vector<int> v{0,1,2,3,4,5,6,7,8,9};
	auto a = magicNumber(v);
	return 0;
}
