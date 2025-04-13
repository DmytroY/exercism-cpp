#include "grade_school.h"
#include <iostream>
#include <algorithm>

namespace grade_school {

// TODO: add your solution here

std::map<int, std::vector<std::string>> school::roster() const { return _roster; }

void school::add(std::string name, int grade) {
    if(school::_roster.find(grade) != school::_roster.end()) {
        school::_roster[grade].push_back(name);
        sort(school::_roster[grade].begin(), school::_roster[grade].end());
    } else {
        school::_roster[grade] = {name,};
    }
}

std::vector<std::string> school::grade(int grade) const {
    try {
        return school::_roster.at(grade);
    } catch(const std::out_of_range& e){
        return {};
    }
    
}

}  // namespace grade_school
