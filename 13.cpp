// Check if the Binary Tree is Balanced Binary Tree



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int height(TreeNode*root){
  if(root==NULL) return 0;
    int l= height(root->left);
    int r= height(root->right);
    return 1+max(r,l);
}
  bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;// An empty tree is balanced
        int lh = height(root->left);
        int rh= height(root->right);
        if(abs(lh-rh)>1)return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(left==false||right==false) return false;
        return true;
          }
};



// T.C.= O(N^2)
// S.C. =O(N)


// Approach for Checking if a Binary Tree is Balanced:

// This code uses a height calculation approach. 
// The height function computes the height of the tree while checking for balance.
// If a subtree is unbalanced, it returns -1. The isBalanced function returns true if the height is not -1, indicating a balanced tree.


class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0; 
        int lh = height(root->left);
        int rh = height(root->right);

        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) {
            return -1; // Unbalanced tree
        }

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};




// T.C.= O(N)
// S.C. =O(N)







