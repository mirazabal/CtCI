#include <limits>

struct Point 
{
	int64_t x;
	int64_t y;
};

struct Line
{
	int64_t slope;
	Point startPoint;
};

struct Square
{
	Point middle;	
};


Line getMiddleLine(const Square& square1, const Square& square2)
{
	Line retLine;
	if(square1.x != square2.x )
		retLine.slope = (square1.y - square2.y)/(square1.x- square2.x);
	else
		retLine.slope = std::numeric_limits<int64_t>::max();

	retLine.startPoint = square1.middle;
	return retLine;
}


int main()
{
	return 0;
}

