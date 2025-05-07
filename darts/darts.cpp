#include "darts.h"
#include <cmath>

namespace darts {

// TODO: add your solution here
int score(float x, float y){
    float r = sqrt(x*x + y*y);
    if(r <= 1) return 10;
    if(r <= 5) return 5;
    if(r <= 10) return 1;
    return 0;
}
}  // namespace darts