/*                Lowest Common Ancestor of a Binary Tree

  Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node
in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

class Solution {
public:
 bool Path(TreeNode* root, vector<TreeNode*>& arr, TreeNode* x) {
    if (!root) return false;

    arr.push_back(root);
    if (root == x) return true;
    if (Path(root->left, arr, x) || Path(root->right, arr, x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

 vector<TreeNode*> v1,v2;
    Path(root, v1, p);
    Path(root, v2, q);
    int i = 0;
     TreeNode* lca;

        while(i<v1.size() && i<v2.size()){
            if(v1[i] != v2[i]){
                break;
            }
            lca = v1[i];
            i++;
        }
        return lca;
    }
}; 


// space optimize

class Solution {
public:
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    else
        return root;
 }
};
