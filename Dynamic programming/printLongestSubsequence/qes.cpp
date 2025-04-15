#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();

    // dp[i][j] will represent LCS of text1[0..i-1] and text2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the dp table
    int len = dp[n][m];
    string ans(len, '$');
    int index = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if(text1[i - 1] == text2[j - 1]){
            ans[index--] = text1[i - 1];
            i--;
            j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return ans;
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    string lcs = longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence: " << lcs << endl;
    return 0;
}



class Solution {
    int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){ 
        // ✅ Passed dp by reference to avoid copying on each recursive call

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) // ✅ Correct comparison between text1 and text2
            return dp[i][j] = 1 + f(i - 1, j - 1, text1, text2, dp);

        return dp[i][j] = max(f(i - 1, j, text1, text2, dp), f(i, j - 1, text1, text2, dp));
        // ✅ Fixed typo and ensured correct memoization
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, text1, text2, dp); 
        // ✅ Adjusted starting indices to n-1 and m-1 to match 0-based indexing
    }
};