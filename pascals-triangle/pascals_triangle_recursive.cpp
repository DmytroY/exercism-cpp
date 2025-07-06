#include "pascals_triangle.h"

namespace pascals_triangle {

// TODO: add your solution here
std::vector<int> arow(int k){
    // calculating k-th row of Paskal's triangle

    if(k == 1) return {{1},};  // basic case
    std::vector<int> prev_row = arow(k-1); //recursive call
    std::vector<int> this_row(prev_row.size() + 1); // declare resulting vector with size
    prev_row.insert(prev_row.begin(),0); // add 0 to begining
    prev_row.push_back(0); // add 0 to the end
    //calculating resulting row
    for(unsigned i = 0; i < prev_row.size() - 1; i++){
        this_row[i] = prev_row[i] + prev_row [i + 1];
    }
    return this_row;
}

std::vector<std::vector<int>> generate_rows(int k){
    std::vector<std::vector<int>> result;

    for(int r = 1; r <= k; r++){
        result.push_back(arow(r));
    }

    return result;
}
}  // namespace pascals_triangle
