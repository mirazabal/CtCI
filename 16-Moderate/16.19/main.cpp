#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>

struct point{
		point(uint32_t x, uint32_t y) : x_{x}, y_{y}
		{
		}

	uint32_t x_;
	uint32_t y_;
};

std::vector<point> generate_possible_points(uint32_t x, uint32_t y, std::vector<std::vector<uint32_t >>& vs)
{
	std::vector<point> retVec;
	retVec.reserve(8);

	if(x != 0 ){
		retVec.emplace_back(point(x-1,y));
		if(y != 0)
			retVec.emplace_back(x-1, y-1);
		if(y +1 <= vs.size() -1 )
			retVec.emplace_back(x-1, y +1);
	}
	if(x +1 <= vs[0].size() -1 ){
		retVec.emplace_back(point(x+1,y));
		if(y != 0)
			retVec.emplace_back(x+1, y-1);
		if(y +1 <= vs.size() -1 )
			retVec.emplace_back(x+1, y +1);
	}
	if(y != 0 )
			retVec.emplace_back(point(x, y-1));

	if(y+1 <= vs.size()-1 )
			retVec.emplace_back(point(x, y+1));

	return retVec;
}

uint32_t recursive_alg(uint32_t x, uint32_t y, std::vector<std::vector<uint32_t>>& vs ,std::vector< std::vector<bool > >& visited, uint32_t& actual_extension  ){

	auto possible_points = generate_possible_points(x,y,vs);
	
	visited[y][x] = true;
	for(const auto& point_ : possible_points ){
		if( !vs[point_.y_][point_.x_] && !visited[point_.y_][point_.x_] ){
			++actual_extension;
			recursive_alg(point_.x_, point_.y_,vs,visited, actual_extension);
		}
	}
	return actual_extension;
}


std::vector<uint32_t> get_ponds(std::vector< std::vector<uint32_t>>& vs )
{
		std::vector<std::vector<bool>> visited(vs.size(), std::vector<bool>(vs[0].size(),false) );

		std::vector<uint32_t> retVal;
		uint32_t actual_extension{1};
		for(auto it_v_uint = std::begin(vs); it_v_uint != std::end(vs); ++it_v_uint ){
			for(auto it_val = std::begin(*it_v_uint); it_val != std::end(*it_v_uint); ++it_val ){
				uint32_t x = std::distance(std::begin(*it_v_uint), it_val );
				uint32_t y = std::distance(std::begin(vs), it_v_uint);
				if( *it_val == 0 && !visited[y][x]){
				retVal.emplace_back(recursive_alg(x, y, vs, visited, actual_extension));
				actual_extension = 1;
				}			
			}
		}
	return retVal;
}

int main()
{
	std::vector<std::vector<uint32_t>> vs = {{0,2,1,0},{0,1,0,1}, {1,1,0,1}, {0,1,0,1} };
	auto retVec = get_ponds(vs);

	for(const auto val: retVec)
			std::cout << val << '\n';

	return 0;
}
