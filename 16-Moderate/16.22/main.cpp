#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

enum class DIRECTION{
	UP,
	RIGHT,
	LEFT,
	DOWN
};

void generate_table(std::vector<std::vector<int>>& table, uint64_t nSteps)
{
	//std::random_device rd;
	std::mt19937 mt;
	mt.seed(std::random_device()());   
	std::uniform_int_distribution<std::mt19937::result_type> dist(0,2);
	table.resize(nSteps);
	for(auto row = 0; row != nSteps; ++row ) {
		table[row].resize(nSteps);
		for(auto col = 0; col != nSteps; ++col)
			table[row][col] = dist(mt);
	}	
}

void printPassed( std::vector<std::vector<int>>& vecPassed)
{
	for(auto row = std::begin(vecPassed); row != std::end(vecPassed); ++row ) {
		for(auto col = row->begin() ; col != row->end(); ++col){
			if(*col)
				std::cout << "x";
			else
				std::cout << "-";
		}
		std::cout << '\n';
	}
}


void printKSteps(uint64_t nSteps)
{
	std::vector<std::vector<int>> table;
	table.reserve(nSteps);

	DIRECTION actualDir = DIRECTION::LEFT;
	generate_table(table, 2*nSteps);
	
	std::pair<uint64_t, uint64_t> actualPos(nSteps, nSteps);

	std::vector<std::vector<int>> vecPassed(2*nSteps, std::vector<int>(2*nSteps,0) );

	vecPassed[actualPos.first][actualPos.second] = 1;	

	for(auto i = 0u; i < nSteps; ++i){
		auto color = table[actualPos.first][actualPos.second]; 
		table[actualPos.first][actualPos.second] = color == 0 ? 1 : 0;  
	
		switch(actualDir){
			case DIRECTION::UP:
				actualDir =  color== 0 ? DIRECTION::RIGHT : DIRECTION::LEFT;
				actualPos.first = actualPos.first;
				actualPos.second = ++actualPos.second;
				vecPassed[actualPos.first][actualPos.second] = 1;	
				break;

			case DIRECTION::RIGHT:
				actualDir = color == 0 ? DIRECTION::DOWN : DIRECTION::UP;
				actualPos.first = ++actualPos.first;
				actualPos.second = actualPos.second;
				vecPassed[actualPos.first][actualPos.second] = 1;	
				break;

			case DIRECTION::LEFT:
				actualDir = color == 0 ? DIRECTION::UP : DIRECTION::DOWN;
				actualPos.first = --actualPos.first;
				actualPos.second = actualPos.second;
				vecPassed[actualPos.first][actualPos.second] = 1;	
				break;

			case DIRECTION::DOWN:
				actualDir = color == 0 ? DIRECTION::LEFT : DIRECTION::RIGHT;
				actualPos.first = actualPos.first;
				actualPos.second = --actualPos.second;
				vecPassed[actualPos.first][actualPos.second] = 1;	
				break;

			default:
				break;
		
		}
	
	}
	printPassed(vecPassed);
}




int main()
{
	printKSteps(10);
	return 0;
}
