/*Given a binary tree, find its height.

The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. A leaf node is a node that does not have any children.*/
#include<iostream>
using namespace std;

class Solution {
  public:
    // Function to find the height of a binary tree.
   int height(struct Node* node){
        // code here 
            if (node == NULL) {
            return -1;
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return max(leftHeight, rightHeight)+1 ;

    }
    
};
