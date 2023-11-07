// Top view of a Binary Tree
//Problem Statement: Given below is a binary tree. The task is to print the top view of the binary tree.
//The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.


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
      
       // if one value is present for horizontal distance then do nothing
        if(mp.find(hd)==mp.end())
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
output : [4,2,1,3,7]
      1
     / \
    2   3
   / \ / \
  4  5 6  7
*/
