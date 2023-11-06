
// Write a program for the Anti-Clockwise Boundary traversal of a binary tree.



void LeftNodes(TreeNode<int> *root, vector<int>&ans){
    if(!root || (!root->left && !root->right)) return;
    ans.push_back(root->data);
    if(root->left)
     LeftNodes(root->left, ans);
    else LeftNodes(root->right, ans);
}

void LeafNodes(TreeNode<int> *root, vector<int>&ans){
    if(!root) return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    
    LeafNodes(root->left, ans);
    LeafNodes(root->right, ans);
}

void RightNodes(TreeNode<int> *root, vector<int>&ans){
    if(!root || (!root->left && !root->right)) return;
    if(root->right) RightNodes(root->right, ans);
    else RightNodes(root->left, ans);
    
    // backtrack
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root){
	vector<int>ans;
    if(!root) return ans;
    
    ans.push_back(root->data);

    // Left Nodes
    LeftNodes(root->left, ans);
    
    // Leaf Nodes of left and right subtrees
    LeafNodes(root->left, ans);
    LeafNodes(root->right, ans);
    
    // Right Nodes
    RightNodes(root->right, ans);
    
    return ans;
}
