#include <stdio.h>


void reverseAndPrintString(char* str)
{
	char* end = str;
	size_t sizeStr{0};

	while( *end ){
		sizeStr++;	
		end++;
	}
	end--;

	char* start = str;
	char temp;
	while(sizeStr > 2){
		temp = *end;
		*end = *start;
		*start = temp;

		start++;
		end--;
		sizeStr -= 2;
	}
	printf( "%s", str);
}

int main()
{
	char str[32] =  { "Hay tela marinera... "} ;
	reverseAndPrintString(str);
	return 0;
}
