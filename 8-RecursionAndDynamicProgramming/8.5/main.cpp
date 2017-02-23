#include <stdio.h>
#include <cstdlib>

int recursivelyMultiplyHelper(int bigger, int smaller)
{
	if(smaller == 0)
		return 0;

	if (smaller == 1)
		return bigger;

	int m = smaller << 1;

	int halfProduct = recursivelyMultiplyHelper(bigger,m);
	if( smaller % 2 == 0)
		return halfProduct + halfProduct;
	else
		return halfProduct + halfProduct + bigger;	
}

int recursivelyMultiply(int n1, int n2)
{
	int smaller = n1 < n2 ? n1 : n2;
	int bigger = n1 > n2 ? n1 : n2;
	return recursivelyMultiplyHelper(bigger,smaller);
}

int main()
{
	return 0;
}
