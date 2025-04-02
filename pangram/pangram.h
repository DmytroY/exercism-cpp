#if !defined(PANGRAM_H)
#include <string>
#include <set>
#define PANGRAM_H

namespace pangram {

// TODO: add your solution here
inline bool is_pangram(std::string text) {
    std::set<char> letters{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(char c : text) {
        c = tolower(c);
        if(letters.count(c)) {
            letters.erase(c);
        }
    }
    if (letters.empty()) return true;
    return false;
}
}  // namespace pangram

#endif  // PANGRAM_H