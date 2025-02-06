#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;
    
    Node* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int left, int right) {
        if (left > right) return NULL;
        
        int rootValue = preorder[preorderIndex++];
        Node* root = new Node(rootValue);
        
        int inorderIndex = inorderMap[rootValue];
        
        root->left = buildTreeHelper(preorder, inorder, left, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, right);
        
        return root;
    }
    
public:
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        inorderMap.clear();
        preorderIndex = 0;
        
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }
    
    void postorderTraversal(Node* root, vector<int> &postorder) {
        if (root == NULL) return;
        
        postorderTraversal(root->left, postorder);
        postorderTraversal(root->right, postorder);
        postorder.push_back(root->data);
    }
};
