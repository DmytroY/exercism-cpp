#include "resistor_color.h"
#include <map>

namespace resistor_color {
    std::vector<std::string> colorvector = {
        "black",
        "brown",
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "violet",
        "grey",
        "white"
    };

    // creating map of {color_name, color_number} to speed up future search of color code
    std::map<std::string, int> colormap = []() {
        std::map<std::string, int> temp_map;
        for (unsigned i = 0; i < colorvector.size(); i++){
            temp_map[colorvector.at(i)] = i;
        }
        return temp_map;
    }();

    int color_code(std::string color){ return colormap.at(color); }

    std::vector<std::string> colors(){ return colorvector; }

}  // namespace resistor_color
