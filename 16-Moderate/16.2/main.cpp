#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int getOccurrence(string& book, string& word){
	
	size_t occurrence{0};
	size_t pos{0};
	while( (pos = book.find(word,pos)) != string::npos ){
		occurrence++;
		pos += word.length();
	}
	return occurrence;
}

int main(){

	string book{"por mi coco pasa un tren y hace tiempo que perdio la via mi coco"};
	string word{"Juan"};
	cout << getOccurrence(book, word) << endl;
	return 0;
}
