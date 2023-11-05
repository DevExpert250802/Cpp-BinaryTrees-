/*
113. Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path
equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/


class Solution {
public:
void Sum(TreeNode* root, int targetSum,int curSum,vector<int>&curPath,vector<vector<int>>&Paths){

    if(!root) return;
      
    curSum+=root->val;
    curPath.push_back(root->val);

    if(!root->left && !root->right&&targetSum==curSum){
        Paths.push_back(curPath);   
    }
     Sum(root->left,targetSum,curSum,curPath,Paths);
     Sum(root->right,targetSum,curSum,curPath,Paths);
    curPath.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>Paths;
       vector<int>curPath;
       int curSum=0;
        Sum(root,targetSum,curSum,curPath,Paths);
        return Paths;
    }
};
