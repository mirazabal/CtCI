#include <iostream>
#include <cstdint>

uint64_t sum(uint64_t a, uint64_t b)
{
    if (!a)
        return b;

    auto add_no_carry = a^b;
    auto carry_no_add = (a&b) << 1;
    return sum( carry_no_add, add_no_carry );
};

template <typename T>
constexpr T sum_templ(T a, T b)
{    
    return a == 0 ? b : sum( (a&b) << 1, a^b );
}; 

  
 
int main()
{
    std::cout << sum(33,45) << '\n';
    std::cout << sum_templ<uint64_t>(10,25) << '\n';
    return 0; 
}  
