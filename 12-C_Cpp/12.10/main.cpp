#include <stdio.h>


void* allocate_malloc(size_t required_bytes, size_t aligment)
{
	void* p = (void*)malloc( required_bytes + aligment - 1 );
	void* q = (void*)( (size_t(p)+ aligment - 1) & ~(aligment-1) );	
	return q;
}


int main()
{
	return 0;
}
