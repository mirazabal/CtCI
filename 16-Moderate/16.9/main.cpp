#include <exception>
#include <iostream>


int64_t negate(int64_t a){
	int64_t neg{0};
	int64_t newSign = a < 0 ? 1 : -1;
	int64_t delta{newSign};

	while(a != 0){
		if( ((a + delta > 0) && (a > 0)) || ((a + delta < 0) && ( a < 0)) ) {
			neg += delta;
			a += delta;
			delta = delta + delta;
		}else{
			neg += newSign;
			a += newSign;
			delta = newSign;
		}
	}
	return neg;
}


int64_t substrate(int64_t x, int64_t y){
	return x + negate(y);
}


int64_t divide(int64_t x, int64_t y){

	if(y == 0)
		throw std::runtime_error("Trying to divide by 0");

	int64_t retVal{0};
	int32_t sign = 1;


	if(x < 0){
		x = negate(x);
		sign = -1;
	} 
	if(y < 0){
		y = negate(y);
		sign = (sign == 1) ? -1 : 1;
	}

	while(x > y){
		retVal++;	
		x = substrate(x,y);
	}

	return (sign == -1) ? negate(retVal) : retVal;
}


int multiply(int x, int y){

	if(x > y)
		return multiply(y,x);

	if(x == 0 || y == 0)
		return 0;

	int64_t sign = ( ((x > 0) && (y < 0)) || ((x < 0) && (y > 0)) ) ? -1 : 1;
	if(x < 0)
		x = negate(x);
	if(y < 0)
		y = negate(y);

	int64_t retVal{0};
	for(int i = 0; i < y; ++i){
		retVal += x;
	}

	return (sign == -1) ? negate(retVal) : retVal;
}


int main()
{
	auto res_m = multiply(-5,-5);
	auto res_d = divide(40,6);

	std::cout << "res_m = " << res_m << '\n';
	std::cout << "res_d = " << res_d << '\n';
	return 0;
}
