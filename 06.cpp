// Iterative Preorder Traversal

// approach : need a vector for returning answer , a stack for storing node and check if left and right child exists and then pop it (push : right then left as it follows LIFO )

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode* >st;
        st.push(root);
        while(!st.empty()){
           TreeNode* node= st.top();
           st.pop();
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
            ans.push_back(node->val);
        }
        return ans;
        
    }
};


/*  
output: 1 2 4 5 3 6 7 

      1
     / \
    2   3
   / \ / \
  4  5 6  7


*/
// Time complexity  : O(n)
// Space complexity : O(n)
