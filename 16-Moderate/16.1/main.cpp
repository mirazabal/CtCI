#include <iostream>

using namespace std;

void swapNumber(int& a, int& b){
	a = a - b;
	b = a + b;
	a = b - a;
}


int main()
{
	int a{2};
	int b{3};

	swapNumber(a,b);

	cout << "a = "  << a << " b= " << b << endl;

	return 0;
}
