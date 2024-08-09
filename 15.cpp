// Symmetric Tree


class Solution {
public:
    bool f(TreeNode *root1,TreeNode *root2)  {
    if(root1==NULL&&root2==NULL) return true;
    if(root1==NULL||root2==NULL||root1->val!=root2->val)return false;
    return f(root1->left,root2->right) && f(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;//Tree is empty
        return f(root->left,root->right);
    }
};




Alter


class Solution {
public:
    bool f(TreeNode *root1,TreeNode *root2)  {
    if(!root1) return !root2;
    if(!root2) return !root1;
    return (root1->val==root2->val) && f(root1->left,root2->right) && f(root1->right,root2->left);


    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return f(root->left,root->right);
    }
};

/*
  output: Symmetrical

      1
    / | \
  2   |   2
/  \  |  /  \
3   4 |  4   3
 \    |      /
  5   |    5 

  */
