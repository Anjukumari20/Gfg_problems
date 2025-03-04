class Solution {
    public:
      int lis(vector<int>& arr) {
          // code here
          int n = arr.size();
             vector<int> dp(n, 1); // Initialize LIS array with 1
  
          for (int i = 1; i < n; i++) {
              for (int j = 0; j < i; j++) {
                  if (arr[i] > arr[j]) {
                      dp[i] = max(dp[i], dp[j] + 1);
                  }
              }
          }
  
          return *max_element(dp.begin(), dp.end());
      }
  };
  