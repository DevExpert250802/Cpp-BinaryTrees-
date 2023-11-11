// Given the root of a binary tree, return all root-to-leaf paths in any order. A leaf is a node with no children.

class Solution {
public:
void Path(TreeNode* root,vector<string>& answer,string curr){
        if(!root)return;
        if(root->left||root->right)  
        curr+=(to_string(root->val)+"->");

        else
        {
            curr+=(to_string(root->val));
            answer.push_back(curr);
        }
        Path(root->left,answer,curr);
        Path(root->right,answer,curr);
        
}
   vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string curr="";
        Path(root,answer,curr);
        return answer;
    }
};


/*
   1
  /  \
 2    3
/ \  / \
4  5 6  7
Input: root = [1,2,3,4,5,6,7]
Output: ["1->2->4","1->2->5","1->3->6","1->3->7"]
  */
