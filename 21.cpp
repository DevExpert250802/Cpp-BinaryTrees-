// Level Order II Traversal of a Binary Tree

// Given the root of a binary tree, return the bottom-up level order traversal of its 
// nodes' values. (i.e., from left to right, level by level from leaf to root).



class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int size =q.size();
            for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



/*  
output :[[4,5,6,7],[2,3],[1]]
      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/
