#include <iostream>
#include <numbers>
// for use <numbers> at least C++20 version needed.
// compile vith version flag:  g++ -std=c++23 -o test test.cpp

using namespace std;
int main() {
    cout << "pi :" << numbers::pi << endl;
    cout << "pi_v<float>: " << numbers::pi_v<float> << endl;
    cout << "pi_v<double>: " << numbers::pi_v<double> << endl;
    cout << "pi_v<long double>: " << numbers::pi_v<long double> << endl;

    return 0;
}