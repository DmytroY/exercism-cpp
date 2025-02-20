#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec{1, 2, 3, 4, 5};
    // vector<int> vec = {1, 2, 3, 4, 5};
    cout << *vec.begin() << std::endl;
    cout << *(vec.end()-1) << std::endl;
    cout << vec.front() << std::endl;
    cout << vec.back() << std::endl;
  
    return 0;
}