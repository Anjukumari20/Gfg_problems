
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
         unordered_map<int, int> prefixSumMap; 
         int maxLen = 0;  
         int cumulativeSum = 0; 

    
        for (int i = 0; i < arr.size(); i++) {
    
        int value = (arr[i] == 0) ? -1 : 1;
        cumulativeSum += value;

        
        if (cumulativeSum == 0) {
            maxLen = i + 1;
        }

        
        if (prefixSumMap.find(cumulativeSum) != prefixSumMap.end()) {
        
            int subarrayLength = i - prefixSumMap[cumulativeSum];
            maxLen = max(maxLen, subarrayLength);
        } else {
            
            prefixSumMap[cumulativeSum] = i;
        }
    }

    return maxLen;
    }
};
