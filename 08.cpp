// Implementation of Postorder traversal using 2 Stack


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if (root==NULL) return ans;
       stack<TreeNode*>st1,st2;
        st1.push(root);

        while(!st1.empty()){
            TreeNode* node =st1.top();
            st1.pop();
            st2.push(node);
            
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};



/*
output: 4 5 2 6 7 3 1 

      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/

// Time complexity  : O(n)
// Space complexity : O(2n)
