#include <iostream>
using namespace std;

// Definition for a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (!root) return NULL;
        
        // If both n1 and n2 are smaller than root, LCA lies in the left subtree
        if (n1->data < root->data && n2->data < root->data)
            return LCA(root->left, n1, n2);
        
        // If both n1 and n2 are greater than root, LCA lies in the right subtree
        if (n1->data > root->data && n2->data > root->data)
            return LCA(root->right, n1, n2);
        
        // If n1 and n2 lie on different sides, root is the LCA
        return root;
    }
};

// Function to insert a node into the BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main() {
    Solution solution;
    
    // Example 1: Construct BST
    Node* root = new Node(5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 8);
    
    Node* n1 = root->right->right; // Node 7
    Node* n2 = root->right->right->right; // Node 8
    Node* lca = solution.LCA(root, n1, n2);
    cout << "LCA of " << n1->data << " and " << n2->data << " is: " << lca->data << endl;
    
    return 0;
}
