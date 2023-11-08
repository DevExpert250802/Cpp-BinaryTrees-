// Left view

/*
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
The task is to complete the function leftView(), which accepts root of the tree as argument.

*/


// Recursion

class Solution {
public:
    vector<int> LeftSideView(TreeNode* root) {
        vector <int> res;
        recursion(root,0,res);
        return res;
    }
    void recursion(TreeNode* root,int level,vector<int>&res){
        if(!root) return;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->left,level+1,res);
        recursion(root->right,level+1,res);
    }
};




// Level-wise

class Solution {
public:
    vector<int> LeftSideView(TreeNode* root) {
        vector<int>ans;

        queue<TreeNode*>q;
        q.push(root);

        if(!root) return ans;

        while(!q.empty())
        {
            int size=q.size();
            int level;
            for(int i=0;i<size;i++)
            {
               TreeNode* node = q.front();
                q.pop();
                if(node->right!=NULL) q.push(node->right);
                if(node->left!=NULL) q.push(node->left);
                level = node->val;
            }
                ans.push_back(level);
        }
        return ans;
    }
};



/*
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   
*/

// Time Complexity: O(N)
// Space Complexity: O(H)       (H -> Height of the Tree)
