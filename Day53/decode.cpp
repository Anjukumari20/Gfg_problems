class Solution {
    public:
      int countWays(string &digits) {
          int n = digits.size();
          if (n == 0 || digits[0] == '0') return 0;
  
          vector<int> dp(n + 1, 0);
          dp[0] = 1;  // Base case: empty string
          dp[1] = 1;  // Single character decoding
  
          for (int i = 2; i <= n; i++) {
              int oneDigit = digits[i - 1] - '0';         // Single-digit
              int twoDigit = stoi(digits.substr(i - 2, 2)); // Two-digit
  
              if (oneDigit >= 1) 
                  dp[i] += dp[i - 1]; // Single-digit decoding
  
              if (twoDigit >= 10 && twoDigit <= 26) 
                  dp[i] += dp[i - 2]; // Two-digit decoding
          }
  
          return dp[n];
      }
  };
  