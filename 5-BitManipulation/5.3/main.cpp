#include <stdio.h>
#include <vector>


size_t flipBitToWin(size_t val)
{
	size_t actualMaxLenght{0};
	size_t maxVal{0};
	size_t counterSecondOnesChain{0};

	bool zeroInBetween{false};

	while(val != 0){
		auto ret = val & 1;
		if(ret == 1){
			if(zeroInBetween){
				counterSecondOnesChain++;	
			}
			actualMaxLenght++;
		} else {
			if(zeroInBetween){ // second 0
				if(counterSecondOnesChain == 0) // found 2 zeros in a row
				{	
					maxVal = std::max(actualMaxLenght , maxVal);
					actualMaxLenght = 0;
					zeroInBetween = false;
				} else {
					actualMaxLenght = counterSecondOnesChain + 1;
					counterSecondOnesChain = 0;
				}
			} else {
				if(counterSecondOnesChain != 0)
					zeroInBetween = true;
				counterSecondOnesChain = 0;
			}
		}
		val >> 1;
	}
	maxVal = std::max( maxVal, actualMaxLenght);

	return maxVal;

}

int main()
{

	return 0;
}
