#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Initialize the first column (target = 0) as true
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Initialize the first row (using only arr[0])
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP table
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}
