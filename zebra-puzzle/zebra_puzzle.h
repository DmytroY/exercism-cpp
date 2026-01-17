#pragma once

#include <string>
#include <array>
#include <algorithm>

namespace zebra_puzzle {

struct Solution {
    std::string drinksWater;
    std::string ownsZebra;
};

Solution solve();


}  // namespace zebra_puzzle
