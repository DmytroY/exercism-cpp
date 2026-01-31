#include "spiral_matrix.h"

namespace spiral_matrix {

// TODO: add your solution here
void turn_rigth(int& dx, int& dy){
    if(dx == 1){dx = 0; dy = 1; return;}
    if(dy == 1){dx = -1; dy = 0; return;}
    if(dx == -1){dx = 0; dy = -1; return;}
    if(dy == -1){dx = 1; dy = 0; return;}
}

std::vector<std::vector<uint32_t>> spiral_matrix(int n){
    if(!n) return {};
    std::vector<std::vector<uint32_t>> result (n, std::vector<uint32_t> (n, 0));
    int x{0}, dx{1}, y{0}, dy{0}, i{1};
    result[0][0] = i;
    while(i < n * n ){
        //if next possible position is our of range or alredy filled - turn right
        if(x + dx >= n || x + dx < 0 || y + dy >= n || y + dy < 0 || result[y+dy][x+dx]){
            turn_rigth(dx, dy);
        } 
        x += dx; y += dy; i++;
        result[y][x] = i;
    }
    return result;
}
}  // namespace spiral_matrix
