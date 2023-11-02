//      Maximum Depth in Binary Tree    |   Height of Binary Tree |

// Recursive way  

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
       int l= maxDepth(root->left);
       int r=maxDepth(root->right);
       return 1+ max(l,r);
    }
};


// Level Order

class Solution {
public:
    int maxDepth(TreeNode* root) {
      
        if (root == NULL)return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Increment depth after processing each level
            ++depth;
        }
      return depth;
    }
};



/*
output: 3

      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/

// Time complexity  : O(n)
// Space complexity : O(n)
