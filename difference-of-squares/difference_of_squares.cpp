#include "difference_of_squares.h"

namespace difference_of_squares {

// TODO: add your solution here
int square_of_sum(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum * sum;
}


int sum_of_squares(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum = sum + i * i;
    }
    return sum;
}


int difference(int n) {
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
