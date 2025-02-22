#include <iostream>

void myFunc1(int& i) {
    if (i > 5) i= 777;
}

void myFunc2(int* i) {
    if(*i > 5)  *i = 999;
}

int main() {
    int a = 10;
    myFunc1(a);
    std::cout << a << std::endl;

    int b{20};
    myFunc2(&b);
    std::cout << b << std::endl;
    return 0;
}