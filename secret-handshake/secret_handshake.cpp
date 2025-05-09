#include "secret_handshake.h"

namespace secret_handshake {

// TODO: add your solution here
std::vector<std::string> commands(int n) {
    std::map<int, std::string> actions{
        {0, "wink"},
        {1, "double blink"},
        {2, "close your eyes"},
        {3, "jump"}
    };
    std::vector<std::string> result{};
    for(int i = 0; i < 4; i++){
        if(n & (1 << i)) result.push_back(actions[i]);
    }
    if(n & 0b10000) std::reverse(result.begin(), result.end());
    return result;
}}  // namespace secret_handshake
