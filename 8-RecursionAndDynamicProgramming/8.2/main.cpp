#include <stdio.h>
#include <vector>

using namespace std;
/*
class Cell{
	public
		Cell(size_t r, size_t c) : row{r}, col{c}
	{

	}

	size_t row;
	size_t col;
	bool transitable;
	bool visited;
};

vector<Cell> findPath(size_t r, size_t c, vector< vector<Cell> >& vCells, size_t lastRow, size_t lastColumm)
{
	if(r == lastRow && c == lastColumm ){
		vector<Cell> vCell;
		vCell.emplace_back( Cell(r,c));
		return vCell;
	}

	if( r + 1 < lastRow && vCells[r+1][c].transitable == true && vCells[r+1][c].visited == false )
	{
		vCells[r+1][c].visited = true;
		return findPath(r+1, c,vCells, lastRow, lastColumm).emplace_back(Cell(r,c));
	}





}
*/

class Point{
	public:
	Point( size_t row, size_t col): row_{row}, col_{col}
   	{

	}
	size_t row_;
	size_t col_;
};

bool getPath(std::vector< std::vector<bool> >& maze, int row, int col, std::vector<Point>& path){

	if(col < 0 || row < 0 || !maze[row][col])
		return false;

	bool isAtOrigin = (row == 0) && (col == 0);
	
	if( isAtOrigin || getPath(maze, row, col-1, path) || getPath(maze, row-1, col, path ) ){
		Point p(row, col);
		path.emplace_back(p);
		return true;
	}
	return false;
}

std::vector<Point> getPath(std::vector< std::vector<bool> >& maze){

	std::vector<Point> path;
	if( getPath(maze, maze.size()-1, maze[0].size()-1, path ) ){
		return path;
	}

	return std::vector<Point>();
}

int main()
{
	std::vector< std::vector<bool> > maze { {true,true,true }, {true, true,true}, {true,true,true} };
	auto a = getPath(maze);

	return 0;
}
