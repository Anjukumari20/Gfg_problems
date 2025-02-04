#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() : root(NULL) {}
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new TreeNode(5);
    tree.root->left = new TreeNode(8);
    tree.root->right = new TreeNode(6);
    tree.root->left->left = new TreeNode(3);
    tree.root->left->right = new TreeNode(7);
    tree.root->right->right = new TreeNode(9);

    cout << tree.diameterOfBinaryTree(tree.root) << endl;
    return 0;
}
