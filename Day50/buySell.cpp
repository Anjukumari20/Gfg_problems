class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int n = prices.size();
            if (n == 0) return 0;
            
            vector<int> left(n, 0), right(n, 0);
            
            // Calculate max profit if sold on or before day i
            int minPrice = prices[0];
            for (int i = 1; i < n; i++) {
                minPrice = min(minPrice, prices[i]);
                left[i] = max(left[i - 1], prices[i] - minPrice);
            }
            
            // Calculate max profit if bought on or after day i
            int maxPrice = prices[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                maxPrice = max(maxPrice, prices[i]);
                right[i] = max(right[i + 1], maxPrice - prices[i]);
            }
            
            // Compute the max sum of profits from both transactions
            int maxProfit = 0;
            for (int i = 0; i < n; i++) {
                maxProfit = max(maxProfit, left[i] + right[i]);
            }
            
            return maxProfit;
        }
    };