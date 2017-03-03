#include <array>
#include <stdio.h>
#include <iostream>

using namespace std;

void orderArrays(array<int,10>& A, int valid_A_values,  array<int,5>& B)
{
	int indexA{valid_A_values-1};
	int indexB{B.size()-1};

	int end{A.max_size() - 1};
	while(indexA != -1 && indexB != -1){
		if(A[indexA] >= B[indexB]){
			A[end] = A[indexA];
			indexA--;
		} else {
			A[end] = B[indexB];
			indexB--;
		}
		end--;
	}

	while(indexA != -1){
		A[end] = A[indexA];
		indexA--;
		end--;
	} 
	
	while(indexB != -1){
		A[end] = B[indexB];
		indexB--;
		end--;
	}

}


int main()
{
	std::array<int,10> A {0,1,2,3,4};
	std::array<int,5> B {0,1,2,3,4};

	orderArrays(A,5,B);
	
	for(auto const& v : A)
		cout << v << endl;

	return 0;
}
