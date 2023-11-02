
//  Iterative  Inorder traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(!st.empty()||node!=NULL){
            if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node=node->right;
        }
    }
        return ans;
  }   
};


/*  output   :  4251637

      1
     / \
    2   3
   / \ / \
  4  5 6  7
  

*/

// Time complexity  : O(n)
// Space complexity : O(n)
