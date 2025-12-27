#pragma once
#include <utility>
#include <string>

namespace robot_simulator {

enum class Bearing {NORTH, EAST, SOUTH, WEST};

class Robot{
    private:
        std::pair<int, int> _p;
        Bearing _b;
    public:
        Robot(std::pair<int, int> position = {0, 0}, Bearing bearing = Bearing::NORTH) : _p(position), _b(bearing) {}

        std::pair<int, int> get_position() const { return _p;}

        Bearing get_bearing() const {return _b;}

        void turn_right() {_b = static_cast<Bearing>((static_cast<int>(_b) + 1) % 4);}

        void turn_left() {_b = static_cast<Bearing>((static_cast<int>(_b) + 3) % 4);}

        void advance() {
            switch (_b) {
            case Bearing::NORTH:
                _p.second++;
                break;
            case Bearing::EAST:
                _p.first++;
                break;
            case Bearing::SOUTH:
                _p.second--;
                break;
            case Bearing::WEST:
                _p.first--;
                break;            
            default:
                break;
            }
        }

        void execute_sequence(std::string instruction){
            //"RAALAL"
            for(char c : instruction){
                switch (c){
                    case 'R':
                        turn_right();
                        break;
                    case 'L':
                        turn_left();
                        break;
                    case 'A':
                        advance();
                        break;                   
                    default:
                        break;
                }
            }
        }

};
    
}  // namespace robot_simulator
