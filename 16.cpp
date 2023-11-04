// Binary Tree Maximum Path Sum

class Solution {
    int Sum(TreeNode* root, int& res) {
        if (root == NULL) return 0;

        int lh = Sum(root->left, res);
        int rh = Sum(root->right, res);

        // Calculate the maximum path sum for the subtree rooted at the current node
        int case1 = max(root->val, max(lh, rh) + root->val);

        // Calculate the maximum path sum that goes from the current node to one of its children and continues to the other child node
        int case2 = lh + rh + root->val;

        // Update the global maximum path sum 'res' with the maximum of case1 and case2
        res = max(res, max(case1, case2));

        // Return the maximum path sum that goes from the current node to one of its children
        return case1;
    }

public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        Sum(root, result);
        return result;
    }
};


/*  

case 1: for subtree rooted at current node
       

      1                  1  
     / \                / \
    2  -3             -2  -3
                       
   
case 2 :


      1                    
     / \               
    2   3              
    
  */
