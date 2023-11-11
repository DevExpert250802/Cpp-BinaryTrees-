/*
 Univalued Binary Tree
 
A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
*/

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return univalued(root, root->val);
    }
    bool univalued(TreeNode* root, int val) {
        if (!root) return true;
        if(root->val != val) return false; 
        return univalued(root->left, val) && univalued(root->right, val);
    }
};
