#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
        int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
            if (i == 0 && j == 0) return grid[0][0];
            if (i < 0 || j < 0) return 1e9; // Return a large number to avoid choosing out-of-bound paths.

            if (dp[i][j] != -1) return dp[i][j];

            int up = grid[i][j] + solve(i - 1, j, grid, dp);
            int left = grid[i][j] + solve(i, j - 1, grid, dp);

            return dp[i][j] =  min(up, left);
        }

    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize dp table with -1
            return solve(m - 1, n - 1, grid, dp);
        }
};
