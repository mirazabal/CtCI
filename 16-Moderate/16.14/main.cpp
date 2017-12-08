#include <unordered_map>
#include <assert.h>
#include <vector>
#include <limits>

#include <stdint.h>

struct Point
{
	double x;
	double y;
};

struct Line
{
	double slope;
	double start_y_Point;	
	bool operator==(const Line &other) const
	{
	   	return (slope == other.slope && start_y_Point == other.start_y_Point);
	}
/*
	Line operator=()
	{
		return *this;
	}
*/
};


struct LineHasher
{
	std::size_t operator()(const Line& l) const
	{
		return (std::hash<double>()(l.slope) ^ (std::hash<double>()(l.start_y_Point) << 1));
	}
};



Line createLine(const Point& p1, const Point& p2)
{
	Line retLine;
	if(p1.x != p2.x)
		retLine.slope = (p1.y - p2.y)/(p1.x - p2.x);
	else
		retLine.slope = std::numeric_limits<double>::max();

	retLine.start_y_Point = p1.y - retLine.slope*(p1.x);
   return retLine;	
}


Line mostFreqLine(const std::unordered_map<Line, int64_t, LineHasher>& uM_)
{
	assert(uM_.size() > 0);

	Line retLine;
	int64_t best_match{0};
	for(auto const & pair_ : uM_ ){
		if(pair_.second > best_match ){
			best_match = pair_.second;
			retLine = pair_.first;
		}
	}
	return retLine;
}
/*
void insertLineToUnorderedMap(const std::unordered_map<Line,int64_t>& uM_, const Line& l)
{
	auto& find_elem = freq.find(line);

	if(find_elem == std::unordered_map::end())
		freq.emplace(line,1);
	else
		find_elem.second++;
}


Line bestLine(const std::vector<Point>& vecPoints )
{
	assert(vecPoints.size() > 0);

	std::unordered_map<Line,int64_t> freq;
	for(auto it = vecPoints.begin(); it != vecPoints.end() - 1; ++it){
		for(auto it2 = it + 1 ; it2 =! vecPoints.end(); ++it2){
		  	auto line = createLine(*it, *it2 );
			insertLineToUnorderedMap(freq,line);
		}
	}
	return mostFreqLine(freq);	
}
*/


int main()
{


}
