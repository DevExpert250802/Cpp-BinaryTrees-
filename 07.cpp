
//  Iterative  Inorder traversal

/* approach :  Create empty vector ans , stack st to help traverse the tree iteratively & a pointer node to the root of the tree.

Use a while loop that continues until the stack is not empty or the node is not null. This loop handles the traversal process.

Within the loop:

If node is not null, push node onto the stack then node = node->left This step goes as far left as possible in the tree.

If node is null, it means you've reached the leftmost node. Pop a node from the stack, add its value to the ans vector,
node = node->right  moves to the right subtree.

Finally, return the ans vector
*/

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
