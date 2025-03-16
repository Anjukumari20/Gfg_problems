class Solution {
    public:
        int minJumps(vector<int>& arr) {
            int n = arr.size();
            if (n <= 1) return 0; // Already at the last index
            if (arr[0] == 0) return -1; // Cannot move forward
    
            int jumps = 1;  // At least one jump is needed
            int maxReach = arr[0]; // Maximum index we can reach
            int steps = arr[0]; // Steps left in the current range
    
            for (int i = 1; i < n; i++) {
                if (i == n - 1) return jumps; // If we reached the last index
    
                maxReach = max(maxReach, i + arr[i]); // Update max reachable index
                steps--; // Use one step
    
                if (steps == 0) { // If no steps left, we must jump
                    jumps++; // Increase jump count
                    if (i >= maxReach) return -1; // If we can't go further, return -1
                    steps = maxReach - i; // Refill steps with new range
                }
            }
    
            return -1; // In case we never reach the last index
        }
    };