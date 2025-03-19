class Solution {
    public:
        int maxProfit(vector<int>& prices, int k) {
            int n = prices.size();
            if (n == 0 || k == 0) return 0;
    
            // If k is greater than n/2, then it's equivalent to unlimited transactions
            if (k >= n / 2) {
                int maxProfit = 0;
                for (int i = 1; i < n; i++) {
                    if (prices[i] > prices[i - 1])
                        maxProfit += prices[i] - prices[i - 1];
                }
                return maxProfit;
            }
    
            // DP table
            vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    
            for (int t = 1; t <= k; t++) {
                int maxDiff = -prices[0];
                for (int d = 1; d < n; d++) {
                    dp[t][d] = max(dp[t][d - 1], prices[d] + maxDiff);
                    maxDiff = max(maxDiff, dp[t - 1][d] - prices[d]);
                }
            }
    
            return dp[k][n - 1];
        }
    };