// Same Tree




class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>&v){
        if(root!=NULL){
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }else
            v.push_back(100000);
    }
    
    void preorder(TreeNode* root, vector<int>&v){
        if(root!=NULL){
            v.push_back(root->val);
            preorder(root->left, v);
            preorder(root->right, v);
        }else
            v.push_back(100000);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        vector<int> inp, inq, prep, preq;
        inorder(p, inp);
        inorder(q, inq);
        
        preorder(p, prep);
        preorder(q, preq);
        
        if(inp == inq  && prep == preq)
            return true;
        else
            return false;
    }
};



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Recursive Solution

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
           if (p == NULL || q == NULL)  return(p==q);
       return(p->val == q->val) &&isSameTree(p->left , q->left) && isSameTree(p->right,q->right);
        
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        return ( p->val == q->val  && 
                isSameTree( p->left, q->left ) && 
                 isSameTree( p->right, q->right )  );
    }
};

/*  
output: same

      1                  1  
     / \                / \
    2   3              2   3

  */
