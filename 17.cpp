// Path Sum
/* 
Given the root of a binary tree and an integer targetSum, return true if 
 the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 A leaf is a node with no children.
 */


class Solution {
public:
bool PathSum(TreeNode* root, int targetSum,int sum){
     if (!root ) return false;
      if(!root -> left && !root -> right ){
          int newSum = sum + root -> val;
            if(newSum == targetSum)
                return true;  
      }

     return PathSum(root -> left, targetSum, sum + root -> val) ||
           PathSum(root -> right, targetSum, sum + root -> val);
           
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return PathSum(root, targetSum, sum);
    }
};

// Time complexity of O(N)
// Space complexity of O(N)


