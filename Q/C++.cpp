#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

int main()
{
    std::vector<std::string> foods = {"猪脚饭", "沙县小吃", "卤肉饭"};

    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<size_t> dist(0, foods.size() - 1);

    size_t index = dist(rng);
    std::cout << "今天吃: " << foods[index] << std::endl;
    return 0;
}