#if !defined(PANGRAM_H)
#include <string>
#include <set>
#include <bitset>
#define PANGRAM_H

namespace pangram {

// TODO: add your solution here

// set aproach
// inline bool is_pangram(std::string text) {
//     std::set<char> letters{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//     for(char c : text) {
//         c = tolower(c);
//         if(letters.count(c)) {
//             letters.erase(c);
//         }
//     }
//     if (letters.empty()) return true;
//     return false;
// }

// bitset aproach
inline bool is_pangram(std::string text) {
    std::bitset<26> bitset26;
    for(char c : text) {
        if(std::isalpha(c)){
            c = tolower(c);
            bitset26.set(c - 'a');
        }
    }
    return bitset26.all();
}

}  // namespace pangram

#endif  // PANGRAM_H