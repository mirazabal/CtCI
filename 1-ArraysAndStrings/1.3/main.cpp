


void URLify(char arr[], int arrSize, int lenght)
{
	int index {lenght - 1};
	for(int i = arrSize - 1 ; i > 0 ; i--){
		if(arr[index] != ' ')
		{
			arr[i] = arr[index];
		}else {
			arr[i] = (char)'0';
			i--;
			arr[i] = (char)'2';
			i--;
			arr[i] = (char)'%';	
		}
		index--;
	}

};




int main(){
	
	char arr[] = "My name is mikel      " ;
//	int arrSize = sizeof(arr)/sizeof(arr[0]); 
:x




	return 0;
};
