#include <iostream>
using namespace std;

int main() {
    // define separate lambda func
    auto dvakrat = [](int i) {return 2 * i;};

    for(int i = 0; i < 5; i++){
        //inline lambda. passing parameter by caching variable from environment
        cout << [i]() {return i;} () << " -- ";
        //inline lambda. passing parameter as argument
        cout << [](int i) {return i * i;} (i) << " -- ";
        //using predefined labmda func
        cout << dvakrat(i) << endl;
    }

    return 0;
}