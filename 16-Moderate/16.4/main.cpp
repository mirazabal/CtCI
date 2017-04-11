#include <exception>
#include <iostream>
#include <vector>

using namespace std;

enum class Piece { circles ,crosses, none }; 


void checkTable(vector< vector<Piece>>& table){
	if(table.size() == 0)
		throw runtime_error(" ");
	if(table[0].size() == 0)
		throw runtime_error(" ");

	if(table.size() != table[0].size() )
		throw runtime_error(" ");
}

Piece checkHorizontal(vector< vector<Piece>>& table){

	for(auto i = 0; i < table.size(); i++ ){
		for(auto j = 0; j < table[0].size(); ++j){
			if( table[i][0] != table[i][j]){
				break;
			}
			if(table[i][0] == table[i][j] && j == table[i].size() - 1 ){
				return table[i][0];
			}
		}			
	}
}

Piece checkVertical(vector< vector<Piece>>& table){

	for(auto i = 0; i < table.size(); i++ ){
		for(auto j = 0; j < table[0].size(); ++j){
			if(table[0][j] != table[i][j]){
				break;
			}
			if(table[0][j] == table[i][j] && j == table[i].size() - 1 ){
				return table[0][j];
			}
		}			
	}
}

Piece checkDiagonal( vector< vector<Piece> >& table){
	for(auto i = 0, auto j = 0; i < table.size(); ++i, ++j){
		if(table[0][0] != table[i][j]){
			break;
		}
		if(table[0][0] == table[i][j] && j == table[i].size() - 1 ){
			return table[0][j];
		}
	}
}

Piece ticTacToe(vector< vector<Piece>>& table){

	checkTable(table);

	auto p1 = checkHorizontal(table);
	auto p2 = checkVertical(table);
	auto p3 = checkDiagonal(table);
	
	if(p1 != Piece::none )
		return p1;
	if(p2 != Piece::none)
		return p2;
	if(p3 != Piece::none)
		return p3;

	return Piece::none;
}

int main()
{
	

	return 0;
}
