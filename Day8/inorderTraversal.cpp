#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
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
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    
private:
    void inorderTraversal(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        
        // Recursively traverse the left subtree
        inorderTraversal(node->left, result);
        
        // Visit the current node
        result.push_back(node->data);
        
        // Recursively traverse the right subtree
        inorderTraversal(node->right, result);
    }
};

// Function to test the inorder traversal
int main() {
    // Creating the binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   
    //    4   5  
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution sol;
    vector<int> result = sol.inOrder(root);
    
    // Printing the result
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}