#include <bits/stdc++.h>
using namespace std;

bool f(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(index == 0) return arr[0] == target;

    if (dp[index][target] != -1)
        return dp[index][target];

    bool notTaken = f(index-1, target, arr, dp);
    bool taken = false;
    if(arr[index] <= target)
        taken = f(index-1, target-arr[index], arr, dp);

    return dp[index][target] = taken || notTaken;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}
