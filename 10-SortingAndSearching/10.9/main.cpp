#include <iostream>
#include <stdio.h>

class Pos{
	public:
	Pos(int row, int col) :  row_(row), col_(col) 
	{
	
	}
	int row_;
	int col_;
};



Pos getValueInMatrix(int** mat, int startCols, int endCols, int startRows, int endRows, int valueSearched){


	if(startCols>= endCols && startRows >= endRows )
		return Pos(-1,-1);

	if(startRows == endRows){
		
		auto medCol = startCols + (endCols-startCols)/2;
		if(mat[startRows][medCol] == valueSearched)
			return Pos(startRows, medCol);
	
		if(valueSearched > medCol)
			return getValueInMatrix(mat, medCol+1, endCols, startRows, endRows, valueSearched);
		else
			return getValueInMatrix( mat, startCols, medCol-1, startRows, endRows,valueSearched);
	}

	auto medRow = startRows + (endRows-startRows)/2;

	if(mat[medRow][0] == valueSearched)
		return Pos(medRow,0);

	if( valueSearched > mat[medRow][0]){
		return getValueInMatrix(mat, startCols, endCols, medRow+1, endRows, valueSearched);
	} else {
		return getValueInMatrix(mat, startCols, endCols, startRows, medRow-1, valueSearched);
	}

}


Pos getValueInMatrix(int** mat, int numCols, int numRows, int valueSearched)
{
	return getValueInMatrix(mat, 0, numCols-1, 0, numRows-1, valueSearched);	
}	

int main()
{
	auto rows = 5;
	auto cols = 5;

	int** mat = (int**)malloc(rows*sizeof(int*));
	for(auto i = 0; i < rows; i++){
		mat[i] = (int*)malloc(cols*sizeof(int));
	}

	for(int i = 0; i < rows; i ++){
		for(int j = 0; j < cols; j++){
			mat[i][j] = i*10 + j;
		}
	}
	
	auto p = getValueInMatrix( mat, cols, rows, 63);

	std::cout << "col = " << p.col_  << " row = "<< p.row_ << '\n' ;


	for(int i = 0; i < rows; i++){
		free( (int*)mat[i] );
	}

	free((int**)mat);
	return 0;
}
