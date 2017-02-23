#include <stdio.h>

struct ChangeValues
{
	public:
	ChangeValues(size_t zeroPos, size_t onePos) : zeroPos_(zeroPos), onePos_(onePos){
	
	}

	size_t zeroPos_;
	size_t onePos_;
};

ChangeValues detectSwapValues( size_t val)
{
	ChangeValues ret;

	bool oneCount{false};
	size_t posOne{0};
	size_t posZero{0};

	while( val != 0){
		auto b = val & 1;
		if(b == 0){
		   if(oneCount){
				posZero++;
			   break;
		   }
		} else {
			posOne = posZero;
			oneCount = true;
		}

		posZero++;
		val >> 1;
	}

	return ChangeValues(posZero, posOne);
}


size_t nextLargest(size_t val)
{
	auto retVal = detectSwapValues(val);
	
	size_t maskZero = 1 << retVal.zeroPos_;
	val |= maskZero;


	size_t maskOne = 1 << retVal.onePos_;
	maskOne = ~maskOne;
	val &= maskOne;

	return val;
}


int main()
{
	return 0;
}
