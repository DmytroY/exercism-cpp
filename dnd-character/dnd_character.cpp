#include "dnd_character.h"
#include <cmath>
#include <ctime>

namespace dnd_character {

int modifier(int constitution){
    return floor((constitution - 10) / 2.0);
}

int ability(){
    srand(time(0));
    return rand() % 16 + 3;
}

}  // namespace dnd_character
