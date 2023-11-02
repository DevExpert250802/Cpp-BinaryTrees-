// Implementation of Postorder traversal using 1 Stack


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == NULL)
            return ans;

        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = st.top()->right;

                if(temp == NULL) {
                    temp = st.top();
                    st.pop();

                    ans.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();

                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
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
// Space complexity : O(n)
