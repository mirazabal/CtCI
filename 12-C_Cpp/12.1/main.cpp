#include <iostream>
#include <stdio.h>
#include <string.h>

void printLastKLines(char const* filePath,size_t numLines){

	FILE* fp;
	fp = fopen(filePath, "r" );
	if(fp == NULL)
		return;
	
	char** buff = (char**)malloc(sizeof(char*) * numLines );

	for(size_t i = 0; i < numLines; i++){
		buff[i] = (char*)calloc( sizeof(char) , 150 );
	}

	size_t indexCircularBuff {0};
	char* line = NULL;
	size_t len = 0;

	while( getline( &line, &len, fp) != -1){

		strcpy(buff[indexCircularBuff] , line );
	
		if(indexCircularBuff == numLines - 1)
			indexCircularBuff = 0;
		else
			indexCircularBuff++;
	}

	for(size_t i = 0; i < numLines; ++i){
		printf("values for %s",  buff[indexCircularBuff] );
		
		if(indexCircularBuff == numLines-1)
			indexCircularBuff = 0;
		else
			indexCircularBuff++;
	}

	free(line);
	fclose(fp);

	for(int i = 0; i < numLines; i++)
		free(buff[i]);	

	free(buff);
}

int main(){
	printLastKLines("data.txt", 10);
	
	
	return 0;
}
