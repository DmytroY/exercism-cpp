#include "sum_of_multiples.h"
#include <set>

namespace sum_of_multiples {

// TODO: add your solution here

    // variant 1
    // int to(std::vector<int> items, int level) {
    //     std::set<int> mtpl {};
    //     for(int item : items) {
    //         for(int n = item; n < level; n += item) {
    //             mtpl.insert(n);
    //         }
    //     }
    //     int result{0};
    //     for(int item : mtpl) {
    //         result += item;
    //     }
    //     return result;
    // }

    // variant 2
    int to(std::vector<int> items, int level) {
        int result{0};
        for(int i = 1; i < level; i++){
            for(int item : items){
                if( i % item == 0) {
                    result += i;
                    break;
                }
            }
        }
        return result;
    }

}  // namespace sum_of_multiples
// to({4, 6}, 15) )
// 4, 6, 8, 12, = 30