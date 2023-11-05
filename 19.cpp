/*
437. Path Sum III

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum
of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards 
(i.e., traveling only from parent nodes to child nodes).

 */

class Solution {
public:
    int ans = 0;

    void Path(TreeNode* root, int targetSum, long long int currentSum) {
        if (!root) return;

        currentSum += root->val;

        if (currentSum == targetSum) {
            ans++;
        }

        Path(root->left, targetSum, currentSum);
        Path(root->right, targetSum, currentSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        Path(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};
