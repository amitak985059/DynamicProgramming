class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            vector<int> dp(m, 0);
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == 0 && j == 0) {
                        dp[j] = grid[i][j];  // Start point
                    } else {
                        int up = (i > 0) ? dp[j] : INT_MAX;
                        int left = (j > 0) ? dp[j - 1] : INT_MAX;
                        dp[j] = grid[i][j] + min(up, left);
                    }
                }
            }
            return dp[m - 1];
        }
    };
    