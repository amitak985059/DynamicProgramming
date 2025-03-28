#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int> prev(4, 0);

    // Base case: Filling the first row
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    // Fill the DP table
    for (int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) { // 'last' represents the last task done
            temp[last] = 0; // Reset to 0 before computing max
            
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp; // Update prev to store current day's results
    }

    return prev[3]; // The best score when we are not restricted by the last task
}
