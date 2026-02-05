#include "rail_fence_cipher.h"

namespace rail_fence_cipher {

std::string encode(const std::string& plaintext, int num_rails){
    size_t n = plaintext.size();
    // create fence of optional char with num_rails rails
    std::vector<std::vector<std::optional<char>>> v(num_rails, std::vector<std::optional<char>>(n));

    // fill fence with message
    int x{-1}, y{-1}, dir{1};
    for(char c : plaintext){
        x++;
        y += dir;
        v[y][x] = c;
        if(y == (num_rails - 1)) dir =  -1;
        if(y == 0) dir = 1;
    }

    // read encoded message
    std::string out{};
    for(int j = 0; j < num_rails; j++){
        for(size_t i = 0; i < n; i++){
            if(v[j][i]) out.push_back(v[j][i].value());
        }  
    }

    return out;
}

std::string decode(const std::string& ciphertext, int num_rails){
    size_t n = ciphertext.size();
    // create fence of optional char with num_rails rails
    std::vector<std::vector<std::optional<char>>> v(num_rails, std::vector<std::optional<char>>(n));

    // fill fence with placeholders in correct positions
    int y{-1}, dir{1};
    for(size_t x = 0; x < n; x++){
        y += dir;
        v[y][x] = ' ';
        if(y == (num_rails - 1)) dir =  -1;
        if(y == 0) dir = 1;
    }

    // fill plaseholders with ciphertext
    int k{0};
    for(int j = 0; j < num_rails; j++){
        for(size_t i = 0; i < n; i++){
            if(v[j][i]){
                v[j][i].value() = ciphertext[k];
                k++;
            } 
            
        }  
    }

    // read text
    std::string out{};
    for(size_t i = 0; i < n; i++){
        for(int j = 0; j < num_rails; j++){
            if(v[j][i]) out.push_back(v[j][i].value());
        }
    }
    return out;
}

}  // namespace rail_fence_cipher
