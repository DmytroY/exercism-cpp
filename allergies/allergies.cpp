#include "allergies.h"
#include <iostream>

namespace allergies {

// TODO: add your solution here

    std::map<int, std::string, std::greater<int>> allergenes_map = {
        {1,  "eggs"},
        {2,  "peanuts"},
        {4,  "shellfish"},
        {8,  "strawberries"},
        {16, "tomatoes"},
        {32, "chocolate"},
        {64, "pollen"},
        {128, "cats"},
    };

    // class allergy_test constructor
    allergy_test::allergy_test(int n) {

        // score over 255 convert to correct range
        while(n > 255) {
            n -= 256;
        }

        // build personal set of allergenes
        for(auto item : allergies::allergenes_map) {
            if(item.first <= n) {
                allergy_test::allergenes_set.insert(item.second);
                n -= item.first;
            }
        }

    };

    bool allergy_test::is_allergic_to(std::string food) {
        if(allergy_test::allergenes_set.find(food) != allergy_test::allergenes_set.end()) {return true;}
        return false;
    };

    std::unordered_set<std::string> allergy_test::get_allergies() {
        return allergy_test::allergenes_set;
    }

}  // namespace allergies
