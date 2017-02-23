#include <stdio.h>
#include <vector>

enum class Color
{
	Blue,
	Red,
	Green
};


class Cell{
	public:
		Cell(Color c) : color{c}
	   	{
	   	}

	Color color;
};



void paintFill(std::vector<std::vector<Cell>>& arr, size_t x, size_t y, Color newColor, Color oldColor)
{
	if(arr[x][y].color == oldColor)
	{
		arr[x][y].color = newColor;
		if( x + 1 < arr.size()-1)
			paintFill(arr, x+1,y , newColor, oldColor)

		if( x != 0)
			paintFill(arr, x-1, y, newColor, oldColor);

		if( y + 1 < arr[0].size()-1)
			paintFill(arr,x, y+1, newColor, oldColor);

		if (y != 0)
			paintFill(arr, x, y-1, newColor, oldColor);
	}
}

int main()
{
	return 0
}
