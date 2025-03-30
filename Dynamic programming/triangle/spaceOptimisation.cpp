#include <vector>
using namespace std;

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<int> front(n, 0); // Stores the DP values of the next row
    vector<int> curr(n, 0);  // Stores the DP values of the current row

    // Initialize `front` with the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n-1][j];  // Base case
    }

    // Start filling from the second-last row to the top
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // Current cell value = triangle[i][j] + min(from directly below, from below-right)
            curr[j] = triangle[i][j] + min(front[j], front[j+1]);
        }
        front = curr; // Move the `curr` row values to `front` for the next iteration
    }

    return front[0]; // The topmost element contains the final answer
}
