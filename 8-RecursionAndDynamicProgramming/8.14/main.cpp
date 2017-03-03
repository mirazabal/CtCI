#include <string>

using namespace std;

size_t countEval(std::string str , bool result)
{
	if(str.size() == 0)
		return 0;

	if(str.size() == 1){
		if((result && str == "1") || (!result && str == "0"))
			return 1;

		return 0;
	}

	size_t ways = 0;
	for(int i = 1; i < str.size(); i +=2){
	
		string leftStr(std::begin(str), std::begin(str) + i );
		string rightStr(std::begin(str) + i + 1, std::end(str) );

		size_t leftTrue = countEval(leftStr, true);
		size_t leftFalse = countEval(leftStr, false);

		size_t rightTrue = countEval(rightStr, true);
		size_t rightFlase = countEval(rightStr, false);

		size_t subways = 0;
		size_t totalWays = leftTrue + leftFalse + rightTrue + rightFlase;

		if( str[i] == '&'){
			subways = leftTrue * rightTrue;
		} else if( str[i] == '|'){
			subways = leftTrue * rightFlase + leftTrue * rightTrue +leftFalse*rightTrue;
		} else if (str[i] == ' ') {
			subways = leftTrue*rightFlase + leftFalse*rightTrue;
		} else
			throw exception();

		ways += result ? subways : totalWays -subways;
	}

	return ways;
}



int main()
{
	auto a = countEval("1&1|0&1", true);
	return 0;
}
