#include <iostream>
#include <string>
#include <vector>


using namespace std;


int sparseSearch(int start, int end, vector<string> const& vStrings, string const& searchedStr){

	if(start >= end)
		return -1;

	auto middle = start + (end-start)/2;

	while(vStrings[middle] == " " && middle < end)
		middle++;

	if(vStrings[middle] == searchedStr)
		return middle;

	if(middle == end)
		return -1;

	if(vStrings[middle] > searchedStr)
		return sparseSearch(start, middle-1, vStrings, searchedStr );
	else
		return sparseSearch(middle+1, end, vStrings, searchedStr );

	return -1;
}

int sparseSearch(vector<string> const& vStrings, string const& searchedStr)
{
	return sparseSearch(0, vStrings.size()-1, vStrings, searchedStr);
}

int main()
{
	vector<string> vs{"aasd"," "," ","all", " "," ","azz", "baaz", " " , " ",  "bastards", " " ," " , "monkeys"};

	cout <<  sparseSearch(vs, "all") << '\n';
	return 0;
}
