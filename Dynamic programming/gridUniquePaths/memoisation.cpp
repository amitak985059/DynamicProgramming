class Solution {
    int f(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j]; 
        
        int up = f(i - 1, j, dp);
        int left = f(i, j - 1, dp);

        return dp[i][j] = up + left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));  // Fixing dp size to m × n
        return f(m - 1, n - 1, dp);
    }
};

   //link ofthe problem https://leetcode.com/problems/unique-paths/