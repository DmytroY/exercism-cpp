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

bool verify(const std::vector<std::string>& terms, const std::string& sum, const std::map<char, int>& my_map){
    // should not be empty
    if(my_map.empty()) return false;

    // values should be unique
    std::set<int> seen;
    for(const auto& item : my_map){
        // set.insert() returns pair where second part is insertion success indicator
        if(seen.insert(item.second).second == false) return false;
    }

    int correct_sum{0};
    for(unsigned i = 0; i < sum.length(); i++){
            correct_sum +=my_map.at(sum[sum.length() - 1 - i]) * pow(10, i);
    }
    if(correct_sum == 0) return false;

    int calculated_sum{0};
    for(std::string term : terms){
        for(unsigned i = 0; i < term.length(); i++){
            calculated_sum +=my_map.at(term[term.length() - 1 - i]) * pow(10, i);
        }
    }
    return calculated_sum == correct_sum;
}

std::optional<std::map<char, int>> solve(std::string text){
    std::vector<std::string> left_rigth = split(text, " == ");
    std::vector<std::string> terms = split(left_rigth[0], " + "); // vector with terms
    std::string sum = left_rigth[1]; // sum

    // initialize resulting map
    std::map<char, int> my_map;
    for(char c : text){ if(isalpha(c))my_map[c] = 0; }
 
    // leading digit of multidigit number must not be zero. 
    // there is a set of chars we never shoul assign 0
    std::set<char> forbidden;
    for(std::string term : terms) {
        if(term.size() > 1) forbidden.insert(term[0]);
    }
    forbidden.insert(sum[0]);

    // n is decimal representation of all my_map values. Assign every decimal digit as my_map values
    for(unsigned long long n = 0; n < pow(10, my_map.size()); n++){
        unsigned long long t = n; // 
        for(auto item : my_map){
            int value = t - (t/10)*10;

            // do not assign 0 to forbidden char, assing 1 instead
            if(value == 0 && forbidden.find(item.first) != forbidden.end()) {
                my_map[item.first] = 1;
            } else {
                my_map[item.first] = value;
            }
            t /= 10; // for the next place in number
        }

        // if we found correct combination
        if(verify(terms, sum, my_map)) return my_map;
    }
    return std::nullopt;
}

}  // namespace alphametics
