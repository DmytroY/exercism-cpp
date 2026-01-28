#pragma once
#include <vector>

namespace knapsack {

struct Item {
    int weight;
    int value;
};

int maximum_value(const int&, const std::vector<Item>&);

}  // namespace knapsack
