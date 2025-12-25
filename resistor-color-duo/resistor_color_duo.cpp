#include "resistor_color_duo.h"
#include <map>

namespace resistor_color_duo {

int value(std::vector<std::string> colors){
    std::map<std::string, int> color_map = {
        {"black", 0},
        {"brown", 1},
        {"red", 2},
        {"orange", 3},
        {"yellow", 4},
        {"green", 5},
        {"blue", 6},
        {"violet", 7},
        {"grey", 8},
        {"white", 9}
    };

    return color_map.at(colors[0]) * 10 + color_map.at(colors[1]);
}

}  // namespace resistor_color_duo
