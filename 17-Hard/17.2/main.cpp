#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

void shuffle_iteratively(std::vector<uint64_t>& cards)
{
    for(int i = 1; i < cards.size(); ++i){
        int rand_idx = rand() % i;
        std::swap(cards[i], cards[rand_idx]);
    }
}

std::vector<uint64_t> shuffle_recursively(std::vector<uint64_t>& cards, int i)
{
    if(i == 0)
        return cards;

    shuffle_recursively(cards, i-1 );

    int rand_idx = rand() % i;
    std::swap(cards[i], cards[rand_idx]);
    return cards;
}

int main()
{
    std::vector<uint64_t> vec_rec(52);
    std::iota( std::begin(vec_rec), std::end(vec_rec), 0);
    std::vector<uint64_t> vec_ite = vec_rec;

    auto ret_rec = shuffle_recursively(vec_rec, vec_rec.size());
    for(auto i : ret_rec)
        std::cout << i << '\n';

    std::cout << " " << '\n';

    shuffle_iteratively(vec_ite);
    for(auto i : vec_ite)
        std::cout << i << '\n';

    return 0;
}

