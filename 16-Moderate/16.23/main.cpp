#include <iostream>
#include <random>

int rand5()
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0,4);
	return dis(gen);
}

int rand7()
{
	for(;;){
		auto res = 5*rand5() + rand5();
		if(res < 21)
			return res % 7;
	}
}

int main()
{
	for(int i = 0; i < 100; i++)
		std::cout << rand7() << '\n'; 
	return 0;
}
