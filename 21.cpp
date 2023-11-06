// Binary Tree Zigzag Level Order Traversal

/* 
Approach :The code performs a zigzag level order traversal of a binary tree using a queue-based approach. 
 It initializes a queue with the root node, processes each level while alternating the direction,
 and stores the results in a vector of vectors. If the level number is even, it reverses the order of nodes in that level.
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)  return ans;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
             count++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->val);
            }
            if(count%2==0)
            reverse(level.begin(),level.end());
            ans.push_back(level);
            
        }

        return ans;
    }
};

/*  
output : [[1],[3,2],[4,5,6,7]]
      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/
