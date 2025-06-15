#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H
#include <string>
#include <map>
#include <optional>
#include <set>
#include <vector>
#include <cmath>

namespace alphametics {

// TODO: add your solution here
std::optional<std::map<char, int>> solve(std::string text);
std::vector<std::string> split(std::string text, const std::string& separator);
bool verify(const std::vector<std::string>& terms, const std::string& sum, const std::map<char, int>& my_map);

}  // namespace alphametics

#endif  // ALPHAMETICS_H