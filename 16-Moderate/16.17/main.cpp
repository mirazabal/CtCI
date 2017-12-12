#include <vector>
#include <limits>
#include <assert.h>
#include <iostream>

int64_t contiguosLargestSum(std::vector<int64_t> const& vec ){

	assert(vec.size() > 0);

	int64_t partialSum{ 0 };
	int64_t retVal{std::numeric_limits<int64_t>::min()};
	for(auto val : vec){
		auto temp = val + partialSum;

		//ToDo: check for integer sum overflow....

		if(temp <= 0){
			partialSum = 0;
			if(temp > retVal)
				retVal = temp;
		}
		else
			partialSum = temp;	
		
		if(partialSum > retVal )
			retVal = partialSum;
	}

	return retVal;
}


int main()
{

	std::vector<int64_t> vec {-8,5,-4,8,-5,-10};
	std::cout << contiguosLargestSum(vec) << std::endl;
	return 0;
}
