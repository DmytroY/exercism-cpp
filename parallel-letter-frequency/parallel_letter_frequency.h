#pragma once
#include <array>
#include <algorithm>
#include <vector>
#include <map>
#include <atomic>
#include <execution>

namespace parallel_letter_frequency {
    std::map<char, unsigned> frequency(std::vector<std::string_view> texts);
}
