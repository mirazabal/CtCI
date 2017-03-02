#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;


class Box{

	public:

	Box(size_t w, size_t h, size_t d) : width{w}, height{h}, depth{d}
	{
	
	}
	size_t width;
	size_t height;
	size_t depth;
};

void buildStack( size_t pos, std::vector<Box> actualStack, vector<Box> const& vBoxes, size_t& maxHeight ){
	
	if(pos >= vBoxes.size() - 1 ){

		

		size_t heightActualStack{0};
		for(auto const& b : actualStack)
			heightActualStack += b.height;
		
		if(vBoxes[pos].depth <= vBoxes[pos-1].depth && vBoxes[pos].width <= vBoxes[pos-1].width )
			heightActualStack += vBoxes[pos].height;

		if(heightActualStack > maxHeight)
			maxHeight = heightActualStack;

		return;
	}

	buildStack(pos+1, actualStack, vBoxes, maxHeight );
	
	if( vBoxes[pos].depth >= vBoxes[pos+1].depth && vBoxes[pos].width >= vBoxes[pos+1].width  ){
	actualStack.push_back( vBoxes[pos]);
		buildStack(pos+1, actualStack, vBoxes, maxHeight);
	}
}

size_t getMaxHeight(std::vector<Box>& vBoxes)
{
	std::sort(std::begin(vBoxes), std::end(vBoxes), [](Box const& b1, Box const& b2){ return b1.height > b2.height ;} );

	size_t retVal{0};
	buildStack(0,vector<Box>(), vBoxes,retVal);

	return retVal;
}

int main()
{
	vector<Box> vBoxes;
	for(int i = 0; i < 5; i++){
		Box b( 10, 15 - i, 10);
		vBoxes.emplace_back(b);
	}

	auto val = getMaxHeight(vBoxes);
	std::cout << val << std::endl;

	return 0;
}
