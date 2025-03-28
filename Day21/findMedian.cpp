#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxHeap; // Max-heap for lower half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for upper half
        vector<double> medians;
        
        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
            
            // Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // Compute the median
            if (maxHeap.size() == minHeap.size()) {
                medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                medians.push_back(maxHeap.top());
            }
        }
        
        return medians;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> result = sol.getMedian(arr);
    
    for (double median : result) {
        cout << median << " ";
    }
    cout << endl;
    
    return 0;
}
