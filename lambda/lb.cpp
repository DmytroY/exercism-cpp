#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main() {
    std::vector<int> numbers = {5, 4, 2, 7, 1, 6, 3, 8, 9, 10};
    
    std::function<bool(int, int)> sorting_logic = [] (int a, int b) -> bool { return a > b;}; // named lambda function
    std::sort(numbers.begin(), numbers.end(), sorting_logic);

    // sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b;}); // anonimous lambda function

    for (auto item :numbers) {
        std::cout << item << " ";
    }
    // 10 9 8 7 6 5 4 3 2 1
    return 0;
}