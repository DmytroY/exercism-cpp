#include "yacht.h"

namespace yacht {

// TODO: add your solution here

unsigned int score(std::vector<int> dices, std::string category){
    unsigned int result{0};
    std::vector<int> counter = {0,0,0,0,0,0,0};

    for(int item : dices){
        counter[item]++;
        if(category == "choice") result += item;
        if(category == "ones" && item == 1) result += item;
        if(category == "twos" && item == 2) result += item;
        if(category == "threes" && item == 3) result += item;
        if(category == "fours" && item == 4) result += item;
        if(category == "fives" && item == 5) result += item;
        if(category == "sixes" && item == 6) result += item;
        if(category == "yacht") {result = 50; if(item != dices[0]) { return 0; }}
        if(category == "full house") result += item; 
    }   

    if(category == "full house" && (!std::count(counter.begin(), counter.end(), 3) || !std::count(counter.begin(), counter.end(), 2))) return 0;

    if(category == "four of a kind" && (std::count(counter.begin(), counter.end(), 4) || std::count(counter.begin(), counter.end(), 5))) {
        if(dices[0] == dices[1] || dices[0] == dices[2]) {
            return dices[0] * 4;
        } else return dices[1] * 4;
    }
    if(category == "little straight" && *std::max_element(counter.begin(), counter.end()) < 2 && counter[6] == 0) return 30;
    if(category == "big straight" && *std::max_element(counter.begin(), counter.end()) < 2 && counter[1] == 0) return 30;


    return result;
}

}  // namespace yacht
