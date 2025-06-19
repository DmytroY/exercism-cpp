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

bool backtrack(std::map<char, int>& solution,
    std::vector<bool>& used,
    const std::map<char, long long>& weights,
    const std::set<char>& first);
    
bool verify(const std::map<char, int>& solution, const std::map<char, long long>& weights);


}  // namespace alphametics

#endif  // ALPHAMETICS_H