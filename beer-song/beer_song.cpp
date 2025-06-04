#include "beer_song.h"

namespace beer_song {

// TODO: add your solution here
    std::string verse(int n){
        
        // if(n > 2){
        //     char result[150];
        //     sprintf(result, "%d bottles of beer on the wall, %d bottles of beer.\n"
        // "Take one down and pass it around, %d bottles of beer on the wall.\n", n, n, n-1);
        //     return result;
        // }

        // if(n == 2) return "2 bottles of beer on the wall, 2 bottles of beer.\n"
        //     "Take one down and pass it around, 1 bottle of beer on the wall.\n";

        // if(n == 1) return "1 bottle of beer on the wall, 1 bottle of beer.\n"
        //     "Take it down and pass it around, no more bottles of beer on the "
        //     "wall.\n";

        // return "No more bottles of beer on the wall, no more bottles of beer.\n"
        //     "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        // } 

        switch (n)
        {
        case 0:
            return "No more bottles of beer on the wall, no more bottles of beer.\n"
            "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
            //break;

        case 1:
            return "1 bottle of beer on the wall, 1 bottle of beer.\n"
            "Take it down and pass it around, no more bottles of beer on the "
            "wall.\n";
            //break;
        
        case 2:
            return "2 bottles of beer on the wall, 2 bottles of beer.\n"
            "Take one down and pass it around, 1 bottle of beer on the wall.\n";
            //break;

        default:
            char result[150];
            sprintf(result, "%d bottles of beer on the wall, %d bottles of beer.\n"
            "Take one down and pass it around, %d bottles of beer on the wall.\n", n, n, n-1);
            return result;
            //break;
        }
    }

    std::string sing(int h, int l) {
        std::string result;
        for(int i = h ; i >= l; i--){
            result = result + verse(i) + "\n";
        }
        result.pop_back();
        return result;
    }

    std::string sing(int h) {
        return sing(h, 0);
    }    
}  // namespace beer_song
