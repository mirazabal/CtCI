#include <stdio.h>


void* allocate_malloc(size_t required_bytes, size_t aligment)
{
	void* p = (void*)malloc( required_bytes + aligment - 1 );
	if(NULL == p)
		return NULL;

	void* q = (void*)( (size_t(p)+ aligment - 1) & ~(aligment-1) );	
	((void**)q)[-1] = p;
	
	return q;
}

void aligned_free(void *q)
{
	void* p = ((void**)q)[-1];
	free(p);
}


int main()
{



	return 0;
}
