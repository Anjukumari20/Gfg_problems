#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* current = root;
        int count = 0;
        
        while (!stk.empty() || current) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            
            current = stk.top();
            stk.pop();
            count++;
            if (count == k) {
                return current->val;
            }
            
            current = current->right;
        }
        
        return -1; // If k is larger than the number of nodes in BST
    }
};
