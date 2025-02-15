#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to serialize the tree
vector<int> serialize(Node* root) {
    vector<int> result;
    if (!root) return result;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr) {
            result.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back(-1); // Using -1 as a marker for NULL
        }
    }
    return result;
}

// Function to deserialize the tree
Node* deSerialize(vector<int>& arr) {
    if (arr.empty()) return NULL;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Function for in-order traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    vector<int> serializedTree = serialize(root);
    Node* deserializedRoot = deSerialize(serializedTree);
    
    inorder(deserializedRoot); // Printing inorder traversal of the deserialized tree
    return 0;
}
