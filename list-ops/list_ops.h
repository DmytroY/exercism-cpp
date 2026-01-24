#pragma once
#include <vector>
#include <functional>

namespace list_ops {

// TODO: add your solution here

template <typename T>
inline size_t length(const std::vector<T> v){
    size_t n{0};
    for(auto it = v.begin(); it != v.end(); it++) n++;
    return n;
}

template <typename T>
inline void append(T& left, const T& right) {
    size_t sizel = length(left);
    left.resize(sizel + length(right));
    for(size_t i = 0; i < length(right); i++){
        left[sizel + i] = right[i];
    }
}

template <typename T>
inline std::vector<T> concat(const std::vector<std::vector<T>> v){
    std::vector<T> result{};
    for(auto item : v){
        append(result, item);
    }
    return result;
}

inline std::vector<int> filter(const std::vector<int> v, std::function<int(int)> func){
    std::vector<int> result;
    size_t s{0};

    for(int item : v){
        if(func(item)){
            s++;
            result.resize(s);
            result[s-1] = item;
        }
    }
    return result;
}


}  // namespace list_ops
