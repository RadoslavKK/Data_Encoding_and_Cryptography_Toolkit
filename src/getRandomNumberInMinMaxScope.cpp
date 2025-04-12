#include "getRandomNumberInMinMaxScope.h"
#include <random>

short getRandomNumberInMinMaxScope(int min, int max)
{
    std::random_device rd;  // Seed for random number engine
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}