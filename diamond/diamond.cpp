#include "diamond.h"

namespace diamond {
// TODO: add your solution here
std::vector<std::string> rows(char c) {
    int n = c - 'A';
    int len = 2 * n + 1;

    std::vector<std::string> result;
    result.reserve(len);

    auto make_row = [&](int i) {
        std::string s(len, ' ');
        char ch = 'A' + i;
        s[n - i] = ch;
        s[n + i] = ch;
        return s;
    };

    for (int i = 0; i < n; ++i) result.push_back(make_row(i));
    for (int i = n; i >= 0; --i) result.push_back(make_row(i));
    
    return result;
}

}  // namespace diamond
