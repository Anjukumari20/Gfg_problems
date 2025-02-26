class Solution {
    public:
      vector<int> maxOfMins(vector<int>& arr) {
          // Your code here
            int n = arr.size();
          vector<int> left(n, -1), right(n, n), ans(n, 0);
          stack<int> s;
          
          // Find previous smaller element for each element
          for (int i = 0; i < n; i++) {
              while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
              if (!s.empty()) left[i] = s.top();
              s.push(i);
          }
          
          // Clear stack for next computation
          while (!s.empty()) s.pop();
          
          // Find next smaller element for each element
          for (int i = n - 1; i >= 0; i--) {
              while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
              if (!s.empty()) right[i] = s.top();
              s.push(i);
          }
          
          // Compute window size for each element
          vector<int> res(n, 0);
          for (int i = 0; i < n; i++) {
              int window_size = right[i] - left[i] - 1;
              res[window_size - 1] = max(res[window_size - 1], arr[i]);
          }
          
          // Fill in the rest of the results
          for (int i = n - 2; i >= 0; i--) {
              res[i] = max(res[i], res[i + 1]);
          }
          
          return res;
          
      }
  };
  