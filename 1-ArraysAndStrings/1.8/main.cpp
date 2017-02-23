#include <array>
#include <vector>

void zeroMatrix( std::array< std::array<int, 10>,10>& matrix)
{
	std::vector<int> vecColumms;
	std::vector<int> vecRows;
	for(int i = 0; i < matrix.size(); i ++){
		for(int j = 0; j < matrix[i].size()){
			if(matrix[i][j] == 0){
				vecColumms.push_back(j);
				vecRows.emplace_back(i);
			}
		}
	}

	for(auto val: vecColumms){
		for(int i = 0; i < matrix.size(); i++)
			matrix[i][val] = 0;
	}

	for(auto val: vecRows){
		for(int j = 0; j < matrix[0].size(); j++){
			matrix[val][j] = 0;
		}
	}

};




int main()
{
	return 0;
};
