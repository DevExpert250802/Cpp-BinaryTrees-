// Print Root to Node Path in a Binary Tree

// Problem  :  We are given a binary tree T and a node V. We need to print a path from the root of the tree to the node.

class Solution {
public:
    bool Path(TreeNode* root, vector<int>& ans, int x) {
        if (root == NULL) {
            return false;
        }
        ans.push_back(root->val);
        if (root->val == x) {
            return true;
        }
        if (Path(root->left, ans, x) || Path(root->right, ans, x)) {
            return true;
        }
        ans.pop_back();
        return false;
    }

    vector<int> binaryTreePaths(TreeNode* root, int x) {
        vector<int> ans;
        helper(root, ans, x);
        return ans;
    }
};

/*
   1
  /  \
 2    3
/ \  / \
4  5 6  7

x = 5
Output : 1->2->5
  */
