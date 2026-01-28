#include "knapsack.h"

namespace knapsack {

// TODO: add your solution here
int maximum_value(const int& m, const std::vector<Item>& items){
    // m is max weight
    int n = items.size(); // count of items
    // create knapsack value DP table where value = f(choosen items, weigth)
    // item\capasity   1kg      2kg     3kg     4kg
    // 0                0       0       0       0
    // 1{2, 20}         0       20      20      20
    // 2{2, 20}         0       20      20      40
    // 3{4, 50}         0       20      20      50

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for(int i = 0; i <= n; i++){
        for(int c = 0; c <= m; c++){
            if(i == 0 || c == 0){
                dp[i][c] = 0;
                continue;
            }

            if(items[i-1].weight > c){
                dp[i][c] = dp[i-1][c];
                continue;
            }

            dp[i][c] = std::max(dp[i-1][c], items[i-1].value + ((c >= items[i-1].weight) ? dp[i-1][c-items[i-1].weight] : 0 ));
        }
    }
    return dp[n][m];
}

}  // namespace knapsack
