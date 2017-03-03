#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool checkPossiblePlaceQueen(size_t row, size_t col, vector<size_t> const& res){

	for(size_t rowsQueen = 0; rowsQueen < res.size(); rowsQueen++){
		size_t colsQueen = res[rowsQueen];

		if(colsQueen == col)
			return false;

		auto distRows = row > rowsQueen ? row - rowsQueen : rowsQueen - row;
		auto distCols = col > colsQueen ? col - colsQueen : colsQueen - col;

		if(distCols == distRows)
			return false;
	}

	return true;
}


void placeQueen(int row, vector<size_t> result, vector< vector<size_t> >& vVectors){

	if(row == 8)
		vVectors.push_back(result);
	else{
		for(auto cols = 0; cols < 8; cols++){
			if(checkPossiblePlaceQueen(row,cols,result)){
				result.emplace_back(cols);	
				placeQueen(row+1,result, vVectors);	
				result.pop_back();
			}
		}
	}
}




void get8Queens()
{
	vector<size_t> v {};
	vector< vector<size_t > > res;

	placeQueen(0,v, res);
	cout << " Possible solutions = " << res.size() << endl;
	for(auto const& a : res){
		for(auto const& b : a){
			cout << b << endl;
		}
		cout << " " << endl;
	}
}	



int main()
{
	get8Queens();
	return 0;
}
