#include "flower_field.h"

namespace flower_field {

char get_or_space(const std::vector<std::string>& v, const int& x, const int& y){
    if (y < 0 || y >= static_cast<int>(v.size())) return ' ';
    if (x < 0 || x >= static_cast<int>(v[0].size())) return ' ';
    return v[y][x];
}

std::vector<std::string> annotate(std::vector<std::string> garden){
    size_t h = garden.size();
    if(garden.size() == 0) return garden;
    size_t w = garden[0].size();
    unsigned counter{0};

    for(size_t x = 0; x < w; x++){
        for(size_t y = 0; y < h; y++){
            if(garden[y][x] != '*'){
                counter = 0;
                for (int i : {-1, 0, 1}){
                    for (int j : {-1, 0, 1}){
                        if(get_or_space(garden, x + i, y + j) == '*') counter++;
                    }
                }
                if(counter) garden[y][x] = '0' + counter;
            }
        }
    }
    return garden;
}

}  // namespace flower_field
