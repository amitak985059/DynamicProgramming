#include <vector>
using namespace std;

int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp) {
    if (i == n - 1) {
        return triangle[i][j];  // Corrected base case
    }
    if (dp[i][j] != -1) return dp[i][j];

    int d = triangle[i][j] + f(i + 1, j, triangle, n, dp);
    int d1 = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(d, d1);
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));  // Corrected 2D DP initialization
    return f(0, 0, triangle, n, dp);
}
