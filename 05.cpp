// Level Order Traversal of a Binary Tree


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i =0;i<size;i++){
                TreeNode* node= q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};


/*   

# include <bits/stdc++.h>

vector<int> levelOrder(TreeNode<int> * root){
   vector<int>ans;
   if(root==NULL) return ans;
   queue<TreeNode<int> *>q;
   q.push(root);

   while (!q.empty()) {
       TreeNode<int> * node = q.front();
       q.pop();
       
       if(node->left!=NULL) q.push(node->left);
       if(node->right!=NULL) q.push(node->right);
       ans.push_back(node->data);
   }
   return ans;
}

// link : https://www.codingninjas.com/studio/problems/zigzag-binary-tree-traversal_920532?leftPanelTabValue=PROBLEM

*/


/*  
output : 1 2 3 4 5 6 7
      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/


// Time complexity  : O(n)
// Space complexity : O(n)
