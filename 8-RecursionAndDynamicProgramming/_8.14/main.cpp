#include <stdio.h>
#include <string>




size_t countVal(std::string str, bool result)
{
	if(str.size() == 0)
		return 0;

	if(str.size() == 1)
		return  (size_t)std::atoi(&str[0]);


	for(auto i = 1; i < str.size()-1 ; i += 2){
		std::string left(str.begin(), str[i-1]); 
		std::string right(str[i+1], str.end());
		
		auto leftTrue = countVal(left,true);
		auto leftFalse = countVal(left, false);

		auto rightTrue = countVal(right,true);
		auto rightFalse = countVal(right,false);		
		


		auto total = (leftTrue + leftFalse)*(rightTrue+rightFalse);

		int totalTrue = 0;

		if(str[i] == "^"){
			totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
		} else if (str[i] == "&"){
			totalTrue = leftTrue * rightTrue;
		} else if (str[i] == "|"){
			totalTrue = leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
		} else
			throw std::exception("O no, ya lo sabia");


		int subways = result ? totalTrue : total - totalTrue;
		ways += subways;
	}
		
		return ways;
}

int main()
{
	auto retVal = countVal("1^0|0|0|1", true);
	return 0;
}	
