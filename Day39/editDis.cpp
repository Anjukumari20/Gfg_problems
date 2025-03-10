#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i; // Remove all characters
        for (int j = 0; j <= n; j++) dp[0][j] = j; // Insert all characters

        // Filling the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};

// Driver code
int main() {
    Solution sol;
    string s1 = "geek", s2 = "gesek";
    cout << sol.editDistance(s1, s2) << endl; // Output: 1

    string s3 = "abcd", s4 = "bcfe";
    cout << sol.editDistance(s3, s4) << endl; // Output: 3

    return 0;
}
