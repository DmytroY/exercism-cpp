#include <iostream>

void myFunc(int& i) {
    if (i > 5) {
        i = 777;
    }
}

int main() {
    int i = 10;
    myFunc(i);
    std::cout << i << std::endl;
    return 0;
}