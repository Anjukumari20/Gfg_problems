class Solution {
    public:
        int robLinear(vector<int>& nums) {
            int prev1 = 0, prev2 = 0;
            for (int num : nums) {
                int temp = prev1;
                prev1 = max(prev2 + num, prev1);
                prev2 = temp;
            }
            return prev1;
        }
        
        int maxValue(vector<int>& arr) {
            int n = arr.size();
            if (n == 1) return arr[0];
    
            // Case 1: Exclude last house
            vector<int> case1(arr.begin(), arr.end() - 1);
            // Case 2: Exclude first house
            vector<int> case2(arr.begin() + 1, arr.end());
    
            return max(robLinear(case1), robLinear(case2));
        }
    };