#include <array>
#include <string>


void merge(std::string& str, int l, int m, int r )
{
	char L[m-l+1];
	char R[r-m];

	// fill the arrays
	for(int i = 0; i < m-l+1; i++){
		L[i] = str[l + i];
	}
	for(int i = 0; i < r-m; i++){
		R[i] = str[m + i+ 1];
	}


	int n1{m-l+1};
	int left_counter{0};
	int n2{r-m};
	int right_counter{0};

	int str_counter{l};

	while(n1 != left_counter && n2 != right_counter ){
		if(L[left_counter] <= R[right_counter] ){
			str[str_counter] = L[left_counter];
			left_counter++;
		}else{
			str[str_counter] = R[right_counter];
			right_counter++;
		}
		str_counter++;
	}

	while(n1 != left_counter ){
		str[str_counter] = L[left_counter];
		left_counter++;
		str_counter++;
	}
	while(n2 != right_counter){
		str[str_counter] = R[right_counter];
		right_counter++;
		str_counter++;
	}

};

void merge_sort(std::string& str, int l, int r)
{
	if(l < r){
		int m = (l+r)/2;
		merge_sort(str, l, m);
		merge_sort(str, m+1, r);
		merge(str,l, m,r );
	}
};


bool has_unique_chars_no_additional_space(std::string& str)
{
	merge_sort(str, 0, str.size() - 1);

	for(int i = 1; i < str.size(); i ++){
		if(str[i] == str[i-1])
			return false;
	}

	return true;
};

bool has_unique_chars(std::string& str)
{
	if(str.size() > 256)
	   	return false; // ASCII has no more than 256 characters	

	std::array<bool, 256> arr;
	for(auto& b : arr)
		b = false;
	for(char& s : str)
	{
		if( arr[s] == true ){
			return false;
		}
		else{
			arr[s] = true;
		}
	}
	return true;
};

int main()
{
	std::string str("awerdsxcvfghtpoikjuzhgbwnm");
	bool val = has_unique_chars(str);
	bool val2 =  has_unique_chars_no_additional_space(str);

	return 0;
};

