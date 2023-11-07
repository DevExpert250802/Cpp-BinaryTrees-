// Vertical Order Traversal of a Binary Tree


/* Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
The root of the tree is at (0, 0).The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index
starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column.
In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree. */






class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        ///***    mapping --> Horizontal distance ->levelwise   ***///
        // mp<horizontal distance,map<level, multinodes>>mp
        map<int, map<int, multiset<int>>> mp;

        // queue contains root, horizontal distance, level;
        queue<pair<TreeNode*, pair<int, int>> > q;

        q.push({root, {0, 0}});
        while (!q.empty()) {
// In C++, the auto keyword is used for automatically determine the data type of a variable based on the initialization value. This feature is known as "type deduction" or"automatic type deduction."
            auto it = q.front();          
            q.pop();
            TreeNode* node = it.first;
            int hd = it.second.first;
            int lvl = it.second.second; 
            mp[hd][lvl].insert(node->val);
            if (node->left) q.push({node->left, {hd- 1 , lvl+1}});
            if (node->right) q.push({node->right, {hd+1, lvl+1}});
        }
        for (auto i : mp) // i is a row representing <int,map>   --->>   <hd ,  <level, multiset <int> > >
         {
            vector<int> node;
            for (auto j : i.second) //j is a row representing <level, multiset <int> >
            {
                for(auto k : j.second)// k is a row representing multiset <int>
                {
                  node.push_back(k);
                }
            }
            ans.push_back(node);
        }
        return ans;
    }
};


/*  
output : [[4],[2],[1,5,6],[3],[7]]
      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/
