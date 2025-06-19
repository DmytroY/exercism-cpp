#include "alphametics.h"

namespace alphametics {

// TODO: add your solution here

std::vector<std::string> split(std::string text, const std::string& separator){
    std::vector<std::string> result;
    while(true){
        auto pos = text.find(separator);
        if(pos != std::string::npos) {
            result.push_back(text.substr(0, pos));
            text = text.substr(pos + separator.length(), text.length() - pos);
        } else {
            result.push_back(text.substr(0, text.length()));
            break;
        }
    }
    return result;
}

bool verify(const std::map<char, int>& solution, const std::map<char, long long>& weights){
    long long checksum{0};
    for(auto kv : solution){
        checksum += (kv.second * weights.at(kv.first));
    }
    return checksum == 0;
}

bool backtrack(std::map<char, int>& solution, std::vector<bool>& used,const std::map<char, long long>& weights, const std::set<char>& first){
    if (solution.size() == weights.size() && verify(solution, weights) ) {
        return true;
    }

    for(auto kv : weights){
        if(solution.find(kv.first) == solution.end()){
            for(int i = 0; i <= 9; i++ ){
                if(first.find(kv.first) != first.end() && i == 0) continue;
                if(used[i] == false){
                    solution[kv.first] = i;
                    used[i] = true;
                    if(backtrack(solution, used, weights, first)) return true;
                    solution.erase(kv.first);
                    used[i] = false;
                }
            }
        }
    }
    return false;
}

std::optional<std::map<char, int>> solve(std::string text){
    
    std::map<char, int> solution;  // current variant of map
    std::map<char, long long> weights; // weigths precalculater for every character, depend on positions and count
    std::vector<std::string> words; // vector of TERMS and SUM as last worint; 
    std::vector<bool> used(10, false); // which digit we already used
    std::set<char> first; // set of first chars. leading digit of a multi-digit number must not be zero

    auto left_right = split(text, " == "); //left_rigth[0] are TERMS, left_rigth[1] is SUM
    words = split(left_right[0], " + ");
    words.push_back(left_right[1]); // last word is SUM

    for(auto word : words){
        if (word.size() > 1){first.insert(word.at(0));} // insert to set of first chars

        long long d{1}; // weigths for TERMS will be positive
        if(word == left_right[1]) d = -1;  // weights for SUM will be negative
        for(auto it = word.rbegin(); it < word.rend(); it++) {
            weights[*it] += d; // summarize weights of letters in different words
            d *= 10; // weights for letters from rigth to left are: 1, 10, 100, 1000 .....
        }
    }

    backtrack(solution, used, weights, first);
    if(solution.size() == 0) return std::nullopt;
    return solution;
}

}  // namespace alphametics
