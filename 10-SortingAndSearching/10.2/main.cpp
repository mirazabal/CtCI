#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


class ValPos
{
	public:
	ValPos(int val_, int pos_) : val(val_), pos(pos_)
	{

	};

	int val;
	int pos;
};

void sortArrayStrings(vector<string>& str)
{

	vector<ValPos> v;
	v.reserve(str.size());

	size_t pos{0};

	for(auto const& word : str){
		int val{0};
		for(auto const& charac: word){
			val += charac;
		}
		v.emplace_back( ValPos(val,pos) );
		pos++;
	}

	sort(begin(v),end(v), [&](ValPos const& p1, ValPos const& p2) { return p1.val >= p2.val; });

	vector<string> tempStr;
	tempStr.reserve(str.size());

	transform(begin(v) ,end(v), begin(tempStr), [&](ValPos const& vP){ return str[vP.pos] ;} );

	str = tempStr;
}


int main()
{
	vector<string> vs{ "asdf", "fdsa", "qwe", "ewq", "qwty", "ion"};
	
	sortArrayStrings(vs);

	for(auto const& str : vs)
		cout << str << endl;


	return 0;
}
