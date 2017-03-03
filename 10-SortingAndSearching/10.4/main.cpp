
class Listy{

	public:

	int operator[](int index)
	{
		return -1;
	}

	int elementAt(int searchedVal)
	{
	
	}

};


int searchListy(Listy const& l, int searchedValue){

	int index = 1;
	while( Listy[index] != -1)
		index *= 2;
	
	int startIndex = index/2;
	int endIndex = index;

	index = startIndex + (endIndex-startIndex)/2;

	while(true)
	{
		if(l[index] == -1)
			endIndex = index;
		 else
			startIndex = index;

		index = startIndex + (endIndex - startIndex)/2;
		
		if(endIndex - startIndex < = 1)
			break;;
	}


	int end = endIndex;
	int start = 0;

	int middle = start + (end-start)/2;
	
	while(true)
	{
	
		if(searchedValue == l[middle])
			return middle;

		if(middle == start || middle == end)
			return -1;

		if( searchedValue > l[middle])
		{
			start = middle + 1;
		} else {
			end = middle -1;
		}
			
		middle =  start + (end-start)/2; 
	}


}



int main()
{

	return 0;
}
