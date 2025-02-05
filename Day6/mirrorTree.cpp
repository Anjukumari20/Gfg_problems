
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == NULL) return;
        
        // Swap the left and right child
        swap(node->left, node->right);
        
        // Recur for left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

// Function to perform level order traversal (for testing purposes)
void printLevelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (temp) {
            cout << temp->data << " ";
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    cout << endl;
}

// Helper function to create a binary tree from level order input
Node* buildTree(vector<int> nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;
    
    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
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