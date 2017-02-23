#include <iostream>
#include <stdio.h>
#include <string>

std::string bitRepresentation(double val)
{
	std::string retStr;
	double comp{0.5};
	while(val != 0){
		if( val >= comp){
			retStr.append("1");
			val = val - comp;
		} else {
			retStr.append("0");
		}

		comp = comp/2;
		if(retStr.size() == 32){
			retStr = "ERROR";
			break;
		}
	}

	return retStr;
}



int main(){

	std::cout << bitRepresentation(0.8757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575757575) << std::endl;
	return 0;
}
