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

/*                  if (p == NULL || q == NULL)  return(p==q);
checks if the pointer p is NULL , checks if the pointer q is NULL.
The logical OR operator  is used to combine these conditions. If either p or q is NULL, the condition will evaluate to true.
This means that if at least one of the trees is empty, the condition inside the if-statement will be executed.
If the condition inside the if-statement is true (i.e., either p or q is NULL), it proceeds to the statement return (p == q);.
In the return (p == q); part, it checks if p and q are equal by comparing their pointers. If p and q are both NULL,
the condition p == q will be true because they are equal in this context. If both p and q are non-NULL, the condition p == q will be true In either case, it returns true.
If p is NULL and q is not NULL, or if q is NULL and p is not NULL, the condition p == q will be false because they are not equal. In this case, it returns false.
*/

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
