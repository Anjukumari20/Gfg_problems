#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool findTarget(Node* root, int target) {
        unordered_set<int> seen;
        return inorder(root, target, seen);
    }
    
private:
    bool inorder(Node* node, int target, unordered_set<int>& seen) {
        if (!node) return false;
        
        if (inorder(node->left, target, seen)) return true;
        
        if (seen.count(target - node->data)) return true;
        seen.insert(node->data);
        
        return inorder(node->right, target, seen);
    }
};

// Example usage
int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);
    
    Solution sol;
    cout << sol.findTarget(root, 12) << endl; // Output: 1 (true)
    
    Node* root2 = new Node(9);
    root2->left = new Node(5);
    root2->right = new Node(10);
    root2->left->left = new Node(2);
    root2->left->right = new Node(6);
    root2->right->right = new Node(12);
    
    cout << sol.findTarget(root2, 23) << endl; // Output: 0 (false)
    
    return 0;
}
