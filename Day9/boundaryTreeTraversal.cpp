#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    void addLeftBoundary(Node *root, vector<int> &res) {
        Node *curr = root->left;
        while (curr) {
            if (!(curr->left == nullptr && curr->right == nullptr)) 
                res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addLeafNodes(Node *root, vector<int> &res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(root->data);
            return;
        }
        addLeafNodes(root->left, res);
        addLeafNodes(root->right, res);
    }
    
    void addRightBoundary(Node *root, vector<int> &res) {
        Node *curr = root->right;
        stack<int> s;
        while (curr) {
            if (!(curr->left == nullptr && curr->right == nullptr)) 
                s.push(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        
        res.push_back(root->data);
        if (root->left || root->right) {
            addLeftBoundary(root, res);
            addLeafNodes(root, res);
            addRightBoundary(root, res);
        }
        return res;
    }
};

// Utility function to create a tree from input
Node* buildTree(vector<int> nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    queue<Node*> q;
    Node *root = new Node(nodes[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node *curr = q.front();
        q.pop();
        if (nodes[i] != -1) {
            curr->left = new Node(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new Node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Main function to test the code
int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9, -1, -1, -1, -1};
    Node *root = buildTree(input);
    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);
    for (int num : result) cout << num << " ";
    return 0;
}
