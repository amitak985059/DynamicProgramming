
#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    int prev = 0, prev2 = 0;

    for (int ind = 1; ind < n; ind++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[ind] - height[ind - 1]);
        if (ind > 1)
            jumpTwo = prev2 + abs(height[ind] - height[ind - 2]);

        int curri = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
