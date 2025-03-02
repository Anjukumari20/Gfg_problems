class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          // code here
           deque<int> dq;
          vector<int> result;
          
          for (int i = 0; i < arr.size(); i++) {
              // Remove elements out of the current window
              if (!dq.empty() && dq.front() == i - k)
                  dq.pop_front();
              
              // Remove elements smaller than the current one (maintain decreasing order)
              while (!dq.empty() && arr[dq.back()] <= arr[i])
                  dq.pop_back();
              
              // Add the current element index to the deque
              dq.push_back(i);
              
              // Store the maximum of the current window
              if (i >= k - 1)
                  result.push_back(arr[dq.front()]);
          }
          
          return result;
          
      }
  };
  