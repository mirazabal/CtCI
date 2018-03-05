#include <algorithm>
#include <bitset>
#include <iostream>
#include <random>
#include <vector>

std::vector<uint64_t> deleteFromVector(std::bitset<1> val ,uint8_t pos, std::vector<uint64_t> vs)
{
    vs.erase(std::remove_if(std::begin(vs), std::end(vs), [=](uint64_t val_){  
                                std::bitset<64> bs{val_};
                                return (bs[pos] == val[0]);
                                } ), std::end(vs));
    return vs;
}

uint64_t missingNumber(std::vector<uint64_t> vs, uint8_t pos)
{
    if(vs.size() == 1 || vs.size() == 2 ){
        std::bitset<64> bs{vs[0]};
        bs[pos] == 0 ? bs[pos] = 1 : bs[pos] = 0; 
        return bs.to_ullong();
    }
    
    uint64_t numberZeros{0};
    uint64_t numberOnes{0};

    for(auto val : vs){
        std::bitset<64> bs{val};
        bs[pos] == 0 ? numberZeros++ : numberOnes++;
    }

    bool isEven = (vs.size() % 2 == 0); 
    if( isEven && (numberZeros > numberOnes + 1) ) 
        vs = deleteFromVector(0, pos, vs);
    else if( !isEven && (numberZeros > numberOnes) )
        vs = deleteFromVector(0, pos, vs);
    else
        vs = deleteFromVector(1, pos, vs);

    return missingNumber(vs,++pos);
}


int main()
{
    std::vector<uint64_t> vs(10);
    std::iota(std::begin(vs), std::end(vs), 0u);
    vs.erase( std::remove(std::begin(vs), std::end(vs), 6), std::end(vs) );

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(vs), std::end(vs), rng);

    std::cout << missingNumber(vs,0) << '\n';
    return 0;
}
