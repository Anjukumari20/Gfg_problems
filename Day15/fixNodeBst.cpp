#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    Node *first, *middle, *last, *prev;
    
public:
    Solution() : first(nullptr), middle(nullptr), last(nullptr), prev(nullptr) {}
    
    void inorder_traversal(Node* root) {
        if (!root) return;
        
        inorder_traversal(root->left);
        
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        
        inorder_traversal(root->right);
    }
    
    void correctBST(Node* root) {
        inorder_traversal(root);
        
        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }
};

void print_inorder(Node* root) {
    if (!root) return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

Node* build_tree_from_list(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        int left_idx = 2 * i + 1;
        int right_idx = 2 * i + 2;
        if (left_idx < n) nodes[i]->left = nodes[left_idx];
        if (right_idx < n) nodes[i]->right = nodes[right_idx];
    }
    
    return nodes[0];
}

int main() {
    int arr[] = {10, 5, 8, 2, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = build_tree_from_list(arr, n);
    
    cout << "Before correction:\n";
    print_inorder(root);
    cout << endl;
    
    Solution solution;
    solution.correctBST(root);
    
    cout << "After correction:\n";
    print_inorder(root);
    cout << endl;
    
    return 0;
}
