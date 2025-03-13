class Solution {
    public:
      // Function to return max value that can be put in knapsack of capacity W.
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n = val.size();
          vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
          
          // Build the dp table
          for (int i = 1; i <= n; i++) {
              for (int w = 1; w <= W; w++) {
                  if (wt[i - 1] <= w) {
                      dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                  } else {
                      dp[i][w] = dp[i - 1][w];
                  }
              }
          }
          
          return dp[n][W];
      }
  };
  