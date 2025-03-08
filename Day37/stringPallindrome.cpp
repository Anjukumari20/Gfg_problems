class Solution {
    public:
      string longestPalindrome(string &s) {
          // code here
            int n = s.size();
          if (n == 0) return "";
          
          int start = 0, maxLen = 1;
          
          // Function to expand around center and return length
          auto expandAroundCenter = [&](int left, int right) {
              while (left >= 0 && right < n && s[left] == s[right]) {
                  left--;
                  right++;
              }
              return right - left - 1; // Length of palindrome
          };
          
          for (int i = 0; i < n; i++) {
              int len1 = expandAroundCenter(i, i);       // Odd length palindrome
              int len2 = expandAroundCenter(i, i + 1);   // Even length palindrome
              int len = max(len1, len2);
              
              if (len > maxLen) {
                  maxLen = len;
                  start = i - (len - 1) / 2;
              }
          }
          
          return s.substr(start, maxLen);
          
      }
  };