class Solution {
    public:
        vector<int> longestSubarray(vector<int>& arr, int x) {
            int n = arr.size();
            deque<int> maxDeque, minDeque; // To maintain max and min elements in the window
            int left = 0, bestStart = 0, maxLen = 0;
    
            for (int right = 0; right < n; right++) {
                // Maintain the maxDeque (decreasing order)
                while (!maxDeque.empty() && arr[maxDeque.back()] < arr[right]) {
                    maxDeque.pop_back();
                }
                maxDeque.push_back(right);
    
                // Maintain the minDeque (increasing order)
                while (!minDeque.empty() && arr[minDeque.back()] > arr[right]) {
                    minDeque.pop_back();
                }
                minDeque.push_back(right);
    
                // Check if window is invalid
                while (!maxDeque.empty() && !minDeque.empty() &&
                       (arr[maxDeque.front()] - arr[minDeque.front()] > x)) {
                    left++; // Shrink window from the left
                    if (maxDeque.front() < left) maxDeque.pop_front();
                    if (minDeque.front() < left) minDeque.pop_front();
                }
    
                // Update longest valid subarray
                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    bestStart = left;
                }
            }
    
            return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
        }
    };