class Solution {
    public:
      int findMaxSum(vector<int>& arr) {
          int n = arr.size();
          if (n == 0) return 0;
          if (n == 1) return arr[0];
  
          int prev2 = 0, prev1 = 0, curr = 0;
          
          for (int i = 0; i < n; i++) {
              curr = max(prev1, arr[i] + prev2);
              prev2 = prev1;
              prev1 = curr;
          }
          
          return prev1;
      }
  };