//                                                          Diameter of a Binary Tree




// Approach 1 :



class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int x = height(root->left);
        int y = height(root->right);
        return max(x, y) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        int d1 = height(root->left) + height(root->right);
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);

        // The diameter can be either the maximum of left and right subtrees or
        // a path that goes through the current root node.
        return max({d1, d2, d3});
    }
};


/*
  
Time  Complexity: O(N*N) ( For every node, Height Function is called which takes O(N) time hence for every node it becomes N*N )  

Space Complexity: O(1)  ( Extra Space ) + O(H) ( Recursive Stack Space where “H” is the height of tree )

*/




// Approach 2 :




// Global declaration of variable

/*

class Solution {
public:
     int diameter = 0;            // Global
     int height(TreeNode* root){
        if (root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        diameter=max(diameter,lh+rh);
        return 1+ max(lh,rh);
     }
     int diameterOfBinaryTree(TreeNode* root) {
         int data =height(root);
         return diameter;
     
    }
};

*/

class Solution {
public:
     int height(TreeNode* root,int& diameter){
        if (root == NULL) return 0;
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+ max(lh,rh);
     }
     int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};



/* 
Time Complexity: O(N) 

Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree )  
*/






/*  
output : 4
      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/
