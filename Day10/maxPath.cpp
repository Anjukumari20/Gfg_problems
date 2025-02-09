#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

class Solution {
public:
    int maxSum;
    
    int findMaxSum(Node* root) {
        maxSum = INT_MIN;
        findMaxPathSum(root);
        return maxSum;
    }
    
private:
    int findMaxPathSum(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // Compute the maximum path sum for left and right subtrees
        int leftMax = max(0, findMaxPathSum(node->left));
        int rightMax = max(0, findMaxPathSum(node->right));
        
        // Update the global maximum if needed
        maxSum = max(maxSum, leftMax + rightMax + node->data);
        
        // Return the max sum including this node
        return max(leftMax, rightMax) + node->data;
    }
};

// Example Usage
int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    
    Solution solution;
    cout << "Maximum Path Sum: " << solution.findMaxSum(root) << endl;
    
    return 0;
}
