#include "robot_name.h"
#include <random>

namespace robot_name {

// TODO: add your solution here

    char rA(){ return rand() % 26 + 65; }
    char rD(){ return rand() % 10 + 48; }
    std::string generate_name() {
        srand(std::random_device{}());
        while(true){
            std::string candidate_name = std::string{rA()} + rA() + rD() + rD() + rD();
            if(robot::_names.find(candidate_name) == robot::_names.end()) {
                robot::_names.insert(candidate_name);
                return candidate_name;
            }
        }    
    }

    std::set<std::string> robot::_names{};

    robot::robot(){
        _name = generate_name();
    }

    std::string robot::name() const{
        return robot::_name;
    }
    
    void robot::reset() {
        _name = generate_name();
    }
}  // namespace robot_name
