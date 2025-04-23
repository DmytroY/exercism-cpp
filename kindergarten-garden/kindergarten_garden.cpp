#include "kindergarten_garden.h"
#include <vector>
#include <algorithm>

namespace kindergarten_garden {

// TODO: add your solution here
    std::vector<std::string> names{
        "Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};

    kindergarten_garden::Plants to_enum(char c){
        switch (c) {
        case 'C' : return kindergarten_garden::Plants::clover;
        case 'G' : return kindergarten_garden::Plants::grass;
        case 'V' : return kindergarten_garden::Plants::violets;
        case 'R' : return kindergarten_garden::Plants::radishes;
        };
        return kindergarten_garden::Plants::error;
    }

    //plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Charlie")
    std::array<kindergarten_garden::Plants, 4> plants(std::string garden, std::string name){
        auto it = std::find(names.begin(), names.end(), name);
        int i = std::distance(names.begin(), it);

        std::array<kindergarten_garden::Plants, 4> result =
         {to_enum(garden[2*i]), to_enum(garden[2*i+1]),
            to_enum(garden[garden.size()/2 + 2*i + 1]), to_enum(garden[garden.size()/2 + 2*i + 2]) };

        return result;
    }
}  // namespace kindergarten_garden
