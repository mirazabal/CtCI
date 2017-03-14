
int** my2DAlloc(size_t rows, size_t cols)
{
	
	int header = sizeof(int)*rows;
	int data = sizeof(int)*rows*cols;

	int** retData = (int**)(malloc(data+header));

	if( NULL == retData)
		return NULL;

	int* buff = (int*)(retData + rows);
   for(int i = 0; i < rows; i++){
	retData[i] = buff + i*cols;
   }	
   return retData;
}




int main()
{
	return 0;
}
