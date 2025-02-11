#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
        if (!root) return true;
        if (root->data <= minVal || root->data >= maxVal) return false;
        return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
    }
    
    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    // Example test case
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(5);
    
    Solution sol;
    if (sol.isBST(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    return 0;
}
