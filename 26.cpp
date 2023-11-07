// Bottom view of a Binary Tree

//  Problem Statement: Given a binary tree, print the bottom view from left to right.
// A node is included in the bottom view if it can be seen when we look at the tree from the bottom.


#include<bits/stdc++.h>

vector<int> bottomView(TreeNode<int>* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode<int>* node = it.first;
        int hd = it.second;

        // Update the map with the value for the horizontal distance.
        mp[hd] = node->data;

        if (node->left) {
            q.push({node->left, hd - 1});
        }

        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Iterate through the map and add values to the result vector.
    for (auto i : mp) {
        ans.push_back(i.second);
    }

    return ans;
}

/*  
output : [4,2,6,3,7]
      1
     / \
    2   3
   / \ / \
  4  5 6  7
*/
