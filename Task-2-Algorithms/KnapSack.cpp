#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int knapsack(int W,
             vector<int>& wt,
             vector<int>& val,
             int n) {

    vector<vector<int>> dp(n + 1,
                           vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {

            if(wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] +
                    dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {

    cout << "===== 0/1 KNAPSACK =====\n\n";

    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;

    cout << "Weights: {10, 20, 30}\n";
    cout << "Values : {60, 100, 120}\n";
    cout << "Capacity = 50\n\n";

    int profit = knapsack(
        capacity,
        weights,
        values,
        values.size()
    );

    cout << "Maximum Profit = "
         << profit << endl;

    cout << "\n----- Runtime Analysis -----\n";

    int itemCounts[] = {10, 50, 100};

    for(int n : itemCounts) {

        vector<int> wt(n);
        vector<int> val(n);

        for(int i = 0; i < n; i++) {
            wt[i] = (i % 20) + 1;
            val[i] = (i % 50) + 10;
        }

        auto start = high_resolution_clock::now();

        int ans = knapsack(
            100,
            wt,
            val,
            n
        );

        auto stop = high_resolution_clock::now();

        auto duration =
        duration_cast<microseconds>(stop - start);

        cout << "Items = "
             << n
             << " | Profit = "
             << ans
             << " | Runtime = "
             << duration.count()
             << " microseconds\n";
    }

    cout << "\nTime Complexity: O(n × W)\n";

    return 0;
}