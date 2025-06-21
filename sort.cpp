#include <iostream>
#include <vector>
#include <algorithm>

//g++ -g -O0 -o sort sort.cpp

// bool comp(int a, int b){
//     return a < b ? true : false;
// }

int main() {
    std::vector<std::pair<char, int>> data {{'a', 9}, {'b', 0}, {'c', -5}};

    std::sort(data.begin(), data.end(), [] (auto a, auto b) {return abs(a.second) > abs(b.second) ? true : false;});


    for(auto item : data) {std::cout << item. first << ":" << item.second << "\n"; }
    std::cout << "\n";
    return 0;
}