#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H
#include <utility>
#include <stdexcept>
#include <cmath>

namespace queen_attack {

// TODO: add your solution here
class chess_board{
    private:
        std::pair<int, int> _white, _black;

    public:
        chess_board(std::pair<int, int>, std::pair<int, int>);
        std::pair<int, int>white() const;
        std::pair<int, int>black() const;
        bool can_attack() const;
};

}  // namespace queen_attack

#endif  // QUEEN_ATTACK_H