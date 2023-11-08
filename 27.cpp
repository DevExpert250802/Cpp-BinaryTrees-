// Right view

/*
Given a Binary Tree, return Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.
The task is to complete the function Right View(), which accepts root of the tree as argument.

*/




class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> res;
        recursion(root,0,res);
        return res;
    }
    void recursion(TreeNode* root,int level,vector<int>&res){
        if(!root) return;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
};



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
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
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level = node->val;
            }
                ans.push_back(level);
        }
        return ans;
    }
};



/*
Right view of following tree is 1 3 7 8.

         1
       /   \
     2       3
   /   \    /  \
  4     5  6    7
   \
     8   
*/


// Time Complexity: O(N)
// Space Complexity: O(H)       (H -> Height of the Tree)
