#include "sublist.h"

namespace sublist {


// enum class List_comparison{equal, sublist, superlist, unequal};

//    [2, 4] 
// [1, 2, 3, 4, 5]

List_comparison sublist(std::vector<int> v1, std::vector<int> v2){
    if(v1 == v2) return List_comparison::equal;

    if(v1.size() < v2.size()){
        if(v1.size() == 0) return List_comparison::sublist;
        // begin and end of window on v2
        auto begin = v2.begin();
        auto end = v2.begin()+ v1.size();
        // clide window and compare v1 to window
        std::vector<int> window(v1.size());
        for(std::size_t i = 0; i <= v2.size() - v1.size(); i++){
            copy(begin + i, end + i, window.begin());
            if(v1 == window) return List_comparison::sublist;
        }
        return List_comparison::unequal;
    }

    if(v1.size() > v2.size()){
        if(v2.size() == 0) return List_comparison::superlist;
        auto begin = v1.begin();
        auto end = v1.begin()+ v2.size();
        std::vector<int> window(v2.size());
        for(std::size_t i = 0; i <= v1.size() - v2.size(); i++){
            copy(begin + i, end + i, window.begin());
            if(v2 == window) return List_comparison::superlist;
        }
        return List_comparison::unequal;
    }

    return List_comparison::unequal;
}

}  // namespace sublist
