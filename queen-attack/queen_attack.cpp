#include "queen_attack.h"

namespace queen_attack {

// TODO: add your solution here
// constructor
chess_board::chess_board(std::pair<int, int> a, std::pair<int, int> b) {
    if(a.first >= 0 && a.first < 8 && a.second >= 0 && a.second < 8
    && b.first >= 0 && b.first < 8 && b.second >= 0 && b.second< 8 && a != b){
        _white = a;
        _black = b; 
    } else {
        throw std::domain_error("out of range");
    }
}

//getters
std::pair<int, int> chess_board::white() const {return _white;}
std::pair<int, int> chess_board::black() const{return _black;}

bool chess_board::can_attack() const {
    if(_white.first == _black.first || _white.second == _black.second) return true;
    if(abs(_white.first - _black.first) == abs(_white.second - _black.second)) return true;

    return false;
}

}  // namespace queen_attack
