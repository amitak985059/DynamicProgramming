#include <bits/stdc++.h>
int f(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums);
    int notPick = 0 + f(ind - 1, nums);

    return dp[ind] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n - 1, nums, dp);
}
