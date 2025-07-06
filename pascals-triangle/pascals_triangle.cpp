#include "pascals_triangle.h"

namespace pascals_triangle {

// TODO: add your solution here
std::vector<std::vector<int>> generate_rows(int k){
    std::vector<std::vector<int>> result;

    for(int r = 0; r < k; r++){
        // base case
        if(r == 0){
            result.push_back({{1}});
            continue;
        } 

        std::vector<int> temp_row = result[r - 1];
        temp_row.insert(temp_row.begin(), 0);
        temp_row.push_back(0);

        std::vector<int> new_row;
        for(unsigned i = 0; i < temp_row.size() - 1; i++){
            new_row.push_back(temp_row[i] + temp_row [i + 1]);
        }
        result.push_back(new_row);
    }
    return result;
}
}  // namespace pascals_triangle
