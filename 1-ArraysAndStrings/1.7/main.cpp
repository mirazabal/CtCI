#include <array>
#include <vector>

void rotateMatrix_90( std::array< std::array<int, 5 >, 5> &matrix)
{
	for(int layer = 0; layer < matrix.size()/2; layer++ ){
		int first = layer;
		int last = matrix.size() -1 - layer;

		for(int i = first; i < last; i ++){
			int offset = i - first;

			int top = matrix[first][i];

			//left top
			matrix[first][i] = matrix[last-offset][first];
			// bottom left
			matrix[last-offset][first] = matrix[last][last-offset];
			// right to bottom
			matrix[last][last-offset] = matrix[i][last];
			// top to right
			matrix[i][last] = top;
		}
	}

};



int main()
{
	std::array< std::array <int , 5>, 5> mat;
//	int mat[5][5];
	int val{0};
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			mat[i][j] = val++;
		}
	}

	rotateMatrix_90(mat);

	return 0;
};


