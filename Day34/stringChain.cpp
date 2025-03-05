class Solution {
    public:
        int longestStringChain(vector<string>& words) {
            // Sort words based on their lengths
            sort(words.begin(), words.end(), [](const string &a, const string &b) {
                return a.size() < b.size();
            });
    
            unordered_map<string, int> dp; // To store the longest chain length for each word
            int maxChain = 1; // At least one word forms a chain of length 1
    
            for (const string& word : words) {
                int best = 1; // Minimum chain length for the current word
                for (int i = 0; i < word.size(); i++) {
                    string prevWord = word.substr(0, i) + word.substr(i + 1); // Remove one character
                    if (dp.find(prevWord) != dp.end()) {
                        best = max(best, dp[prevWord] + 1);
                    }
                }
                dp[word] = best; // Store the best chain length for this word
                maxChain = max(maxChain, best); // Update maximum chain length
            }
    
            return maxChain;
        }
    };