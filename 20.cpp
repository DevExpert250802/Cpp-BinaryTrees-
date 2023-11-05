/*
PathSum IV

If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.
For each integer in this list:

The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to,
1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.

Given a list of ascending three-digits integers representing a binary tree with the depth smaller than 5,
you need to return the sum of all paths from the root towards the leaves.

*/


#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> mp; // Map to represent the tree nodes
int ans = 0; // Variable to store the sum of paths

// Forward declaration of the dfs function
void dfs(int node, int t);

int pathSum(std::vector<int> &a, int n) {
    ans = 0;  // Initialize the variable to store the sum of paths
    mp.clear();  // Clear the map
    // Fill the map with node values where the key is the parent and the value is the node value
    for (int num : a) {
        mp[num / 10] = num % 10;
    }
    dfs(11, 0);  // Start DFS from the root node (11)
    return ans;  // Return the total sum of paths
}

void dfs(int node, int t) {
    if (!mp.count(node)) return;  // If the node doesn't exist, return
    t += mp[node];  // Add the node value to the current path sum
    int d = node / 10, p = node % 10;  // Calculate depth and position of the current node
    int l = (d + 1) * 10 + (p * 2) - 1;  // Calculate the left child node
    int r = l + 1;  // Calculate the right child node

    // If both left and right child nodes don't exist, it's a leaf node
    if (!mp.count(l) && !mp.count(r)) {
        ans += t;  // Add the current path sum to the total sum
        return;
    }

    // Recursive DFS for left and right child nodes
    dfs(l, t);
    dfs(r, t);
}
