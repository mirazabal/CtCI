#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> peaksValleys(vector<int>& inp)
{
	if(inp.size() < 3)
		return inp;
	
	sort(begin(inp), end(inp), [](int a, int b){ return a > b;} );

	auto it1 = begin(inp);
	auto it2 = begin(inp) + 1;

	while(it2 != end(inp) && it1 != end(inp)){
		
		if(*it2 < *it1){
			swap(*it1, *it2);
		}

		it2 += 2;
		it1 += 2;
	}
	return inp;
}

int main()
{
	vector<int> v {5,3,1,2,3};

	auto ret = peaksValleys(v);
	for(auto v : ret)
		cout << v << endl;

	return 0;
}

