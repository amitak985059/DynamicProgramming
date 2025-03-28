#include <vector>
#include <algorithm>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    // Base case: When it's the first day (day == 0)
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(points[0][task], maxi);
            }
        }
        return maxi;
    }

    // Check if the result is already computed
    if (dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    // Try all tasks except the one done the previous day
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    // Store the result in dp array and return
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Initialize the memoization table with -1
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // Start the recursion from the last day with no task restriction (last = 3)
    return f(n - 1, 3, points, dp);
}
