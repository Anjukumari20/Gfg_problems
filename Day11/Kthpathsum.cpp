#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumK(Node *root, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Base case: to count a path from root to a node
        return countPaths(root, 0, k, prefixSumCount);
    }
    
private:
    int countPaths(Node* node, int currentSum, int k, unordered_map<int, int>& prefixSumCount) {
        if (!node) return 0;
        
        currentSum += node->data;
        int count = prefixSumCount[currentSum - k];
        
        prefixSumCount[currentSum]++;
        
        count += countPaths(node->left, currentSum, k, prefixSumCount);
        count += countPaths(node->right, currentSum, k, prefixSumCount);
        
        prefixSumCount[currentSum]--; // Backtrack
        
        return count;
    }
};

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    Solution sol;
    int k = 3;
    cout << "Number of downward paths with sum " << k << ": " << sol.sumK(root, k) << endl;
    
    return 0;
}
