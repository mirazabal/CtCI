#include <stack>
#include <iterator>
#include <iostream>
#include <stdio.h>


void printPossibleParens(size_t leftParens, size_t rightParens, std::string str, size_t max)
{
	if(str == ""){
		str.append("(");
		leftParens++;
		printPossibleParens(leftParens,rightParens,str,max);
	}

	if( leftParens == max && leftParens == rightParens ){
		std::cout << str <<'\n';	
		return;
	}

	if(leftParens == max){
		rightParens++;
		str.append(")");
		printPossibleParens(leftParens,rightParens,str,max);
		return;
	}

	leftParens++;
	str.append("(");
	printPossibleParens(leftParens,rightParens,str,max);
	str.erase(std::end(str));

	if (leftParens > rightParens){
		rightParens++;
		str.append(")");
		printPossibleParens(leftParens,rightParens,str,max);
		str.erase(std::end(str));
	}
}



void printPossibleParens(size_t i)
{
	if(i == 0) return;



}

int main()
{
	return 0;
}
