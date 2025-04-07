class Solution {
    int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
        }

        if(dp[ind][target]!=-1)
            return dp[ind][target];

        int notTaken = findWaysUtil(ind-1, target, arr, dp);
        int taken = 0;
        if(arr[ind] <= target)
            taken = findWaysUtil(ind-1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken + taken;
    }

    int findWays(vector<int> &num, int k){
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return findWaysUtil(n-1, k, num, dp);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int n : nums) totalSum += n;

        // Check for validity
        if((target + totalSum) % 2 != 0 || (target + totalSum) < 0) return 0;

        int subsetSum = (target + totalSum) / 2;
        return findWays(nums, subsetSum);
    }
};
