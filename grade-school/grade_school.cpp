#include "grade_school.h"
#include <iostream>

namespace grade_school {

// TODO: add your solution here

std::map<int, std::vector<std::string>> school::roster() const { return _roster; }

void school::add(std::string name, int grade) {
    if(school::_roster.find(grade) != school::_roster.end()) {
        //std::cout << "pushing to the _roaster name " << name << std::endl;
        school::_roster[grade].push_back(name);

    } else {
        school::_roster[grade] = {name,};
    }

    // std::cout << " -------- addition to roster --------" << std::endl;
    // for(auto item : _roster[grade]) {
    //     std::cout << item << std::endl;
    // }

}

}  // namespace grade_school
